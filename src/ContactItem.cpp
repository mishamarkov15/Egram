#include "../headers/ContactItem.h"


ContactItem::ContactItem(const QMap<QString, QString> &contactItem, QWidget *parent) :
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

void ContactItem::initWidgets(const QMap<QString, QString> &contactItem) {
    setLayout(gridLayout);

    try {
        if (contactItem.find("avatar") != contactItem.end()) {
            avatarImage->setPixmap(QPixmap(contactItem["avatar"]).scaled(32, 32));
        } else {
            avatarImage->setText("A");
        }

        auto first_name = contactItem.find("first_name");
        auto last_name = contactItem.find("last_name");
        auto username = contactItem.find("username");
        if (first_name != contactItem.end()) {
            if (last_name != contactItem.end()) {
                nameLabel->setText(QList<QString>{first_name.value(), last_name.value()}.join(' '));
            } else {
                nameLabel->setText(first_name.value());
            }
        } else {
            nameLabel->setText(username.value());
        }
        lastMessage->setText("lorem ipsum...");
        lastMessageTime->setText("4:34 PM");
        user_id = contactItem["id"].toULongLong();
    } catch (std::out_of_range &error) {
        qCritical() << error.what() << '\n';
        QErrorMessage msg(this);
        msg.showMessage(error.what());
        return;
    }
}

void ContactItem::initLayout() {
    gridLayout->addWidget(avatarImage, 0, 0, 2, 1);
    gridLayout->addWidget(nameLabel, 0, 1, 1, 5);
    gridLayout->addWidget(lastMessageTime, 0, 5, 1, 1);
    gridLayout->addWidget(lastMessage, 1, 1, 1, 5);
}

void ContactItem::initConnections() {

}

void ContactItem::initStyles() {
    setFixedSize(350, 75);
    setMaximumHeight(75);
    setStyleSheet("background-color: black;");


    avatarImage->setMaximumHeight(30);
    avatarImage->setMaximumWidth(30);
    nameLabel->setMaximumHeight(20);
    lastMessageTime->setMaximumHeight(15);
    lastMessage->setMaximumHeight(20);
    gridLayout->setContentsMargins(10, 0, 10, 0);
    gridLayout->setSpacing(10);
    gridLayout->setVerticalSpacing(0);
    gridLayout->setRowStretch(0, 0);
    gridLayout->setRowStretch(1, 1);
}

quint64 ContactItem::getId() {
    return user_id;
}


