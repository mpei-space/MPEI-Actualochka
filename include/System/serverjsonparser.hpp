#ifndef SERVERJSONPARSER_HPP
#define SERVERJSONPARSER_HPP

#include <QObject>
#include <QDate>
#include <QtNetwork/QNetworkReply>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>

#include "include/General/general.hpp"

enum EReply_Type
{
    ScheduleWeek = 0,
    Actualochka = 1
};

class ServerJsonParser : public QObject
{
    Q_OBJECT
public:
    ServerJsonParser() = delete;

    static bool isOnline();
    static QMap<QString, quint32> ParseGroups(QNetworkReply *reply);
    static QVector<QString> ParseJsonFromServer(QNetworkReply *reply, EReply_Type type);
    static QVector<CellData> ParseJsonMonth(QNetworkReply *reply);
    static QString ParseVersion(QNetworkReply *reply);
private:

    static QMap<QString, quint32> ParseJsonGroups(QJsonArray& tjsonArray);
    static QVector<QString> ParseJson(QJsonArray& tjsonArray);
};

#endif // SERVERJSONPARSER_HPP
