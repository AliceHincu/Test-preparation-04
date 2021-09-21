//
// Created by Sakura on 5/23/2021.
//

#include "GUI.h"

//
// Created by Sakura on 5/23/2021.
//

#include <iostream>
#include "GUI.h"

void GUI::initGUI() {
    this->service.readFile();

    auto* mainLayout = new QHBoxLayout{this};

    // list
    this->ObjectsListWidget = new QListWidget{};
    this->ObjectsListWidget->setMinimumWidth(300);
    this->ObjectsListWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    mainLayout->addWidget(this->ObjectsListWidget);
    QObject::connect(this->ObjectsListWidget, &QListWidget::itemSelectionChanged, this, [this]() {this->listItemChanged(); });

    //list2
    this->VeggieListWidget = new QListWidget{};
    this->VeggieListWidget->setMinimumWidth(300);
    this->VeggieListWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    mainLayout->addWidget(this->VeggieListWidget);

    // label + textedit + button + textedit
    auto* veggieWidget = new QWidget{};
    auto* veggieLayout = new QFormLayout{ veggieWidget };
    auto* veggieLabel = new QLabel{"&Vegetable: "};
    this->veggieLineEdit = new QLineEdit{};
    veggieLabel->setBuddy(this->veggieLineEdit);
    veggieLayout->addRow(veggieLabel, this->veggieLineEdit);

    this->veggieButton = new QPushButton("Search");
    veggieLayout->addRow(this->veggieButton);
    QObject::connect(this->veggieButton, &QPushButton::clicked, this, &GUI::getPartOfObjects);

    this->partsLineEdit = new QLineEdit{};
    veggieLayout->addRow(this->partsLineEdit);
    mainLayout->addWidget(veggieWidget);


    this->populateObjectList();
}

void GUI::getPartOfObjects() {
    std::string veggie = this->veggieLineEdit->text().toStdString();
    auto obj = this->service.getObjectBasedOnName(veggie);
    std::string res;
    for(const auto& it: obj.getParts()){
        res+=it;
        res+=" ";
    }
    this->partsLineEdit->setText(QString::fromStdString(res));

    //highlight
    for(int i=0; i<this->ObjectsListWidget->count();i++){
        auto item = this->ObjectsListWidget->item(i);
        if (item->text().toStdString() == obj.getFamily())
            item->setBackground(QColor("green"));
        else
            item->setBackground(QColor("white"));
    }
}

void GUI::populateObjectList() {
    if(this->ObjectsListWidget->count() > 0)
        this->ObjectsListWidget->clear();
    auto Objects = this->service.getUniqueObjects();

    for (auto &c: Objects){
        // fromStdString() -> Returns a copy of the str string
        QString itemInList = QString::fromStdString(c.getFamily());
        QFont font{"Verdana", 10};

        auto* item = new QListWidgetItem{itemInList};
        item->setFont(font);
        this->ObjectsListWidget->addItem(item);
    }

    // set the selection on the first item in the list if it's not empty
    if (!Objects.empty())
        this->ObjectsListWidget->setCurrentRow(0);
}

void GUI::listItemChanged()
{
    const QString& s = this->ObjectsListWidget->currentItem()->text();

    auto obj = this->service.getFamilyObjects(s.toStdString());

    if(this->VeggieListWidget->count() > 0)
        this->VeggieListWidget->clear();

    for (auto &c: obj){
        // fromStdString() -> Returns a copy of the str string
        std::string str = c.getName()+"  parts: ";
        for(const auto& it: c.getParts())
            str+=it;
        QString itemInList = QString::fromStdString(str);
        QFont font{"Verdana", 10};

        auto* item = new QListWidgetItem{itemInList};
        item->setFont(font);
        this->VeggieListWidget->addItem(item);
    }

    // set the selection on the first item in the list if it's not empty
    if (!obj.empty())
        this->VeggieListWidget->setCurrentRow(0);


}

GUI::GUI(Service &service, QWidget *parent): QWidget{parent}, service{service} {
    this->initGUI();
}


GUI::~GUI() = default;
