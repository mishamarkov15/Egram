#include "../headers/ChatWidget.h"

ChatWidget::ChatWidget(ClientTCP *client, QWidget *parent) :
        QWidget(parent),
        banner(nullptr),
        gridLayout(new QGridLayout()),
        listWidget(nullptr),
        lineEdit(nullptr),
        emptyChatTitle(new QLabel()),
        client(client),
        sendMessage(nullptr), sender_id(0), contact_id(0) {
    initWidgetsEmpty();
    initLayoutEmpty();
    initConnectionsEmpty();
    initStylesEmpty();
}

ChatWidget::ChatWidget(quint64 sender_id, quint64 contact_id, ClientTCP *client, QWidget *parent) :
        QWidget(parent),
        banner(new chatbannerwidget()),
        gridLayout(new QGridLayout()),
        listWidget(new QListWidget()),
        lineEdit(new QLineEdit()),
        sendMessage(new QPushButton()),
        client(client),
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

void ChatWidget::initStylesEmpty() {
    setStyleSheet("border: 1px solid #FFFFFF; padding: 8px 12px; border-radius: 16px; letter-spacing: 1px;");
    emptyChatTitle->setStyleSheet("color: white;");
}

void ChatWidget::initWidgets() {
    setLayout(gridLayout);

    sendMessage->setText("Send");

    lineEdit->setPlaceholderText("Type here message...");
    lineEdit->setStyleSheet("padding: 8px 12px; border-radius: 16px; letter-spacing: 1px;");
}

void ChatWidget::initLayout() {
    gridLayout->addWidget(banner, 0, 0, 1, 5);
    gridLayout->addWidget(listWidget, 1, 0, 5, 5);
    gridLayout->addWidget(lineEdit, 6, 0, 1, 4);
    gridLayout->addWidget(sendMessage, 6, 4, 1, 1);
}

void ChatWidget::initConnections() {
    connect(sendMessage, &QPushButton::clicked, client, [&]() {
        emit client->sendToServer(lineEdit->text().toUtf8());
        qDebug() << "Send to server some msg...";
    });
    connect(client, &ClientTCP::signalAddMessage, this, &ChatWidget::slotAddMessage);
    connect(sendMessage, &QPushButton::clicked, this, &ChatWidget::sendMessageSlot);
}

void ChatWidget::initStyles() {
    setStyleSheet("border: 1px solid #FFFFFF; padding: 8px 12px; border-radius: 16px; letter-spacing: 1px;");
    sendMessage->setStyleSheet(
            "QPushButton:hover {background: gray; } QPushButton {border: 1px solid #FFFFFF; padding: 8px 12px; border-radius: 16px; letter-spacing: 1px;}");
    sendMessage->setCursor(QCursor(Qt::PointingHandCursor));
}

void ChatWidget::sendMessageSlot() {
    auto textToSend = lineEdit->text();
    if (textToSend.isEmpty()) {
        return;
    }
    listWidget->addItem(textToSend);
    listWidget->scrollToBottom();

    DatabaseManager::getInstance().addMessage(sender_id, contact_id, textToSend);
    lineEdit->clear();

}

QString ChatWidget::getMessage() const {
    return lineEdit->text();
}

quint64 ChatWidget::getReceiverId() const {
    return contact_id;
}

void ChatWidget::slotAddMessage(const QByteArray& msg) {
    listWidget->addItem(msg.toStdString().c_str());
    listWidget->addItem("HAHAHAHHAHAH");
    listWidget->scrollToBottom();
}


