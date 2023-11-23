#include "../headers/MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        gridLayout(new QGridLayout()),
        centralWidget(new QWidget()),
        splitter(new QSplitter()) {
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
}

void MainWindow::initConnections() {

}

void MainWindow::initStyles() {
    setWindowTitle(APP_NAME);
}
