#include <QApplication>
#include "headers/MainWindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w(QString(argv[2]).toULongLong(), QString(argv[1]).toULongLong());
    w.show();
    return QApplication::exec();
}
