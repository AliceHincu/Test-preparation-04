//
// Created by Sakura on 5/23/2021.
//

#ifndef VEGETABLES_GUI_H
#define VEGETABLES_GUI_H

#include <qwidget.h>
#include <QListWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QApplication>
#include "Service.h"

class GUI: public QWidget {
    //Q_OBJECT
private:
    Service& service;
    QListWidget* ObjectsListWidget{};
    QListWidget* VeggieListWidget{};
    QLineEdit* veggieLineEdit{};
    QLineEdit* partsLineEdit{};
    QPushButton* veggieButton{};
public:
    GUI(Service& service, QWidget *parent = nullptr);
    ~GUI();
    void initGUI();
    void populateObjectList();
    void listItemChanged();
    void getPartOfObjects();
};


#endif //VEGETABLES_GUI_H
