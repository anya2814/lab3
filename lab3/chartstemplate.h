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

enum class EChartType {Pie = 0, Bar = 1};
static inline QVector<QString> CHART_TYPE {"Pie", "Bar"};
static inline int countTypes = 2;

class ChartsTemplate
{
public:
    virtual bool setChart(QChart* chart, DataVector const& data);
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

bool setChartType(QString const& type);

#endif // CHARTSTEMPLATE_H
