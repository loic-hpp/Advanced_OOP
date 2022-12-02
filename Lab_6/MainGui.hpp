//	Description: Definition de la classe mainGUI.
//	Fichier: mainGUI.hpp
//	Auteurs: Rodrigo A. Merino Martel et Loïc Nguemegne Temena
//	Date	6 decembre 2022
//	Créé le 25 novembre 2022

#pragma once
#include <QApplication>
#include <QLabel>
#include <iostream>
#include <QMainWindow>
#include <QListWidget>
#include <QLineEdit>
#include <QRadioButton>
#include <QStatusBar>
#include <Qframe>
#include <QPushButton>
#include <QApplication>
#include <QMenuBar>
#include <QMainWindow>
#include <QComboBox>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QButtonGroup>
#include <QScrollArea>
#include <QScrollBar>
#include "QMessageBox"
#include "Modele.hpp"
#include <vector>
#include <list>
#include "Register.hpp"
using Modele::Article;
const int WINDOWS_SIZE_AJUSTMENT = 50;

class MainGUI :
    public QMainWindow
{
    Q_OBJECT

public:
    MainGui(QWidget* parent = nullptr);

public slots:
    void selectItem(QListWidgetItem* item);
    void cleanDisplay();
    void removeAllItem();
    void removeSelectedItem();
    void createItem();
    void reactivateAdd();
    void createNewCommand();
    void itemHasBeenAdded(std::shared_ptr<Article>& article);
    void itemHasBeenDeleted(std::shared_ptr<Article>& article);
    void invalidDataError();


private:
    void loadItems();
    void setUI();
    void setup();
    void setMenu();
    void setListItems();
    void actualiseRevoveAllButtonStatus();
    void updatePrices();
    QCheckBox* addTaxableCheckBox();
    QHBoxLayout* setLeftWidgetButton();
    QVBoxLayout* setRightLayoutEdit();
    QHBoxLayout* QlistHeader();
    QVBoxLayout* displayPriceLayout();
    QCheckBox* taxableCheckBox_;
    QListWidget* itemList_;
    QLineEdit* description_, *price_;
    QLineEdit* totalBeforeTaxe_, * totalTaxe_, *totalToPay_;
    QPushButton* add_, *remove_, *removeAll_, *newCommand_, *clear_;
    QMessageBox* errorBox;
    Modele::Register register_;
    std::string title = "Caisse enregistreuse";
    
};

