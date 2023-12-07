#include "../headers/ChatWidget.h"

ChatWidget::ChatWidget(QWidget *parent) :
        QWidget(parent),
        banner(nullptr),
        gridLayout(new QGridLayout()),
        listWidget(nullptr),
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
        banner(new chatbannerwidget()),
        gridLayout(new QGridLayout()),
        listWidget(new QListWidget()),
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
    setLayout(gridLayout);


}

void ChatWidget::initLayout() {
    gridLayout->addWidget(banner, 0, 0, 1, 5);
    gridLayout->addWidget(listWidget, 1, 0, 5, 5);
    gridLayout->addWidget(lineEdit, 6, 0, 1, 4);
    gridLayout->addWidget(sendMessage, 6, 4, 1, 1);
}

void ChatWidget::initConnections() {

}

void ChatWidget::initStyles() {

}


