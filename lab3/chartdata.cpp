#include "chartdata.h"

bool DatData::read(const QString& path, Data& fileData, QString &errorMsg)
{
    QFile file(path);
    fileData.dataList = QList<DataElem>();
    if (file.isOpen()) { errorMsg = "--Файл уже открыт--"; return false; }
    if (!file.exists()) { errorMsg = "--Файл не существует--"; return false; }
    if( !file.open(QIODevice::ReadOnly)) { errorMsg = "--Не удалось открыть файл--"; return false; }
    fileData.dataName = file.fileName().split('/').last();
    fileData.dataName = fileData.dataName.split('.').first();

    QTextStream r(&file);

    QStringList line = r.readLine().split('\t');
    if (line.size() != 2) { errorMsg = "--Неподдерживаемый формат данных--"; return false; }

    QStringList startDate = line.first().split('.');
    if (startDate.size() != 3) {errorMsg = "--Неподдерживаемый формат данных--"; return false;  }
    float startValue = line.last().toFloat();

    // запоминаем месяц и год первые в группе
    int startMonth = startDate.at(1).toInt();
    int startYear = startDate.at(2).toInt();

    float averageValue = startValue;
    int n = 1;

    while (!r.atEnd()) {
        line = r.readLine().split('\t');
        if (line.size() != 2) { errorMsg = "--Неподдерживаемый формат данных--"; return false; }
        QStringList date = line.first().split('.');
        float value = line.last().toFloat();

        int month = date.at(1).toInt();
        int year = date.at(2).toInt();

        // группируем данные по месяцам годов
        if (year == startYear && month == startMonth) {
            n += 1;
            averageValue += value;
        }
        else {
            averageValue = averageValue/ (n*(1.0));
            DataElem d(QString::number(startYear) + "." + QString::number(startMonth), QString::number(averageValue));
            fileData.dataList.push_back(d);

            averageValue = value;
            startYear = year;
            startMonth = month;
            n = 1;
    }
    }

    averageValue = averageValue/ (n*(1.0));
    DataElem d(QString::number(startYear) + "." + QString::number(startMonth), QString::number(averageValue));
    fileData.dataList.push_back(d);

    file.close();
    return true;
}

bool JSONData::read(const QString& path, Data& fileData, QString &errorMsg)
{
    QFile file(path);
    fileData.dataList = QList<DataElem>();
    if (file.isOpen()) { errorMsg = "--Файл уже открыт--"; return false; }
    if (!file.exists()) { errorMsg = "--Файл не существует--"; return false; }
    if( !file.open(QIODevice::ReadOnly)) { errorMsg = "--Не удалось открыть файл--"; return false; }
    fileData.dataName = file.fileName().split('/').last();
    fileData.dataName = fileData.dataName.split('.').first();

    QString allData = file.readAll();
    file.close();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(allData.toUtf8());
    if (!jsonDoc.isObject()) { errorMsg = "--Неподдерживаемый формат данных--"; return false; }
    QJsonObject const jsonObj = jsonDoc.object();
    if (!jsonObj.contains("data")) { errorMsg = "--Массив с данными должен быть под названием \"data\"--"; return false; }

    if (!jsonObj["data"].isArray()) { errorMsg = "--Неподдерживаемый формат данных--"; return false; }
    QJsonArray jsonArr = jsonObj["data"].toArray();
    if (jsonArr.isEmpty()) { errorMsg = "--Данных в файле нет--"; return false; }

    QJsonValue item = jsonArr[0];
    if (!item.isArray()) { errorMsg = "--Неподдерживаемый формат данных--"; return false; }
    QJsonArray pair = item.toArray();
    if (pair.size() != 2) { errorMsg = "--Неподдерживаемый формат данных--"; return false; }

    QStringList startDate = pair.at(0).toString().split(' ').first().split('.');
    if (startDate.size() != 3) {errorMsg = "--Неподдерживаемый формат данных--"; return false;  }
    float startValue = pair.at(1).toString().toFloat();

    // запоминаем месяц и год первые в группе
    int startMonth = startDate.at(1).toInt();
    int startYear = startDate.at(2).toInt();

    float averageValue = startValue;
    int n = 1;

    for (int i=1; i < jsonArr.size(); i++) {
        item = jsonArr[i];
        if (!item.isArray()) { errorMsg = "--Неподдерживаемый формат данных--"; return false; }
        QJsonArray pair = item.toArray();
        if (pair.size() != 2) { errorMsg = "--Неподдерживаемый формат данных--"; return false; }

        QStringList date = pair.at(0).toString().split(' ').first().split('.');
        float value = pair.at(1).toString().toFloat();

        int month = date.at(1).toInt();
        int year = date.at(2).toInt();

        // группируем данные по месяцам годов
        if (year == startYear && month == startMonth) {
            n += 1;
            averageValue += value;
        }
        else {
            averageValue = averageValue/ (n*(1.0));
            DataElem d(QString::number(startYear) + "." + QString::number(startMonth), QString::number(averageValue));
            fileData.dataList.push_back(d);

            averageValue = value;
            startYear = year;
            startMonth = month;
            n = 1;
        }
    }

    averageValue = averageValue/ (n*(1.0));
    DataElem d(QString::number(startYear) + "." + QString::number(startMonth), QString::number(averageValue));
    fileData.dataList.push_back(d);

    return true;
}

bool SQLiteData::read(const QString& path, Data& fileData, QString &errorMsg)
{
    if (!QFile::exists(path)) { errorMsg = "--Файл не существует--"; return false; }
    fileData.dataList = QList<DataElem>();

    QSqlDatabase dbase = QSqlDatabase::addDatabase("QSQLITE");  // создаем соединение
    dbase.setDatabaseName(path);                                // конкретизируем
    if (dbase.isOpen()){ errorMsg = "--Файл уже открыт--"; return false; }
    if (!dbase.open()) { errorMsg = "--Не удалось открыть файл--"; return false; }  // открываем базу данных

    QSqlQuery query;

    // создаем запрос
    QString tableName = dbase.tables().first();
    fileData.dataName = tableName;
    QString str = "SELECT * FROM " + tableName;
    query = QSqlQuery(str);
    if (!query.next()) { dbase.close(); errorMsg = "--База данных пустая--"; return false; }

    QStringList startDate = query.value(0).toString().split(' ').first().split('.');
    if (startDate.size() != 3) {errorMsg = "--Неподдерживаемый формат данных--"; return false;  }
    float startValue = query.value(1).toFloat();

    // запоминаем месяц и год первые в группе
    int startMonth = startDate.at(1).toInt();
    int startYear = startDate.at(2).toInt();

    float averageValue = startValue;
    int n = 1;

    while (query.next()) {
    QStringList date = query.value(0).toString().split(' ').first().split('.');
    float value = query.value(1).toFloat();

    int month = date.at(1).toInt();
    int year = date.at(2).toInt();

    // группируем данные по месяцам годов
    if (year == startYear && month == startMonth) {
        n += 1;
        averageValue += value;
    }
    else {
        averageValue = averageValue/ (n*(1.0));
        DataElem d(QString::number(startYear) + "." + QString::number(startMonth), QString::number(averageValue));
        fileData.dataList.push_back(d);

        averageValue = value;
        startYear = year;
        startMonth = month;
        n = 1;
    }
    }

    averageValue = averageValue/ (n*(1.0));
    DataElem d(QString::number(startYear) + "." + QString::number(startMonth), QString::number(averageValue));
    fileData.dataList.push_back(d);
    dbase.close();
    return true;
}

bool setStrategy(QString const &ext)
{
    if (ext == FILE_EXT[0]) { injector.RegisterInstance<IChartData, DatData>(); return true; }
    if (ext == FILE_EXT[1]) { injector.RegisterInstance<IChartData, JSONData>(); return true; }
    if (ext == FILE_EXT[2]) { injector.RegisterInstance<IChartData, SQLiteData>(); return true; }
    return false;
}
