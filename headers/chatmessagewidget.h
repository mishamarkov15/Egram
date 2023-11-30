#ifndef UNTITLED2_CHATMESSAGEWIDGET_H
#define UNTITLED2_CHATMESSAGEWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>


class ChatMessageWidget : public QWidget {
Q_OBJECT

public:
    ChatMessageWidget(const QString &sender, const QString &message, const QString &timestamp, bool isCurrentUser,
                      QWidget *parent = nullptr);

    QSize sizeHint() const override;

private:
    QLabel *senderLabel;
    QLabel *messageLabel;
    QLabel *timestampLabel;
};

#endif //UNTITLED2_CHATMESSAGEWIDGET_H
