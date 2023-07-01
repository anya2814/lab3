#ifndef CHARTVIEW_H
#define CHARTVIEW_H

#include <QWidget>
#include <QtCharts/QtCharts>
#include <QtCharts/QChart>
#include <chartdata.h>
//#include <ioccontainer.h>

enum class ChartType { Pie, Bar, countTypes};

class ChartWidget: public QWidget
{
    Q_OBJECT
public:
    ChartWidget(QWidget* parent, DataVector const& data);
private slots:

    void CBTypeChosen() {};
    void PBPrintPDF() {};

private:
    QChartView *m_chartView;
    DataVector m_data;
    QComboBox *m_typeComboBox;
    QCheckBox *m_colorbwCheckBox;
    QPushButton *m_PDFPushButton;
    QStackedWidget *m_sharedView;

    ChartType m_chartType;
};

#endif // CHARTVIEW_H
