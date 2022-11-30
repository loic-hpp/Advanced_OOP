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

class MainGui :
    public QMainWindow
{
public:
    MainGui(QWidget* parent=nullptr);
private:
    void loadItems();
    void setUI();
    void setup();
    void setMenu();
    void setListItems();
    QCheckBox* addTaxableCheckBox();
    QHBoxLayout* setLeftWidgetButton();
    QVBoxLayout* setRightWidgetEdit();
    QVBoxLayout* displayPriceWidget();
    QCheckBox* taxableCheckBox;
    QListWidget* itemList;
    QLineEdit* description, *price;
    QLineEdit* totalBeforeTaxe, * totalTaxe, *totalToPay;
    QPushButton* add, *remove, *removeAll, *newCommand;
    std::string title = "Caisse enregistreuse";
};

