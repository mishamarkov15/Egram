#ifndef EGRAM_MAINWINDOW_H
#define EGRAM_MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QWidget>
#include <QSplitter>
#include <QString>

const QString APP_NAME = "Egram";

class MainWindow : public QMainWindow {
Q_OBJECT;
public:
    explicit MainWindow(QWidget* parent = nullptr);
private:

    void initWidgets();
    void initLayout();
    void initConnections();
    void initStyles();

    QGridLayout* gridLayout;
    QWidget* centralWidget;
    QSplitter* splitter;
};


#endif //EGRAM_MAINWINDOW_H
