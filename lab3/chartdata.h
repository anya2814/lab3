#ifndef FILESTRATEGY_H
#define FILESTRATEGY_H

#include<QFile>
#include<QIODevice>
#include<QTextStream>
#include<QString>
#include<QVector>

#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonArray>

#include<QSql>
#include<QSqlDatabase>
#include<QSqlQuery>

typedef QPair<QString, QString> Data;
typedef QList<Data> DataVector;

class IChartData
{
public:
    virtual bool read(DataVector fileData, const QString path) = 0;
    virtual ~IChartData() = default;
};

class JSONData: public IChartData
{
public:
    bool read(DataVector fileData, const QString path) override {};
};

class SQLiteData: public IChartData
{
public:
    bool read(DataVector fileData, const QString path) override;
};

#endif // FILESTRATEGY_H
