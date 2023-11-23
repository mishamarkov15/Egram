#ifndef EGRAM_CONTACTLIST_H
#define EGRAM_CONTACTLIST_H

#include <QListWidget>
#include <QWidget>
#include <QLineEdit>
#include <QGridLayout>

class ContactList : public QWidget {
    Q_OBJECT;
public:
    explicit ContactList(QWidget* parent = nullptr);
private:

    void initWidgets();
    void initLayout();
    void initConnections();
    void initStyles();
    QGridLayout* gridLayout;
    QListWidget* listWidget;
    QLineEdit* searchField;
};


#endif //EGRAM_CONTACTLIST_H
