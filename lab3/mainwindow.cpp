#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), m_chartData()
{
    QSplitter *splitter = new QSplitter(this);
    m_chartWidget = new ChartWidget (this, m_chartData);
    m_fileWidget = new FileWidget(this);
    setGeometry(100, 100, 1300, 600);

    splitter->addWidget(m_fileWidget);
    splitter->addWidget(m_chartWidget);

    setCentralWidget(splitter);

    // сигнал о выборе файла для чтения
    QObject::connect(m_fileWidget, &FileWidget::fileSelectedSignal, this, &MainWindow::fileSelectedMWSlot);
    // сигнал об изменении данных для графика
    QObject::connect(this, &MainWindow::dataChangedSignal, m_chartWidget, &ChartWidget::drawChartSlot);
    // сигнал об ошибке в чтении данных
    QObject::connect(this, &MainWindow::dataReadFailedSignal, m_chartWidget, &ChartWidget::dataReadFailedSlot);
}

void MainWindow::fileSelectedMWSlot(QFileInfo const& file)
{
    QString ext = file.suffix();
    QString errorMsg;

    setStrategy(ext);
    auto readingStrategy = injector.GetObject<IChartData>();

    if (readingStrategy->read(file.absoluteFilePath(), m_chartData, errorMsg)) {
        emit MainWindow::dataChangedSignal();
    }
    else emit MainWindow::dataReadFailedSignal(errorMsg);
}
