
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

QT_CHARTS_BEGIN_NAMESPACE
class QChartView;
class QChart;
QT_CHARTS_END_NAMESPACE

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(100, 100, 1500, 500);
    this->setStatusBar(new QStatusBar(this));
    this->statusBar()->showMessage("Choosen Path: ");

    QLabel *justTmpLabel = new QLabel(this);
    justTmpLabel->setText("------В этой части будем отображать файлы с данными для графика----");


    QSplitter *splitter = new QSplitter(parent);
    splitter->addWidget(justTmpLabel);
    //1.Добавление диаграмы(графика). Диаграмму создаем в несколько шагов.
    QtCharts::QChartView *chartView = nullptr;
    //Объявление представления графика.Представление отображает график.
    /*Создание графика*/
    QtCharts::QChart *chartBar = new QtCharts::QChart();
    chartBar->setTitle("Bar chart"); //Устанавливаем заголовок графика

    /*Класс QStackedBarSeries представляет серию данных в виде вертикально расположенных полос, по одной полосе на категорию.*/
    QStackedBarSeries *series = new QStackedBarSeries(chartBar); //Работаем с гиcтограммой.
    // Класс QBarSet представляет один набор столбцов на гистограмме.
    QBarSet *set = nullptr;

    //	set seed for random stuff
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));

    for (int i(0); i < 10; i++) {

        set = new QBarSet("Bar set " + QString::number(i));
        qreal yValue(0);

        for (int j(0); j < 5; j++) {
            yValue = yValue + (qreal)(qrand() % 121 + j) / (qreal) 10 + j;
            *set << yValue;
        }

        series->append(set);
    }

    chartView = new QChartView(chartBar);
    chartView->setMinimumSize(QSize(700, 500));
    chartBar->addSeries(series);
    chartBar->createDefaultAxes();
    splitter->addWidget(chartView);
    //splitter->addWidget(themeWidget);

    setCentralWidget(splitter);

}

/*QComboBox *MainWindow::createTypeBox() const
{
    // settings layout
    QComboBox *themeComboBox = new QComboBox();
    themeComboBox->addItem("Light", QChart::ChartThemeLight);
    themeComboBox->addItem("Blue Cerulean", QChart::ChartThemeBlueCerulean);
    themeComboBox->addItem("Dark", QChart::ChartThemeDark);
    themeComboBox->addItem("Brown Sand", QChart::ChartThemeBrownSand);
    themeComboBox->addItem("Blue NCS", QChart::ChartThemeBlueNcs);
    themeComboBox->addItem("High Contrast", QChart::ChartThemeHighContrast);
    themeComboBox->addItem("Blue Icy", QChart::ChartThemeBlueIcy);
    themeComboBox->addItem("Qt", QChart::ChartThemeQt);
    return themeComboBox;
}
*/
MainWindow::~MainWindow()
{
    //delete ui;
}
