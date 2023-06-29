#ifndef FILESTRATEGY_H
#define FILESTRATEGY_H


class FileStrategy
{
public:
    virtual void read(QMap *fileData) = 0;
};

class FileJSON: public FileStrategy
{
public:
    void read(QMap *fileData) override;
};

class FileDat: public FileStrategy
{
public:
    void read(QMap *fileData) override;
};

#endif // FILESTRATEGY_H
