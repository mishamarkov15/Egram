#ifndef EGRAM_CHATBANNERWIDGET_H
#define EGRAM_CHATBANNERWIDGET_H

#include <QWidget>
#include <QLabel>

class chatbannerwidget : public QWidget
{
Q_OBJECT

public:
    chatbannerwidget(QWidget *parent = nullptr);

private:
    QLabel *bannerLabel;
};


#endif //EGRAM_CHATBANNERWIDGET_H
