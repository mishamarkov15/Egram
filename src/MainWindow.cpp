#include "../headers/MainWindow.h"

MainWindow::MainWindow(quint32 port, quint64 user_id, QWidget *parent) :
        QMainWindow(parent),
        gridLayout(new QGridLayout()),
        centralWidget(new QWidget()),
        splitter(new QSplitter()),
        contactList(new ContactList()),
        chat(new ChatWidget(client)),
        current_user_id(user_id),
        client(new ClientTCP(port, user_id, this)) {
    initWidgets();
    initLayout();
    initConnections();
    initStyles();
}

void MainWindow::initWidgets() {
    setCentralWidget(centralWidget);
    centralWidget->setLayout(gridLayout);
    auto contacts = DatabaseManager::getInstance().selectContactsForUser(current_user_id);
    contactList->setContacts(contacts);
}

void MainWindow::initLayout() {
    gridLayout->addWidget(splitter);

    splitter->addWidget(contactList);
    splitter->addWidget(chat);
}

void MainWindow::initConnections() {
    connect(contactList, &ContactList::contactClicked, this, &MainWindow::openChat);
    connect(contactList, &ContactList::contactClicked, this, &MainWindow::setstyle);
}

void MainWindow::initStyles() {
    setWindowTitle(APP_NAME);
    setMinimumSize(1000, 600);
    setStyleSheet("background-color: black");
    contactList->setStyleSheet("background-color: black;");
    centralWidget->setStyleSheet("background-color: black;");
}

void MainWindow::openChat(quint64 id) {
    delete chat;
    chat = new ChatWidget(current_user_id, id, client, this);
    splitter->addWidget(chat);
    client->setReceiverId(id);
}

void MainWindow::setstyle() {

}