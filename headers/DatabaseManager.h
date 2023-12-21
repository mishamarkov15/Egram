#ifndef EGRAM_DATABASEMANAGER_H
#define EGRAM_DATABASEMANAGER_H

#include <QString>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QMap>

class DatabaseManager {
private:
    DatabaseManager() = delete;

    DatabaseManager(const QString& host, const QString& database_name, const QString& username, const QString& password, qint32 port);

    explicit DatabaseManager(const QMap<QString, QString>& params);



    ~DatabaseManager();
    QSqlDatabase db;
    DatabaseManager* manager;
public:
    static DatabaseManager& getInstance();

    DatabaseManager(const DatabaseManager&) = delete;
    void operator=(const DatabaseManager&) = delete;

    [[nodiscard]] QList<QMap<QString, QString>> selectContactsForUser(quint64 user_id) const;
};


#endif //EGRAM_DATABASEMANAGER_H
