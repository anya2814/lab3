#include "chartstemplate.h"

bool ChartsTemplate::setChart(QChart* chart, Data const& chartData) {
    chart->removeAllSeries();

    if (!createChart(chart, chartData)) return false;  // рисуем график
    chart->setTitle(chartData.dataName);

    return true;
}

bool BarChart::createChart(QChart* chart, Data const& chartData) {
    QBarSeries *series = new QBarSeries(chart);

    for (const auto t: chartData.dataList) {
        bool ok = true;
        auto value = t.second.toFloat(&ok);

        if(ok) {
            QBarSet *set = new QBarSet(t.first);
            set->append(value);
            series->append(set);
        }
        else return false;
    }

    chart->addSeries(series);
    chart->createDefaultAxes();

    return true;
}

bool PieChart::createChart(QChart* chart, Data const& chartData) {
    QPieSeries *series = new QPieSeries(chart);

    for (auto t: chartData.dataList) {
        bool ok = true;
        auto value = t.second.toFloat(&ok);

        if (ok) {
            series->append(t.first, value);
        } else return false;
    }

    chart->addSeries(series);

    return true;
}

bool setChartType(QString const &type) {
    if (type == CHART_TYPE[0]) { injector.RegisterInstance<ChartsTemplate, PieChart>(); return true; }
    if (type == CHART_TYPE[1]) { injector.RegisterInstance<ChartsTemplate, BarChart>(); return true; }
    return 0;
}
