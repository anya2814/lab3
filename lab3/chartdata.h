#ifndef CHARTDATA_H
#define CHARTDATA_H

#include<memory>
#include<QString>
#include<QFile>
#include<QTextStream>
#include<QVector>

#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonArray>

#include<QSql>
#include<QSqlDatabase>
#include<QSqlQuery>

#include"ioccontainer.h"

typedef QPair<QString, QString> DataElem;

struct Data {
    QString dataName;
    QList<DataElem> dataList;
};

static inline QVector<QString> FILE_EXT = {"dat", "json", "sqlite"};   // поддерж. типы расширений файлов

class IChartData            // стратегия чтения файлов
{
public:
    virtual bool read(const QString& path, Data& fileData, QString &errorMsg) = 0;   // виртуальная функция для чтения данных в filedata из файла с путем path
    virtual ~IChartData() = default;
};

class DatData: public IChartData       // чтение файлов формата json
{
public:
    bool read(const QString& path, Data& fileData, QString &errorMsg) override;
};

class JSONData: public IChartData       // чтение файлов формата json
{
public:
    bool read(const QString& path, Data& fileData, QString &errorMsg) override;
};

class SQLiteData: public IChartData     // чтение файлов формата sqlite
{
public:
    bool read(const QString& path, Data& fileData, QString &errorMsg) override;
};

bool setStrategy(QString const &ext);   // выбор стратегии с помощью IOC контейнера

#endif // CHARTDATA_H
