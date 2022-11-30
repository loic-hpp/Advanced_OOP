#include "MainGui.hpp"

MainGui::MainGui(QWidget* parent)
{
	setup();
}

void MainGui::loadItems()
{
	itemList->clear();
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
	displayLeftLayout->addWidget(itemList);
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

	newCommand = new QPushButton(this);
	newCommand->setText("Nouvelle commande");

	commandForm->addLayout(displayLeftLayout);
	commandForm->addWidget(verticalFrameLine);
	commandForm->addLayout(displayRightLayout);

	mainLayout->addLayout(commandForm);
	mainLayout->addWidget(newCommand);
	

	QWidget* widget = new QWidget;
	widget->setLayout(mainLayout);
	setCentralWidget(widget);
	setWindowTitle(title.c_str());
	//Bloquer le changement de taille de la fenêtre
	// depuis cette page: https://stackoverflow.com/questions/16673074/how-can-i-fully-disable-resizing-a-window-including-the-resize-icon-when-the-mou
	widget->setFixedSize(widget->width(), widget->height());
	setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
}

void MainGui::setup()
{
	setMenu();
	setUI();
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
	itemList = new QListWidget(this);
	itemList->setSortingEnabled(true);
	
	
}

QCheckBox* MainGui::addTaxableCheckBox()
{
	taxableCheckBox = new QCheckBox("&Taxable", this);
	return taxableCheckBox;
}

QHBoxLayout* MainGui::setLeftWidgetButton()
{
	add = new QPushButton(this);
	add->setText("Ajouter");
	remove = new QPushButton(this);
	remove->setText("Retirer");
	removeAll = new QPushButton(this);
	removeAll->setText("Tout retirer");

	QHBoxLayout* lefButtonLayout = new QHBoxLayout;
	lefButtonLayout->addWidget(add);
	lefButtonLayout->addWidget(remove);
	lefButtonLayout->addWidget(removeAll);
	return lefButtonLayout;
}

QVBoxLayout* MainGui::setRightLayoutEdit()
{
	QLabel* descriptionlabel = new QLabel;
	descriptionlabel->setText("Description:\t");
	description = new QLineEdit;
	QHBoxLayout* descriptionLayout = new QHBoxLayout;
	descriptionLayout->addWidget(descriptionlabel);
	descriptionLayout->addWidget(description);

	QLabel* pricelabel = new QLabel;
	pricelabel->setText("Prix:\t\t");
	price = new QLineEdit;
	QHBoxLayout* priceLayout = new QHBoxLayout;
	priceLayout->addWidget(pricelabel);
	priceLayout->addWidget(price);

	QVBoxLayout* rightEditLayout = new QVBoxLayout;
	rightEditLayout->addLayout(descriptionLayout);
	rightEditLayout->addLayout(priceLayout);
	rightEditLayout->addWidget(addTaxableCheckBox(), 0, Qt::AlignRight);
	return rightEditLayout;
}

QHBoxLayout* MainGui::QlistHeader()
{
	QLabel* descriptionHeaderLabel = new QLabel;
	descriptionHeaderLabel->setText("DESCRIPTION\t");
	QLabel* priceHeaderLabel = new QLabel;
	priceHeaderLabel->setText("PRIX\t");
	QLabel* taxableHeaderLabel = new QLabel;
	taxableHeaderLabel->setText("TAXABLE\t");
	QHBoxLayout* headerLayout = new QHBoxLayout;
	headerLayout->addWidget(descriptionHeaderLabel, 0, Qt::AlignLeft);
	headerLayout->addWidget(priceHeaderLabel, 0, Qt::AlignCenter);
	headerLayout->addWidget(taxableHeaderLabel);
	return headerLayout;
}

QVBoxLayout* MainGui::displayPriceLayout()
{
	QLabel* totalBeforeTaxelabel = new QLabel;
	totalBeforeTaxelabel->setText("Total av taxes:\t");
	totalBeforeTaxe = new QLineEdit;
	totalBeforeTaxe->setReadOnly(true);
	totalBeforeTaxe->resize(10, totalBeforeTaxe->height());
	//totalBeforeTaxe-­>resize(totalBeforeTaxe->width()/2, totalBeforeTaxe->height());
	
	QHBoxLayout* totalBeforeTaxeLayout = new QHBoxLayout;
	totalBeforeTaxeLayout->addWidget(totalBeforeTaxelabel, 0, Qt::AlignRight);
	totalBeforeTaxeLayout->addWidget(totalBeforeTaxe, 0, Qt::AlignRight);

	QLabel* totalTaxelabel = new QLabel;
	totalTaxelabel->setText("Total Taxes:\t");
	totalTaxe = new QLineEdit;
	totalTaxe->setReadOnly(true);
	QHBoxLayout* totalTaxelLayout = new QHBoxLayout;
	totalTaxelLayout->addWidget(totalTaxelabel, 0, Qt::AlignRight);
	totalTaxelLayout->addWidget(totalTaxe, 0, Qt::AlignRight);

	QLabel* totalToPaylabel = new QLabel;
	totalToPaylabel->setText("Total a payer:\t");
	totalToPay = new QLineEdit;
	totalToPay->setReadOnly(true);
	QHBoxLayout* totalToPayLayout = new QHBoxLayout;
	totalToPayLayout->addWidget(totalToPaylabel, 0, Qt::AlignRight);
	totalToPayLayout->addWidget(totalToPay, 0, Qt::AlignRight);

	QVBoxLayout* priceLayout = new QVBoxLayout;
	priceLayout->addLayout(totalBeforeTaxeLayout);
	priceLayout->addLayout(totalTaxelLayout);
	priceLayout->addLayout(totalToPayLayout);
	return priceLayout;
}
