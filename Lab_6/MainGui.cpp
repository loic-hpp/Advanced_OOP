#include "MainGui.hpp"

MainGui::MainGui(QWidget* parent)
{
	setup();
}

void MainGui::loadItems()
{
	itemList_->clear();
	if (listItemCreated != nullptr) {
		if (!(listItemCreated->empty())){
		for (auto it = listItemCreated->begin(); it != listItemCreated->end(); ++it) {
			QListWidgetItem* item = new QListWidgetItem(
				QString::fromStdString((*it)->displayArticle()), itemList_);
			item->setData(Qt::UserRole, QVariant::fromValue<std::shared_ptr<Article>>(*it));
			item->setHidden(false);
		}
	}
	}

} 

void MainGui::setUI()
{
	// Section de gauche
	// Création du container gauche
	QVBoxLayout* displayLeftLayout = new QVBoxLayout;
	setListItems();
	//ligne de séparation
	QFrame* horizontalFrameLine = new QFrame;
	horizontalFrameLine->setFrameShape(QFrame::HLine);


	//Ajout des élément du Widget gauche
	displayLeftLayout->addLayout(QlistHeader());
	displayLeftLayout->addWidget(itemList_);
	displayLeftLayout->addWidget(horizontalFrameLine);
	displayLeftLayout->addLayout(setLeftWidgetButton());
	
	
	// Trait de séparation droite gauche
	QFrame* verticalFrameLine = new QFrame;
	verticalFrameLine->setFrameShape(QFrame::VLine);
	//displayLeftLayout->addLayout(lefButtonLayout);

	//Section de droite
	QVBoxLayout* displayRightLayout = new QVBoxLayout;
	QWidget* widgetRightLayoutEdit = new QWidget;
	widgetRightLayoutEdit->setLayout(setRightLayoutEdit());
	QWidget* widgetPriceLayout = new QWidget;
	widgetPriceLayout->setLayout(displayPriceLayout());

	displayRightLayout->addWidget(widgetRightLayoutEdit, 0, Qt::AlignTop);
	displayRightLayout->addWidget(widgetPriceLayout,0 , Qt::AlignBottom);

	//Mettre la droite et la gauche ensemble
	QVBoxLayout* mainLayout = new QVBoxLayout;
	QHBoxLayout* commandForm = new QHBoxLayout;

	newCommand_ = new QPushButton(this);
	newCommand_->setText("Nouvelle commande");
	connect(newCommand_, SIGNAL(clicked()), this, SLOT(createNewCommand()));

	commandForm->addLayout(displayLeftLayout);
	commandForm->addWidget(verticalFrameLine);
	commandForm->addLayout(displayRightLayout);

	mainLayout->addLayout(commandForm);
	mainLayout->addWidget(newCommand_);
	

	QWidget* widget = new QWidget;
	widget->setLayout(mainLayout);
	setCentralWidget(widget);
	setWindowTitle(title.c_str());
	//Bloquer le changement de taille de la fenêtre
	// depuis cette page: https://stackoverflow.com/questions/16673074/how-can-i-fully-disable-resizing-a-window-including-the-resize-icon-when-the-mou
	widget->setFixedSize(widget->width()+ WINDOWS_SIZE_AJUSTMENT, widget->height());
	setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
}

void MainGui::setup()
{
	setMenu();
	setUI();
	loadItems();

}

void MainGui::setMenu()
{
	QAction* exit = new QAction(tr("E&xit"), this);
	exit->setShortcuts(QKeySequence::Quit);
	connect(exit, SIGNAL(triggered()), this, SLOT(close()));
	QMenu* fileMenu = menuBar()->addMenu(tr("&Fichier"));
	fileMenu->addAction(exit);
}

void MainGui::setListItems()
{
	itemList_ = new QListWidget(this);
	itemList_->setSortingEnabled(true);
	connect(itemList_, SIGNAL(itemClicked(QListWidgetItem*)),
		this, SLOT(selectItem(QListWidgetItem*)));

	
}

QCheckBox* MainGui::addTaxableCheckBox()
{
	taxableCheckBox_ = new QCheckBox("&Taxable", this);
	return taxableCheckBox_;
}

QHBoxLayout* MainGui::setLeftWidgetButton()
{
	add_ = new QPushButton(this);
	add_->setText("Ajouter");
	connect(add_, SIGNAL(clicked()), this, SLOT(createItem()));
	remove_ = new QPushButton(this);
	remove_->setText("Retirer");
	remove_->setDisabled(true);
	connect(remove_, SIGNAL(clicked()), this, SLOT(removeSelectedItem()));
	removeAll_ = new QPushButton(this);
	removeAll_->setText("Tout retirer");
	actualiseRevoveAllButtonStatus();
	connect(removeAll_, SIGNAL(clicked()), this, SLOT(removeAllItem()));

	QHBoxLayout* lefButtonLayout = new QHBoxLayout;
	lefButtonLayout->addWidget(add_);
	lefButtonLayout->addWidget(remove_);
	lefButtonLayout->addWidget(removeAll_);
	return lefButtonLayout;
}

QVBoxLayout* MainGui::setRightLayoutEdit()
{
	QLabel* descriptionlabel = new QLabel;
	descriptionlabel->setText("Description:\t");
	description_ = new QLineEdit;
	QHBoxLayout* descriptionLayout = new QHBoxLayout;
	descriptionLayout->addWidget(descriptionlabel);
	descriptionLayout->addWidget(description_);

	QLabel* pricelabel = new QLabel;
	pricelabel->setText("Prix:\t\t");
	price_ = new QLineEdit;
	QHBoxLayout* priceLayout = new QHBoxLayout;
	priceLayout->addWidget(pricelabel);
	priceLayout->addWidget(price_);

	QFrame* horizontalFrameLine = new QFrame;
	horizontalFrameLine->setFrameShape(QFrame::HLine);

	clear_ = new QPushButton(this);
	clear_->setText("Efaccer");
	connect(clear_, SIGNAL(clicked()), this, SLOT(reactivateAdd()));

	QVBoxLayout* rightEditLayout = new QVBoxLayout;
	rightEditLayout->addLayout(descriptionLayout);
	rightEditLayout->addLayout(priceLayout);
	rightEditLayout->addWidget(addTaxableCheckBox(), 0, Qt::AlignRight);
	rightEditLayout->addWidget(horizontalFrameLine);
	rightEditLayout->addWidget(clear_);
	return rightEditLayout;
}

QHBoxLayout* MainGui::QlistHeader()
{
	QLabel* descriptionHeaderLabel = new QLabel;
	descriptionHeaderLabel->setText("DESCRIPTION\t");
	QLabel* priceHeaderLabel = new QLabel;
	priceHeaderLabel->setText("PRIX\t");
	QLabel* taxableHeaderLabel = new QLabel;
	taxableHeaderLabel->setText("TAXABLE");
	QHBoxLayout* headerLayout = new QHBoxLayout;
	headerLayout->addWidget(descriptionHeaderLabel, 0, Qt::AlignLeft);
	headerLayout->addWidget(priceHeaderLabel, 0, Qt::AlignCenter);
	headerLayout->addWidget(taxableHeaderLabel, 0, Qt::AlignRight);
	return headerLayout;
}

QVBoxLayout* MainGui::displayPriceLayout()
{
	QLabel* totalBeforeTaxelabel = new QLabel;
	totalBeforeTaxelabel->setText("Total av taxes:\t");
	totalBeforeTaxe_ = new QLineEdit;
	totalBeforeTaxe_->setReadOnly(true);
	totalBeforeTaxe_->resize(10, totalBeforeTaxe_->height());

	
	QHBoxLayout* totalBeforeTaxeLayout = new QHBoxLayout;
	totalBeforeTaxeLayout->addWidget(totalBeforeTaxelabel, 0, Qt::AlignRight);
	totalBeforeTaxeLayout->addWidget(totalBeforeTaxe_, 0, Qt::AlignRight);

	QLabel* totalTaxelabel = new QLabel;
	totalTaxelabel->setText("Total Taxes:\t");
	totalTaxe_ = new QLineEdit;
	totalTaxe_->setReadOnly(true);
	QHBoxLayout* totalTaxelLayout = new QHBoxLayout;
	totalTaxelLayout->addWidget(totalTaxelabel, 0, Qt::AlignRight);
	totalTaxelLayout->addWidget(totalTaxe_, 0, Qt::AlignRight);

	QLabel* totalToPaylabel = new QLabel;
	totalToPaylabel->setText("Total a payer:\t");
	totalToPay_ = new QLineEdit;
	totalToPay_->setReadOnly(true);
	QHBoxLayout* totalToPayLayout = new QHBoxLayout;
	totalToPayLayout->addWidget(totalToPaylabel, 0, Qt::AlignRight);
	totalToPayLayout->addWidget(totalToPay_, 0, Qt::AlignRight);

	QVBoxLayout* priceLayout = new QVBoxLayout;
	priceLayout->addLayout(totalBeforeTaxeLayout);
	priceLayout->addLayout(totalTaxelLayout);
	priceLayout->addLayout(totalToPayLayout);
	return priceLayout;
}

void MainGui::selectItem(QListWidgetItem* item) {
	std::shared_ptr<Article> article = item->data(Qt::UserRole).value<std::shared_ptr<Article>>();
	description_->setDisabled(true);
	description_->setText(QString::fromStdString(article->description));
	price_->setDisabled(true);
	price_->setText(QString::fromStdString(article->displayPrice()));
	taxableCheckBox_->setDisabled(true);
	taxableCheckBox_->setChecked(article->taxable);
	add_->setDisabled(true);
	remove_->setDisabled(false);
}
void MainGui::removeSelectedItem() {
	std::shared_ptr<Article> article;
	for (QListWidgetItem* item : itemList_->selectedItems()) {
		article = item->data(Qt::UserRole).value<std::shared_ptr<Article>>();
		listItemCreated->remove(article);
	}
	reactivateAdd();
}

void MainGui::removeAllItem() {
	if (listItemCreated != nullptr) {
		if (!(listItemCreated->empty())) {
			int size = (int)listItemCreated->size();
			for (int i = 0; i < size; i++)
				listItemCreated->pop_back();
		}
	}
	reactivateAdd();
}

void MainGui::cleanDisplay() {
	actualiseRevoveAllButtonStatus();
	remove_->setDisabled(true);
	description_->setDisabled(false);
	description_->setText("");
	price_->setDisabled(false);
	price_->setText("");
	taxableCheckBox_->setDisabled(false);
	taxableCheckBox_->setChecked(false);
	loadItems();
	updatePrices();
}

void MainGui::createItem() {
	if (listItemCreated == nullptr)
		listItemCreated = std::make_shared<std::list<std::shared_ptr<Article>>>();
	Article article = { description_->text().toStdString(), price_->text().toDouble(), taxableCheckBox_->isChecked()};
	listItemCreated->push_back(std::make_shared<Article>(article));
	cleanDisplay();
}

void MainGui::createNewCommand() {
	billHistory.push_back(std::move(listItemCreated));
	listItemCreated = std::make_shared<std::list<std::shared_ptr<Article>>>();
	reactivateAdd();
}

void MainGui::actualiseRevoveAllButtonStatus() {
	if (listItemCreated == nullptr)
		removeAll_->setDisabled(true);
	else
	{
		if (listItemCreated->empty())
			removeAll_->setDisabled(true);
		else
			removeAll_->setDisabled(false);
	}
}

void MainGui::reactivateAdd() {
	cleanDisplay();
	add_->setDisabled(false);
}

void MainGui::updatePrices() {
	totalBeforeTaxes = Modele::curentTotal();
	totalBeforeTaxe_->setText(QString::fromStdString(Modele::doubleToStr(totalBeforeTaxes)));
}
