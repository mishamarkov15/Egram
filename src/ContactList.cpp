#include "../headers/ContactList.h"

ContactList::ContactList(const QVector< QMap<QString, QString> >& contacts, QWidget *parent) :
        QWidget(parent),
        gridLayout(new QGridLayout()),
        listWidget(new QListWidget()),
        searchField(new QLineEdit()) {
    initWidgets(contacts);
    initLayout();
    initConnections();
    initStyles();
}

void ContactList::initWidgets( const QVector< QMap<QString, QString> >& contacts) {
    setLayout(gridLayout);

    for (const auto& contact : contacts) {
        auto* list_item_contact = new ContactItem(contact, this);
        auto* item = new QListWidgetItem();
        item->setSizeHint(listWidget->sizeHint());
        listWidget->addItem(item);
        listWidget->setItemWidget(item, list_item_contact);
    }
}

void ContactList::initLayout() {
    gridLayout->addWidget(searchField, 0, 0, 1, 1);
    gridLayout->addWidget(listWidget, 1, 0, 1, 1);
}

void ContactList::initConnections() {

}

void ContactList::initStyles() {

}

