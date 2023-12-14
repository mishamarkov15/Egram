#include "../headers/ContactList.h"


ContactList::ContactList(QWidget *parent) :
        QWidget(parent),
        gridLayout(new QGridLayout()),
        listWidget(new QListWidget()),
        searchField(new QLineEdit()),
        FuncButton(new QPushButton("≡")){
    initWidgets();
    initLayout();
    initConnections();
    initStyles();
}

void ContactList::initWidgets() {
    setLayout(gridLayout);
}

void ContactList::setContacts(const QVector<QMap<QString, QString>> &contacts) {
    for (const auto &contact: contacts) {
        auto *list_item_contact = new ContactItem(contact, this);
        auto *item = new QListWidgetItem();
        item->setSizeHint(listWidget->sizeHint());
        listWidget->addItem(item);
        listWidget->setItemWidget(item, list_item_contact);
    }
}

void ContactList::initLayout() {
    gridLayout->addWidget(FuncButton, 0, 0, 1, 1);
    gridLayout->addWidget(searchField, 0, 1, 1, 1);
    gridLayout->addWidget(listWidget, 1, 1, 1, 1);
}

void ContactList::initConnections() {
    connect(listWidget, &QListWidget::itemClicked, this, &ContactList::emitContactClicked);

}

void ContactList::emitContactClicked() {
    auto contact = dynamic_cast<ContactItem *>(listWidget->itemWidget(listWidget->item(listWidget->currentRow())));
    if (contact) {
        emit contactClicked(contact->getId());
    }
}

void ContactList::initStyles() {
    setStyleSheet("background-color: black; padding: 8px 12px; border-radius: 16px; letter-spacing: 1px;");
    FuncButton->setStyleSheet("QPushButton{background-color: black; color: white; letter-spacing: 1px; Font-Size: 38px; font-weight: 300; text-align: center;}"
                              "QPushButton:hover{background-color: black; color: gray;}");
    FuncButton->setFixedSize(40,45);

    searchField->setStyleSheet("border: 1px solid #FFFFFF; padding: 8px 12px; border-radius: 16px; letter-spacing: 1px;");
    searchField->setPlaceholderText("Search a user...");
    listWidget->setStyleSheet("background-color: black; ");
}

