#ifndef EGRAM_CHAT_H
#define EGRAM_CHAT_H

#include <QWidget>
#include <QGridLayout>
#include <QListWidget>
#include <QLineEdit>
#include <QPushButton>

class Chat : public QWidget {
Q_OBJECT;
public:
    explicit Chat(QWidget* parent= nullptr);
private:

    void initWidgets();
    void initLayout();
    void initConnections();
    void initStyles();

    QGridLayout* gridLayout;
    QListWidget* messageList;
    QLineEdit* messageEdit;
    QPushButton* sendButton;
};


#endif //EGRAM_CHAT_H
