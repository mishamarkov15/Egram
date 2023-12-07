#include "../headers/chatbannerwidget.h"
#include <QDateTime>
#include <QFont>

chatbannerwidget::chatbannerwidget(QWidget *parent)
        : QWidget(parent),
        bannerLabel(new QLabel(this))
{
    setWindowTitle("Пример баннера пользователя");
    setFixedSize(400, 100);

    bannerLabel->setAlignment(Qt::AlignCenter);
    bannerLabel->setGeometry(0, 0, width(), height());


    bannerLabel->setStyleSheet("background-color: #333333; color: #fff; border: 2px solid #000000;");
    QFont font("Arial", 16, QFont::Bold);
    bannerLabel->setFont(font);


    QDateTime currentTime = QDateTime::currentDateTime();


    QString timeString = currentTime.toString("dd.MM.yyyy hh:mm:ss");


    QString bannerText = "<body>"
                         "<p style='margin-top: 10px;'>"
                         "<span style='font-size: 24px;'>Пользователь: Вовочка</span><br>"
                         "<span style='font-size: 18px;'>Статус: <span style='color: green;'>В сети</span></span><br>"
                         "<span style='font-size: 14px;'>Последний раз в сети: " + timeString + "</span>"
                                                                                                "</p>"
                                                                                                "</body>";

    bannerLabel->setText(bannerText);
}


