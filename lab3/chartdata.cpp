#include "chartdata.h"

bool JSONData::read(const QString& path, DataVector& fileData)
{
    /*QFile file = QFile(path);
    fileData = DataMap();
    //проверка, открылся ли файл
    if (!file.exists() || !file.open(QIODeviceBase::ReadOnly)) return 0;
*/
    return false;
}

bool SQLiteData::read(const QString& path, DataVector& fileData)
{
    if (!QFile::exists(path)) return false;
    fileData = DataVector();

    QSqlDatabase dbase = QSqlDatabase::addDatabase("QSQLITE");  // создаем соединение
    dbase.setDatabaseName(path);                                // конкретизируем
    if (!dbase.open()) return false;                            // открываем базу данных

    QSqlQuery query;

    // создаем запрос
    QString tableName = dbase.tables().first();
    QString str = "SELECT * FROM " + tableName;
    query = QSqlQuery(str);
    if (!query.next()) { dbase.close(); return false; }

    auto startDate = query.value(0).toString().split(' ').first().split('.');
    auto startValue = query.value(1).toFloat();

    // запоминаем месяц и год первые в группе
    auto startMonth = startDate.at(1).toInt();
    auto startYear = startDate.at(2).toInt();

    float averageValue = startValue;
    int n = 1;

    while (query.next()) {
    auto date = query.value(0).toString().split(' ').first().split('.');
    auto value = query.value(1).toFloat();

    auto month = date.at(1).toInt();
    auto year = date.at(2).toInt();

    // группируем данные по месяцам годов
    if (year == startYear && month == startMonth) {
        n += 1;
        averageValue += value;
    }
    else {
        averageValue = averageValue/ (n*(1.0));
        Data d(QString::number(startYear) + "." + QString::number(startMonth), QString::number(averageValue));
        fileData.push_back(d);

        averageValue = value;
        startYear = year;
        startMonth = month;
        n = 1;
    }
    }

    dbase.close();
    return true;
}

bool setStrategy(QString const& ext)
{
    if (ext == FILE_EXT[0]) { injector.RegisterInstance<IChartData, JSONData>(); return 1; }
    if (ext == FILE_EXT[1]) { injector.RegisterInstance<IChartData, SQLiteData>(); return 1; }
    return false;
}
