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
#include "Article.hpp"
#include <vector>
#include <list>

class MainGui :
    public QMainWindow
{
    Q_OBJECT

public:
    MainGui(std::vector<std::unique_ptr<std::list<Article>>>* billHistory, QWidget* parent = nullptr);

//public slots:
//    void selectItem(QListWidgetItem*);
//    void cleanDisplay();
//    void removeAllItem();
//    void removeselectedItem();
//    void createItem();
//    void itemHasBeenAdded(Article*);
//    void itemHasBeenDeleted(Article*);

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
    std::vector<std::unique_ptr<std::list<Article>>>* billHistory_;
    std::unique_ptr<std::list<Article>> listItemCreated_;
    std::string title = "Caisse enregistreuse";
};

