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
#include <list>

class MainGUI :
    public QMainWindow
{
public:
    MainGUI(QWidget* parent=nullptr);
private:
    void loadItems();
    void setUI();
    void setup();
    void setMenu();
    void setListItems();
    QCheckBox* addTaxableCheckBox();
    QHBoxLayout* setLeftWidgetButton();
    QVBoxLayout* setRightLayoutEdit();
    QHBoxLayout* QlistHeader();
    QVBoxLayout* displayPriceLayout();
    QCheckBox* taxableCheckBox;
    QListWidget* itemList;
    QLineEdit* description, *price;
    QLineEdit* totalBeforeTaxe, * totalTaxe, *totalToPay;
    QPushButton* add, *remove, *removeAll, *newCommand;
    std::string title = "Caisse enregistreuse";
};

