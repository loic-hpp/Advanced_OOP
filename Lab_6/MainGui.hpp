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
const int WINDOWS_SIZE_AJUSTMENT = 50;

class MainGui :
    public QMainWindow
{
    Q_OBJECT

public:
    MainGui(std::vector<std::unique_ptr<std::list<std::shared_ptr<Article>>>>* billHistory, QWidget* parent = nullptr);

public slots:
    void selectItem(QListWidgetItem* item);
    void cleanDisplay();
    void removeAllItem();
    void removeSelectedItem();
    void createItem();
    void reactivateAdd();
    void createNewCommand();
//    void itemHasBeenAdded(Article*);
//    void itemHasBeenDeleted(Article*);

signals:
    //void itemClicked(QListWidgetItem* item);

private:
    void loadItems();
    void setUI();
    void setup();
    void setMenu();
    void setListItems();
    void actualiseRevoveAllButtonStatus();
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
    std::vector<std::unique_ptr<std::list<std::shared_ptr<Article>>>>* billHistory_;
    std::unique_ptr<std::list<std::shared_ptr<Article>>> listItemCreated_;
    std::string title = "Caisse enregistreuse";
};

