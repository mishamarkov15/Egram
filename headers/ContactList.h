#ifndef EGRAM_CONTACTLIST_H
#define EGRAM_CONTACTLIST_H

#include <QListWidget>
#include <QWidget>
#include <QLineEdit>
#include <QGridLayout>
#include "ContactItem.h"

class ContactList : public QWidget {
    Q_OBJECT;
public:
    explicit ContactList(const  QVector< QMap<QString, QString> >& contacts, QWidget* parent = nullptr);
private:

    void initWidgets( const QVector< QMap<QString, QString> >& contacts);
    void initLayout();
    void initConnections();
    void initStyles();
    QGridLayout* gridLayout;
    QListWidget* listWidget;
    QLineEdit* searchField;
};


#endif //EGRAM_CONTACTLIST_H
