#ifndef EGRAM_CHATWIDGET_H
#define EGRAM_CHATWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QListWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include "chatbannerwidget.h"
#include "DatabaseManager.h"

class ChatWidget : public QWidget {
Q_OBJECT;
public:
    explicit ChatWidget(QWidget* parent = nullptr);
    explicit ChatWidget(quint64 sender_id, quint64 contact_id, QWidget* parent = nullptr);
public slots:
    void sendMessageSlot();
private:
    void initWidgetsEmpty();
    void initLayoutEmpty();
    void initConnectionsEmpty();
    void initStylesEmpty();


    void initWidgets();
    void initLayout();
    void initConnections();
    void initStyles();

    QLabel* emptyChatTitle;

    QGridLayout* gridLayout;
    QListWidget* listWidget;
    QLineEdit* lineEdit;
    QPushButton* sendMessage;
    chatbannerwidget* banner;
    quint64 sender_id;
    quint64 contact_id;
};


#endif //EGRAM_CHATWIDGET_H
