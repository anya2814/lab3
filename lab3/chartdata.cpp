#include "chartdata.h"

bool JSONData::read(const QString& path, DataVector& fileData)
{
    /*QFile file = QFile(path);
    fileData = DataMap();
    //проверка, открылся ли файл
    if (!file.exists() || !file.open(QIODeviceBase::ReadOnly)) return 0;
*/
    return 0;
}

bool SQLiteData::read(const QString& path, DataVector& fileData)
{
    if (!QFile::exists(path)) return 0;
    fileData = DataVector();

    QSqlDatabase dbase = QSqlDatabase::addDatabase("QSQLITE");
    dbase.setDatabaseName(path);
    if (!dbase.open()) return 0;

    QSqlQuery query;
    QString tableName = dbase.tables().first();
    QString str = "SELECT * FROM " + tableName;
    query = QSqlQuery(str);
    if (!query.next()) { dbase.close(); return 0; }

    auto prevDate = query.value(0).toString().split(' ').first().split('.');
    auto prevValue = query.value(1).toFloat();

    auto prevMonth = prevDate.at(1).toInt();
    auto prevYear = prevDate.at(2).toInt();

    float averageValue = prevValue;
    int n = 1;

    while (query.next()) {
    auto date = query.value(0).toString().split(' ').first().split('.');
    auto value = query.value(1).toFloat();

    auto month = date.at(1).toInt();
    auto year = date.at(2).toInt();


    if (year == prevYear && month == prevMonth) {
        n += 1;
        averageValue += value;
    }
    else {
        averageValue = averageValue/ (n*(1.0));
        QString monthNum = QString::number(prevMonth);
        Data d(QString::number(prevYear) + "." + monthNum, QString::number(averageValue));
        fileData.push_back(d);

        averageValue = value;
        prevYear = year;
        prevMonth = month;
        n = 1;
    }
    }

    dbase.close();
    return 1;
}

bool setStrategy(QString const& ext)
{
    //IOCContainer injector;
    if (ext == FILE_EXT[0]) { injector.RegisterInstance<IChartData, JSONData>(); return 1; }
    if (ext == FILE_EXT[1]) {
        injector.RegisterInstance<IChartData, SQLiteData>();
        return 1; }
    return 0;
}
