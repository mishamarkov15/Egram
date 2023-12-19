#ifndef EGRAM_MAINWINDOW_H
#define EGRAM_MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QWidget>
#include <QSplitter>
#include <QString>
#include "ContactList.h"
#include "ChatWidget.h"
#include "DatabaseManager.h"

const QString APP_NAME = "Egram";

class MainWindow : public QMainWindow {
Q_OBJECT;
public:
    explicit MainWindow(QWidget* parent = nullptr);
private slots:
    void openChat(quint64 id);
    void setstyle();
private:

    void initWidgets();
    void initLayout();
    void initConnections();
    void initStyles();

    QGridLayout* gridLayout;
    QWidget* centralWidget;
    QSplitter* splitter;
    ContactList* contactList;
    ChatWidget* chat;
    DatabaseManager* manager;
    quint64 current_user_id = 1;
};


#endif //EGRAM_MAINWINDOW_H
