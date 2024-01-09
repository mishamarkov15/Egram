#include "../headers/DatabaseManager.h"

DatabaseManager::DatabaseManager(const QString &host, const QString &database_name, const QString &username,
                                 const QString &password, qint32 port) : db(QSqlDatabase::addDatabase("QPSQL")) {
    db.setHostName(host);
    db.setDatabaseName(database_name);
    db.setUserName(username);
    db.setPassword(password);
    db.setPort(port);
    if (db.open()) {
        qDebug() << "DatabaseManager: successfully connected to database";
    } else {
        throw std::runtime_error(db.lastError().text().toStdString());
    }
}

DatabaseManager::DatabaseManager(const QMap<QString, QString> &params) : db(QSqlDatabase::addDatabase("QPSQL")) {
    try {
        db.setHostName(params["host"]);
        db.setDatabaseName(params["database_name"]);
        db.setUserName(params["username"]);
        db.setPassword(params["password"]);
        db.setPort(params["port"].toInt());
    } catch (std::exception &err) {
        qCritical() << "DatabaseManager: " << err.what();
    }
    if (db.open()) {
        qDebug() << "DatabaseManager: successfully connected to database";
    } else {
        throw std::runtime_error(db.lastError().text().toStdString());
    }
}

DatabaseManager::~DatabaseManager() {
    if (db.isOpen()) {
        db.close();
    }
}

QList<QMap<QString, QString>> DatabaseManager::selectContactsForUser(quint64 user_id) const {
    QList<QMap<QString, QString>> res;
    QSqlQuery query;
    query.prepare(
            "SELECT id, username, first_name, last_name FROM \"user\" WHERE id in (SELECT contact_id FROM contacts WHERE user_id=:id);");
    query.bindValue(":id", user_id);
    query.exec();
    while (query.next()) {
        QMap<QString, QString> contact = {
                {"avatar",     "none"},
                {"id",         query.value("id").toString()},
                {"username",   query.value("username").toString()},
                {"first_name", query.value("first_name").toString()},
                {"last_name",  query.value("last_name").toString()}
        };
        res.emplace_back(contact);
    }
    return res;
}

DatabaseManager &DatabaseManager::getInstance() {
    static DatabaseManager databaseManager("localhost", "egram", "mikhaiil", "higofi19", 5432);
    return databaseManager;
}

void DatabaseManager::addMessage(quint64 sender_id, quint64 contact_id, const QString &message) const {
//    QSqlDatabase::database().transaction();
    QSqlQuery query;
    query.prepare("INSERT INTO messages (sender_id, receiver_id, content) VALUES (:sender, :receiver, :content)");
    query.bindValue(":sender", sender_id);
    query.bindValue(":receiver", contact_id);
    query.bindValue(":content", message);
    if (query.exec()) {
        qDebug() << "DatabaseManager: message successfully added...";
    } else {
        qWarning() << "DatabaseManager: message was not added!!! " << query.lastError().text();

    }
//    QSqlDatabase::database().commit();
}
