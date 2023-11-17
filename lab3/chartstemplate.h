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
protected:
    virtual bool createChart(QChart* chart, Data const& chartData) = 0;  // метод для рисования графика
public:
    bool setChart(QChart* chart, Data const& chartData);       // шаблонный метод для замены и установки графика
    virtual ~ChartsTemplate() = default;
};

class PieChart: public ChartsTemplate
{
protected:
    bool createChart(QChart* chart, Data const& chartData) override;
};

class BarChart: public ChartsTemplate
{
protected:
    bool createChart(QChart* chart, Data const& chartData) override;
};

bool setChartType(QString const &type);     // выбор типа графика с помощью IOC контейнера

#endif // CHARTSTEMPLATE_H
