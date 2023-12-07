#ifndef EGRAM_CONTACTLIST_H
#define EGRAM_CONTACTLIST_H

#include <QListWidget>
#include <QWidget>
#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>
#include "ContactItem.h"

class ContactList : public QWidget {
Q_OBJECT;
public:
    explicit ContactList(QWidget *parent = nullptr);

    void setContacts(const QVector<QMap<QString, QString> > &contacts);

signals:

    void contactClicked(quint64 id);

private slots:

    void emitContactClicked();

private:

    void initWidgets();

    void initLayout();

    void initConnections();

    void initStyles();

    QPushButton *FuncButton;
    QGridLayout *gridLayout;
    QListWidget *listWidget;
    QLineEdit *searchField;
};


#endif //EGRAM_CONTACTLIST_H
