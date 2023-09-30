#ifndef CHARTWIDGET_H
#define CHARTWIDGET_H

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
    void drawChartSlot();
    void dataReadFailedSlot(QString const&);
private slots:
    void PBprintPDFSlot();
    void CBchartTypeChangedSlot(int empty);
private:
    QChartView *m_chartView;
    DataVector const& m_data;
    QComboBox *m_typeComboBox;
    QCheckBox *m_colorbwCheckBox;
    QPushButton *m_PDFPushButton;
    QStackedWidget *m_sharedView;

    QString m_chartType;
};

#endif // CHARTWIDGET_H
