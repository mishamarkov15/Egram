//
// Created by Михаил Марков on 23/11/2023.
//

#ifndef EGRAM_CONTACTITEM_H
#define EGRAM_CONTACTITEM_H

#include <QGridLayout>
#include <QPixmap>
#include <QLabel>
#include <QWidget>
#include <QErrorMessage>

class ContactItem : public QWidget {
Q_OBJECT;
public:
    explicit ContactItem(const QMap<QString, QString>& contactItem, QWidget*parent = nullptr);
private:
    void initWidgets(const QMap<QString, QString>& contactItem);
    void initLayout();
    void initConnections();
    void initStyles();

    QGridLayout* gridLayout;
    QLabel* nameLabel;
    QLabel* lastMessage;
    QLabel* lastMessageTime;
    QLabel* avatarImage;
};


#endif //EGRAM_CONTACTITEM_H
