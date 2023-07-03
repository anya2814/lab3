#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QtCharts/QChartGlobal>
#include <memory>
#include "chartdata.h"
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
    void fileSelectedMWSlot(std::shared_ptr<IOCContainer> injector, QFileInfo const&);
signals:
    void dataChangedSignal();
    void dataReadFailedSignal(QString const&);
private:
    DataVector m_chartData;
    ChartWidget *m_chartWidget;
    FileWidget *m_fileWidget;
};

#endif // MAINWINDOW_H
