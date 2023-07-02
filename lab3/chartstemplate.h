#ifndef CHARTSTEMPLATE_H
#define CHARTSTEMPLATE_H

#include <QString>
#include <QWidget>
#include <QtCharts/QtCharts>
#include <QtCharts/QChart>

#include <QtCharts/QStackedBarSeries>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>

#include "chartdata.h"

enum class EChartType {Pie, Bar};
static inline QVector<QString> CHART_TYPE {"Pie", "Bar"};
static inline int countTypes = 2;

class ChartsTemplate
{
public:
    virtual bool createChart(QChart* chart, DataVector const& data) = 0;
};

class PieChart: public ChartsTemplate
{
    bool createChart(QChart* chart, DataVector const& data) override;
};

class BarChart: public ChartsTemplate
{
    bool createChart(QChart* chart, DataVector const& data) override;
};


#endif // CHARTSTEMPLATE_H
