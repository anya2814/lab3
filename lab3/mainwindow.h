#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>

#include "chartwidget.h"
#include "filewidget.h"

#undef GetObject;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() = default;
public slots:
    void fileSelectedMWSlot(QFileInfo const&);
signals:
    void dataChangedSignal();
    void dataReadFailedSignal(QString const errorMsg);
private:
    DataVector m_chartData;
    QString m_dataName;
    ChartWidget *m_chartWidget;
    FileWidget *m_fileWidget;
};

#endif // MAINWINDOW_H
