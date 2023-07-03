#ifndef CHARTVIEW_H
#define CHARTVIEW_H

#include <QWidget>
#include <QObject>

#include <QtCharts/QtCharts>
#include <QtCharts/QChart>
#include <QPdfWriter>
#include <QPainter>
#include <QComboBox>

#include "chartdata.h"
#include "chartstemplate.h"
#include "ioccontainer.h"

class ChartWidget: public QWidget
{
    Q_OBJECT
public:
    ChartWidget(QWidget* parent, DataVector const& data);
public slots:
    void dataChangedSlot();
    void dataReadFailedSlot(QString const&);
private slots:
    void CBtypeChangedSlot(EChartType type);
    void PBprintPDFSlot();
    void CBchartTypeIndexChangedSlot(int empty);
private:
    void drawChart();

    QChartView *m_chartView;
    DataVector m_data;
    QComboBox *m_typeComboBox;
    QCheckBox *m_colorbwCheckBox;
    QPushButton *m_PDFPushButton;
    QStackedWidget *m_sharedView;

    EChartType m_chartType;
};

#endif // CHARTVIEW_H
