#include "../headers/MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        gridLayout(new QGridLayout()),
        centralWidget(new QWidget()),
        splitter(new QSplitter()),
        contactList(new ContactList({
                                            {{"avatar", "/Users/mikhaiil/PycharmProjects/MarkusShop/media/courses/С++ для студентов/cpp_logo.png"}, {"name", "Steve Jobs 🐺"}, {"last_message", "How are u?"}, {"last_message_time", "4:16 PM"}},
                                            {{"avatar", "/Users/mikhaiil/PycharmProjects/MarkusShop/media/courses/С++ для студентов/cpp_logo.png"}, {"name", "Ilon Mask😛"}, {"last_message", "I want buy this chat)))"}, {"last_message_time", "2:16 PM"}},
                                            {{"avatar", "/Users/mikhaiil/PycharmProjects/MarkusShop/media/courses/С++ для студентов/cpp_logo.png"}, {"name", "Vladimir Vladimirovich 🇷🇺"}, {"last_message", "Хочу на рыбалку"}, {"last_message_time", "4:40 PM"}},
                                    })),
                                    chat(new ChatWidget()){
    initWidgets();
    initLayout();
    initConnections();
    initStyles();
}

void MainWindow::initWidgets() {
    setCentralWidget(centralWidget);
    centralWidget->setLayout(gridLayout);
}

void MainWindow::initLayout() {
    gridLayout->addWidget(splitter);

    splitter->addWidget(contactList);
    splitter->addWidget(chat);
}

void MainWindow::initConnections() {
    connect(contactList, &ContactList::contactClicked, this, &MainWindow::openChat);
}

void MainWindow::initStyles() {
    setWindowTitle(APP_NAME);
}

void MainWindow::openChat() {
    delete chat;
    chat = new ChatWidget(1, 2);
    splitter->addWidget(chat);
}
