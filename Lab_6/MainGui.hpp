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
#include<QMenuBar>
#include <QMainWindow>
#include<QComboBox>
#include<QVBoxLayout>
#include <QButtonGroup>
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
    QHBoxLayout* setLeftWidgetButton();
    QVBoxLayout* setRightWidgetEdit();
    QVBoxLayout* displayPriceWidget();
    QListWidget* itemList;
    QLineEdit* description, *price;
    QLineEdit* totalBeforeTaxe, * totalTaxe, *TotalToPay;
    QPushButton* add, *remove, *removeAll;
    std::string title = "Caisse enregistreuse";
};

