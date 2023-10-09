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
    ChartWidget(QWidget* parent, Data const& chartData);
public slots:
    void drawChartSlot();
    void dataReadFailedSlot(const QString errorMsg);
private slots:
    void PBprintPDFSlot();
    void CBchartTypeSlot(int index);
    void CBcolorSlot(int state);
private:
    QChartView *m_chartView;
    Data const &m_data;
    QComboBox *m_typeComboBox;
    QCheckBox *m_colorCheckBox;
    QPushButton *m_PDFPushButton;
    QStackedWidget *m_sharedView;
    QLabel *m_infoLabel;

    QString m_chartType;
};

#endif // CHARTWIDGET_H
