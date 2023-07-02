#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts/QChartGlobal>
#include "chartdata.h"
#include "chartwidget.h"
#include "filewidget.h"

QT_CHARTS_USE_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() = default;
private:
    DataVector m_chartData;
    ChartWidget *m_chartWidget;
    FileWidget *m_fileWidget;
};

#endif // MAINWINDOW_H
