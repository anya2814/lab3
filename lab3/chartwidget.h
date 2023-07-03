#ifndef CHARTVIEW_H
#define CHARTVIEW_H

#include <QWidget>
#include <QObject>

#include <QtCharts/QtCharts>
#include <QtCharts/QChart>

#include "chartdata.h"
#include "chartstemplate.h"
#include "ioccontainer.h"

class ChartWidget: public QWidget
{
    Q_OBJECT
public:
    ChartWidget(QWidget* parent, DataVector const& data);
public slots:
signals:
    void dataChanged();
    void dataReadFailed(QString const&);
public slots:
    void dataChangedSlot();
    void dataReadFailedSlot(QString const&);
private slots:
    void CBtypeChosenSlot() {};
    void PBprintPDFSlot() {};
    void CBchartTypeIndexChangedSlot(int index) {};
    void CBcolorSchemeIndexChangedSlot(int index) {};
private:
    QChartView *m_chartView;
    DataVector m_data;
    QComboBox *m_typeComboBox;
    QCheckBox *m_colorbwCheckBox;
    QPushButton *m_PDFPushButton;
    QStackedWidget *m_sharedView;

    EChartType m_chartType;
};

#endif // CHARTVIEW_H
