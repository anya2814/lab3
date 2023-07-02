
#include "mainwindow.h"
//#include "ui_mainwindow.h"
#include <QString>
#include <QTime>
#include <QLabel>
#include <QSplitter>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QStackedBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QStatusBar>

#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QAbstractBarSeries>
#include <QtCharts/QPercentBarSeries>
#include <QtCharts/QStackedBarSeries>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLineSeries>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QScatterSeries>
#include <QtCharts/QAreaSeries>
#include <QtCharts/QLegend>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtCore/QTime>
#include <QtCharts/QBarCategoryAxis>

//#include <QtCharts/QAbstractAxis>
//#include <QtCharts/QAbstractSeries>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QLabel *justTmpLabel = new QLabel(this);
    justTmpLabel->setText("------В этой части будем отображать файлы с данными для графика----");


    QSplitter *splitter = new QSplitter(this);
    m_chartWidget = new ChartWidget (this, m_chartData);
    //m_fileWidget = new FileWidget();
    setGeometry(100, 100, 1500, 500);
    setStatusBar(new QStatusBar(this));
    statusBar()->showMessage("Выбранный путь: ");

    splitter->addWidget(justTmpLabel);
    splitter->addWidget(m_chartWidget);
    //splitter->addWidget(m_fileWidget);

    setCentralWidget(splitter);
}

