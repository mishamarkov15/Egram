#include "../headers/ClientTCP.h"

ClientTCP::ClientTCP(quint32 port, quint64 user_id, QObject *parent) :
        QObject(parent),
        port(port),
        user_id(user_id),
        receiver_id(0),
        socket(new QTcpSocket(this)) {
    initWidgets();
    initConnections();
}

void ClientTCP::initConnections() {
    connect(socket, &QTcpSocket::readyRead, this, &ClientTCP::readSocket);
}

void ClientTCP::initWidgets() {
    socket->connectToHost(QHostAddress::LocalHost, port);
    if (socket->isOpen()) {
        qDebug() << "[socket] successfully opened";
    } else {
        qWarning() << "[socket] does not opened";
    }
}

void ClientTCP::readSocket() {
    QByteArray jsonData;
    QDataStream socketStream(socket);
    socketStream.setVersion(QDataStream::Qt_6_2);

    for (;;) {
        socketStream.startTransaction();

        socketStream >> jsonData;
        if (socketStream.commitTransaction()) {
            QJsonParseError error;
            const QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonData, &error);
            if (error.error == QJsonParseError::NoError) {
                qDebug() << "Received from server";
                if (jsonDocument.isObject()) {
                    jsonReceived(jsonDocument.object());
                }
            } else {
                break;
            }
        }
    }
}

void ClientTCP::sendToServer(const QByteArray &data) {
    if (data.isEmpty()) {
        return;
    } else if (receiver_id == 0) {
        qCritical() << "Receiver id must be >0!";
        return;
    }

    QDataStream client_stream(socket);
    client_stream.setVersion(QDataStream::Qt_6_2);

    QJsonObject msg;
    msg["type"] = QString::number(static_cast<quint32>(MSG_TYPE::TEXT));
    msg["text"] = data.toStdString().c_str();
    msg["sender_id"] = QString::number(user_id);
    msg["receiver_id"] = QString::number(receiver_id);
    client_stream << QJsonDocument(msg).toJson(QJsonDocument::Compact);
}

void ClientTCP::setReceiverId(quint64 new_id) noexcept {
    receiver_id = new_id;
}

void ClientTCP::jsonReceived(const QJsonObject &doc) {
    const QJsonValue type_value = doc.value(QLatin1String("type"));
    if (type_value.isNull() || !type_value.isString()) {
        return;
    }

    if (type_value.toInteger() == static_cast<quint32>(MSG_TYPE::TEXT)) {
        const QJsonValue text_value = doc.value(QLatin1String("text"));

        if (text_value.isNull() || !text_value.isString()) {
            return;
        }
        qDebug() << "Receive from server: " << text_value << doc.value(QLatin1String("sender_id")) <<
                 doc.value(QLatin1String("receiver_id"));
        emit signalAddMessage(text_value.toString().toUtf8());
    }
}