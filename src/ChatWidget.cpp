#include "../headers/ChatWidget.h"

ChatWidget::ChatWidget(QWidget *parent) :
        QWidget(parent),
        gridLayout(new QGridLayout()),
        listWidget(nullptr),
        contactName(nullptr),
        lastOnlineTime(nullptr),
        lineEdit(nullptr),
        emptyChatTitle(new QLabel()),
        sendMessage(nullptr), sender_id(0), contact_id(0) {
    initWidgetsEmpty();
    initLayoutEmpty();
    initConnectionsEmpty();
    initStylesEmpty();
}

ChatWidget::ChatWidget(quint64 sender_id, quint64 contact_id, QWidget *parent) :
        QWidget(parent),
        gridLayout(new QGridLayout()),
        listWidget(new QListWidget()),
        contactName(new QLabel()),
        lastOnlineTime(new QLabel()),
        lineEdit(new QLineEdit()),
        sendMessage(new QPushButton()),
        sender_id(sender_id),
        contact_id(contact_id) {
    initWidgets();
    initLayout();
    initConnections();
    initStyles();
}

void ChatWidget::initWidgetsEmpty() {
    emptyChatTitle->setText("Выберите, кому Вы хотели написать.");
    emptyChatTitle->setAlignment(Qt::AlignCenter);
    emptyChatTitle->setFont(QFont("Times New Roman"));
}

void ChatWidget::initLayoutEmpty() {
    setLayout(gridLayout);

    gridLayout->addWidget(emptyChatTitle);
}

void ChatWidget::initConnectionsEmpty() {}

void ChatWidget::initStylesEmpty() {}

void ChatWidget::initWidgets() {

}

void ChatWidget::initLayout() {
    setLayout(gridLayout);
}

void ChatWidget::initConnections() {

}

void ChatWidget::initStyles() {

}


