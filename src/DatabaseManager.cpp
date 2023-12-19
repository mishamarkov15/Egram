#include "../headers/DatabaseManager.h"

DatabaseManager::DatabaseManager(const QString &host, const QString &database_name, const QString &username,
                                 const QString &password, qint32 port) : db(QSqlDatabase::addDatabase("QPSQL")){
    db.setHostName(host);
    db.setDatabaseName(database_name);
    db.setUserName(username);
    db.setPassword(password);
    db.setPort(port);
    if (db.isOpen()) {
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
    } catch (std::exception& err) {
        qCritical() << "DatabaseManager: " << err.what();
    }
    if (db.isOpen()) {
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
