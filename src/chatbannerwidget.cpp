#include "../headers/chatbannerwidget.h"
#include <QDateTime>
#include <QFont>

chatbannerwidget::chatbannerwidget(QWidget *parent)
        : QWidget(parent),
        bannerLabel(new QLabel(this)),
        gridLayout(new QGridLayout(this))

{

    bannerLabel->setAlignment(Qt::AlignCenter);


    bannerLabel->setStyleSheet("background-color: black; color: #fff; border:1px solid #FFFFFF; padding: 8px 12px; border-radius: 16px; letter-spacing: 1px;");
    QFont font("Arial", 12, QFont::Bold);
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


    gridLayout->addWidget(bannerLabel, 0, 0, 1, 0);
    gridLayout->setColumnStretch(0, 1);
    setLayout(gridLayout);
}


