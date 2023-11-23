#include "../headers/ContactList.h"

ContactList::ContactList(QWidget *parent) :
        QWidget(parent),
        gridLayout(new QGridLayout()),
        listWidget(new QListWidget()),
        searchField(new QLineEdit()) {
    initWidgets();
    initLayout();
    initConnections();
    initStyles();
}

void ContactList::initWidgets() {
    setLayout(gridLayout);
}

void ContactList::initLayout() {
    gridLayout->addWidget(searchField, 0, 0, 1, 1);
    gridLayout->addWidget(listWidget, 1, 0, 1, 1);
}

void ContactList::initConnections() {

}

void ContactList::initStyles() {

}

