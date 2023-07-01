#include "mainwindow.h"
#include <QApplication>

#include"chartdata.h"
#include"memory"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    DataVector data = DataVector();
    SQLiteData d;
    d.read(data, "C:/Users/ivank/Desktop/lab3_data/InputDataSQLite/BLOOD_SUGAR.sqlite");

    return a.exec();
}
