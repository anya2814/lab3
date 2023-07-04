#ifndef FILESTRATEGY_H
#define FILESTRATEGY_H

#include<QString>
#include<memory>

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

#include"ioccontainer.h"

typedef QPair<QString, QString> Data;
typedef QList<Data> DataVector;

enum class EFileExt {JSON, SQLite};
static inline QVector<QString> FILE_EXT = { "json", "sqlite"};
static inline int countFileExt = 2;

class IChartData
{
public:
    virtual bool read(const QString& path, DataVector& fileData) = 0;
    virtual ~IChartData() = default;
};

class JSONData: public IChartData
{
public:
    bool read(const QString& path, DataVector& fileData) override;
};

class SQLiteData: public IChartData
{
public:
    bool read(const QString& path, DataVector& fileData) override;
};

bool setStrategy(QString const& ext);

#endif // FILESTRATEGY_H
