#ifndef CHARTSTEMPLATE_H
#define CHARTSTEMPLATE_H

#include <QString>
#include <QWidget>
#include <QtCharts/QtCharts>
#include <QtCharts/QChart>

#include "chartdata.h"

static inline QVector<QString> CHART_TYPE {"Pie", "Bar"};   // поддерж. типы графиков

class ChartsTemplate        // шаблон для графиков
{
public:
    bool setChart(QChart* chart, DataVector const& data);       // шаблонный метод для замены и установки графика
    virtual bool createChart(QChart* chart, DataVector const& data) = 0;  // метод для рисования графика
    virtual ~ChartsTemplate() = default;
};

class PieChart: public ChartsTemplate
{
    bool createChart(QChart* chart, DataVector const& data) override;
};

class BarChart: public ChartsTemplate
{
    bool createChart(QChart* chart, DataVector const& data) override;
};

bool setChartType(QString const type);     // выбор типа графика с помощью IOC контейнера

#endif // CHARTSTEMPLATE_H
