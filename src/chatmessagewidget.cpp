#include "chatmessagewidget.h"
#include <QtWidgets>

ChatMessageWidget::ChatMessageWidget(const QString& sender, const QString& message, const QString& timestamp, bool isCurrentUser, QWidget* parent)
        : QWidget(parent)
{
    senderLabel = new QLabel(sender);
    messageLabel = new QLabel(message);
    timestampLabel = new QLabel(timestamp);

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(senderLabel);
    layout->addWidget(messageLabel);
    layout->addWidget(timestampLabel);

    layout->setContentsMargins(0, 0, 0, 0);

    setLayout(layout);

    // Оформление с использованием функций setStyleSheet и цветовой палитры
    QPalette palette;
    palette.setColor(QPalette::WindowText, Qt::black);
    palette.setColor(QPalette::Text, Qt::black);
    palette.setColor(QPalette::WindowText, QColor("#888888"));

    setPalette(palette);
    setAutoFillBackground(true);
    setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    setContentsMargins(10, 10, 10, 10);
    setStyleSheet(
            "QWidget {"
            "   background-color: #e5e5ea;"
            "   border-radius: 10px;"
            "   border: 1px solid #888888;"
            "}"
            "QLabel {"
            "   font-size: 14px;"
            "   color: black;"
            "   qproperty-alignment: AlignTop;"
            "   padding: 0px;"
            "}"
            "QLabel.timestamp {"
            "   font-size: 12px;"
            "}"
    );

    // Выравнивание сообщений в зависимости от отправителя
    if (isCurrentUser) {
        layout->setAlignment(Qt::AlignRight);
    } else {
        layout->setAlignment(Qt::AlignLeft);
    }
}

// Задаю размер по умолчанию
QSize ChatMessageWidget::sizeHint() const
{
    return QSize(300, 100);
}