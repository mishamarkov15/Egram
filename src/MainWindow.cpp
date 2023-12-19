#include "../headers/MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        gridLayout(new QGridLayout()),
        centralWidget(new QWidget()),
        splitter(new QSplitter()),
        contactList(new ContactList()),
        chat(new ChatWidget()),
        manager(new DatabaseManager("localhost", "egram", "mikhaiil", "higofi19", 5432)) {
    initWidgets();
    initLayout();
    initConnections();
    initStyles();
}

void MainWindow::initWidgets() {
    setCentralWidget(centralWidget);
    centralWidget->setLayout(gridLayout);
    auto contacts = manager->selectContactsForUser(current_user_id);
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
    chat = new ChatWidget(current_user_id, id);
    splitter->addWidget(chat);
}

void MainWindow::setstyle() {

}