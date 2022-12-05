//	Description: Implementation de la classe mainGUI.
//	Fichier: MainGUI.cpp
//	Auteurs: Rodrigo A. Merino Martel et Loïc Nguemegne Temena
//	Date	6 decembre 2022
//	Créé le 25 novembre 2022

#include "MainGui.hpp"

MainGUI::MainGUI(QWidget* parent)
{
	setup();
}

void MainGUI::loadItems()
{
	itemList_->clear();
	if (!register_.empty()) {
		for (auto it = register_.getFirstItemIterator(); it != register_.getLastItemIterator(); ++it) {
			QListWidgetItem* item = new QListWidgetItem(
				QString::fromStdString((*it)->displayArticle()), itemList_);
			item->setData(Qt::UserRole, QVariant::fromValue<std::shared_ptr<Article>>(*it));
			item->setHidden(false);
		}
	}
}

void MainGUI::itemHasBeenAdded(std::shared_ptr<Article>& article) {
	QListWidgetItem* item = new QListWidgetItem(
		QString::fromStdString(article->displayArticle()), itemList_);
	item->setData(Qt::UserRole, QVariant::fromValue<std::shared_ptr<Article>>(article));
	item->setHidden(false);
	cleanDisplay();
}

void MainGUI::itemHasBeenDeleted(std::shared_ptr<Article>& article) {
	reactivateAdd();
}

void MainGUI::setUI()
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
	displayRightLayout->addWidget(widgetPriceLayout, 0, Qt::AlignBottom);

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
	widget->setFixedSize(widget->width() + WINDOWS_SIZE_AJUSTMENT, widget->height());
	setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);

}

void MainGUI::setup()
{
	setMenu();
	setUI();
	loadItems();

}

void MainGUI::setMenu()
{
	QAction* exit = new QAction(tr("E&xit"), this);
	exit->setShortcuts(QKeySequence::Quit);
	connect(exit, SIGNAL(triggered()), this, SLOT(close()));
	QMenu* fileMenu = menuBar()->addMenu(tr("&Fichier"));
	fileMenu->addAction(exit);
}

void MainGUI::setListItems()
{
	itemList_ = new QListWidget(this);
	itemList_->setSortingEnabled(true);
	connect(itemList_, SIGNAL(itemClicked(QListWidgetItem*)),
		this, SLOT(selectItem(QListWidgetItem*)));


}

QCheckBox* MainGUI::addTaxableCheckBox()
{
	taxableCheckBox_ = new QCheckBox("&Taxable", this);
	return taxableCheckBox_;
}

QHBoxLayout* MainGUI::setLeftWidgetButton()
{
	add_ = new QPushButton(this);
	add_->setText("Ajouter");
	connect(add_, SIGNAL(clicked()), this, SLOT(createItem()));
	connect(&register_, SIGNAL(itemAdded(std::shared_ptr<Article>&)),
		this, SLOT(itemHasBeenAdded(std::shared_ptr<Article>&)));
	remove_ = new QPushButton(this);
	remove_->setText("Retirer");
	remove_->setDisabled(true);
	connect(remove_, SIGNAL(clicked()), this, SLOT(removeSelectedItem()));
	connect(&register_, SIGNAL(itemDeleted(std::shared_ptr<Article>&)),
		this, SLOT(itemHasBeenDeleted(std::shared_ptr<Article>&)));
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

QVBoxLayout* MainGUI::setRightLayoutEdit()
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

QHBoxLayout* MainGUI::QlistHeader()
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

QVBoxLayout* MainGUI::displayPriceLayout()
{
	QLabel* totalBeforeTaxelabel = new QLabel;
	totalBeforeTaxelabel->setText("Total av taxes:\t");
	totalBeforeTaxe_ = new QLineEdit;
	totalBeforeTaxe_->setReadOnly(true);
	totalBeforeTaxe_->resize(10, totalBeforeTaxe_->height());
	//totalBeforeTaxe-­>resize(totalBeforeTaxe->width()/2, totalBeforeTaxe->height());

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

void MainGUI::selectItem(QListWidgetItem* item) {
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

void MainGUI::removeSelectedItem() {
	std::shared_ptr<Article> article;
	for (QListWidgetItem* item : itemList_->selectedItems()) {
		article = item->data(Qt::UserRole).value<std::shared_ptr<Article>>();
		register_.removeItem(article);
	}
}

void MainGUI::removeAllItem() {
	register_.removeAllItems();
	reactivateAdd();
}

void MainGUI::cleanDisplay() {
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

void MainGUI::createItem() {
	Article article = { description_->text().toStdString(), price_->text().toDouble(), taxableCheckBox_->isChecked() };
	auto articlePtr = std::make_shared<Article>(article);
	try { register_.addItem(articlePtr); }
	catch (std::invalid_argument& error) {
		if (article.description.size() > 15 || article.description.size() == 0)
		{
			invalidDescriptionError();
		}
		else if (price_->text() == "")
		{
			invalidPriceError();
		}
	}
}

void MainGUI::createNewCommand() {
	register_.createNewCommand();
	reactivateAdd();
}

void MainGUI::actualiseRevoveAllButtonStatus() {
	if (register_.empty())
		removeAll_->setDisabled(true);
	else
		removeAll_->setDisabled(false);
}

void MainGUI::reactivateAdd() {
	cleanDisplay();
	add_->setDisabled(false);
}

void MainGUI::updatePrices() {
	register_.curentTotal();

	totalBeforeTaxe_->setText(QString::fromStdString(register_.doubleToStr(register_.getTotalBeforeTaxes())));
	totalTaxe_->setText(QString::fromStdString(register_.doubleToStr(register_.getTotalTaxes())));
	totalToPay_->setText(QString::fromStdString(register_.doubleToStr(register_.getTotalToPay())));
}

void MainGUI::invalidDescriptionError() {
	errorBox = new QMessageBox(this);
	errorBox->setText("Les champs DESCRIPTION requiert un text de moins de 15 caractères et non vide!");
	errorBox->setWindowTitle("Erreur");
	errorBox->show();
}

void MainGUI::invalidPriceError() {
	errorBox = new QMessageBox(this);
	errorBox->setText("Les champs PRIX est requis!");
	errorBox->setWindowTitle("Erreur");
	errorBox->show();
}