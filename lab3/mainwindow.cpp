
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
    QSplitter *splitter = new QSplitter(this);
    m_chartWidget = new ChartWidget (this, m_chartData);
    m_fileWidget = new FileWidget(this);
    setGeometry(100, 100, 1300, 600);

    splitter->addWidget(m_fileWidget);
    splitter->addWidget(m_chartWidget);

    setCentralWidget(splitter);

    QObject::connect(m_fileWidget, &FileWidget::fileSelectedSignal, this, &MainWindow::fileSelectedMWSlot);
    QObject::connect(this, &MainWindow::dataChangedSignal, m_chartWidget, &ChartWidget::dataChangedSlot);
    QObject::connect(this, &MainWindow::dataReadFailedSignal, m_chartWidget, &ChartWidget::dataReadFailedSlot);
}

void MainWindow::fileSelectedMWSlot(std::shared_ptr<IOCContainer> injector, QFileInfo const& file)
{
    setStrategy(injector, file.suffix());
    injector->RegisterInstance<IChartData, SQLiteData>();
    auto readingStrategy = injector->GetObject<IChartData>();

    if (readingStrategy->read(file.absoluteFilePath(), this->m_chartData)) {
        emit MainWindow::dataChangedSignal();
    }
    else emit MainWindow::dataReadFailedSignal("");
}
