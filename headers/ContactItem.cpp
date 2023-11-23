#include "ContactItem.h"

ContactItem::ContactItem(const QMap<QString, QString>& contactItem, QWidget *parent) :
        QWidget(parent),
        gridLayout(new QGridLayout()),
        nameLabel(new QLabel()),
        lastMessage(new QLabel()),
        lastMessageTime(new QLabel()),
        avatarImage(new QLabel()) {
    initWidgets(contactItem);
    initLayout();
    initConnections();
    initStyles();
}

void ContactItem::initWidgets(const QMap<QString, QString>& contactItem) {
    setLayout(gridLayout);

    try {
        avatarImage->setPixmap(QPixmap(contactItem["avatar"]).scaled(32, 32));
        nameLabel->setText(contactItem["name"]);
        lastMessage->setText(contactItem["last_message"]);
        lastMessageTime->setText(contactItem["last_message_time"]);
    } catch (std::out_of_range& error) {
        qCritical() << error.what() << '\n';
        QErrorMessage msg(this);
        msg.showMessage(error.what());
        return;
    }
}

void ContactItem::initLayout() {
    gridLayout->addWidget(avatarImage, 0, 0, 3, 1);
    gridLayout->addWidget(nameLabel, 0, 1, 1, 5);
    gridLayout->addWidget(lastMessageTime, 0, 6, 1, 1);
    gridLayout->addWidget(lastMessage, 1, 1, 1, 6);
}

void ContactItem::initConnections() {

}

void ContactItem::initStyles() {

}
