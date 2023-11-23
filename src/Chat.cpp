#include "../headers/Chat.h"

Chat::Chat(QWidget *parent) :
        QWidget(parent),
        gridLayout(new QGridLayout()),
        messageList(new QListWidget()),
        messageEdit(new QLineEdit()),
        sendButton(new QPushButton()) {
    initWidgets();
    initLayout();
    initConnections();
    initStyles();
}

void Chat::initWidgets() {
    setLayout(gridLayout);
}

void Chat::initLayout() {

}

void Chat::initConnections() {

}

void Chat::initStyles() {

}
