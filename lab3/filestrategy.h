#ifndef FILESTRATEGY_H
#define FILESTRATEGY_H

#include<QString>
#include<QMap>


class FileStrategy
{
public:
    virtual void read(QMap *fileData, const QString path) = 0;
};

class FileJSON: public FileStrategy
{
public:
    void read(QMap *fileData, const QString path) override;
};

class FileDat: public FileStrategy
{
public:
    void read(QMap *fileData, const QString path) override;
};

#endif // FILESTRATEGY_H
