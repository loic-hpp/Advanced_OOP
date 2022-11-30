#include "MainGui.hpp"

MainGui::MainGui(QWidget* parent)
{
	setup();
}

void MainGui::loadItems()
{
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
	displayLeftLayout->addWidget(itemList);
	displayLeftLayout->addWidget(horizontalFrameLine);
	displayLeftLayout->addLayout(setLeftWidgetButton());
	
	
	// Trait de séparation droite gauche
	QFrame* verticalFrameLine = new QFrame;
	verticalFrameLine->setFrameShape(QFrame::VLine);
	//displayLeftLayout->addLayout(lefButtonLayout);

	//Section de droite
	QVBoxLayout* displayRightLayout = new QVBoxLayout;
	displayRightLayout->addLayout(setRightWidgetEdit());
	displayRightLayout->addLayout(displayPriceWidget());

	//Mettre la droite et la gauche ensemble
	QHBoxLayout* mainLayout = new QHBoxLayout;
	mainLayout->addLayout(displayLeftLayout);
	mainLayout->addWidget(verticalFrameLine);
	mainLayout->addLayout(displayRightLayout);
	QWidget* widget = new QWidget;
	widget->setLayout(mainLayout);
	setCentralWidget(widget);
	setWindowTitle(title.c_str());
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

QHBoxLayout* MainGui::setLeftWidgetButton()
{
	QPushButton* add = new QPushButton(this);
	add->setText("Ajouter");
	QPushButton* remove = new QPushButton(this);
	remove->setText("Retirer");
	QPushButton* removeAll = new QPushButton(this);
	removeAll->setText("Tout retirer");

	QHBoxLayout* lefButtonLayout = new QHBoxLayout;
	lefButtonLayout->addWidget(add);
	lefButtonLayout->addWidget(remove);
	lefButtonLayout->addWidget(removeAll);
	return lefButtonLayout;
}

QVBoxLayout* MainGui::setRightWidgetEdit()
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
	return rightEditLayout;
}

QVBoxLayout* MainGui::displayPriceWidget()
{
	QLabel* totalBeforeTaxelabel = new QLabel;
	totalBeforeTaxelabel->setText("Total av taxes:\t");
	//description = new QLineEdit;
	QHBoxLayout* totalBeforeTaxeLayout = new QHBoxLayout;
	totalBeforeTaxeLayout->addWidget(totalBeforeTaxelabel);
	//totalBeforeTaxeLayout->addWidget(description);

	QLabel* totalTaxelabel = new QLabel;
	totalTaxelabel->setText("Total Taxes:\t");
	//description = new QLineEdit;
	QHBoxLayout* totalTaxelLayout = new QHBoxLayout;
	totalTaxelLayout->addWidget(totalTaxelabel);
	//totalTaxelLayout->addWidget(description);

	QLabel* TotalToPaylabel = new QLabel;
	TotalToPaylabel->setText("Total a payer:\t");
	//description = new QLineEdit;
	QHBoxLayout* TotalToPayLayout = new QHBoxLayout;
	TotalToPayLayout->addWidget(TotalToPaylabel);
	//descriptionLayout->addWidget(description);

	QVBoxLayout* priceLayout = new QVBoxLayout;
	priceLayout->addLayout(totalBeforeTaxeLayout);
	priceLayout->addLayout(totalTaxelLayout);
	priceLayout->addLayout(TotalToPayLayout);
	return priceLayout;
}
