#ifndef EGRAM_CLIENTTCP_H
#define EGRAM_CLIENTTCP_H

#include <QObject>
#include <QTcpSocket>
#include <QJsonDocument>
#include <QJsonObject>
#include <QString>

enum class MSG_TYPE {
    TEXT
};

class ClientTCP : public QObject {
Q_OBJECT;
public:
    explicit ClientTCP(quint32 port = 8000, quint64 user_id = 1, QObject *parent = nullptr);


    void setReceiverId(quint64 new_id) noexcept;
    signals:
    void signalAddMessage(const QByteArray& msg);
private slots:
    void readSocket();

public slots:

    void sendToServer(const QByteArray& data);

private:
    QTcpSocket *socket;
    quint32 port;
    quint64 user_id;
    quint64 receiver_id;

    void initConnections();

    void initWidgets();

    void jsonReceived(const QJsonObject &doc)
};


#endif //EGRAM_CLIENTTCP_H
