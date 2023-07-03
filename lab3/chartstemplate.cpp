#include "chartstemplate.h"

bool setChartType(QString const& type) {
    IOCContainer injector;
    if (type == CHART_TYPE[0]) { injector.RegisterInstance<ChartsTemplate, PieChart>(); return 1; }
    if (type == CHART_TYPE[1]) { injector.RegisterInstance<ChartsTemplate, BarChart>(); return 1; }
    return 0;
}

bool ChartsTemplate::setChart(QChart* chart, DataVector const& data) {
    chart->removeAllSeries();

    if (!createChart(chart, data)) return 0;

    return 1;
}

bool BarChart::createChart(QChart* chart, DataVector const& data) {
    QBarSeries *series = new QBarSeries(chart);

    for (const auto t: data) {
        bool ok = true;
        auto value = t.second.toFloat(&ok);

        if(ok) {
            QBarSet *set = new QBarSet(t.first);
            series->append(set);
            set->append(value);
            series->append(set);
        }
        else return 0;
    }

    chart->addSeries(series);
    chart->createDefaultAxes();

    return 1;
}

bool PieChart::createChart(QChart* chart, DataVector const& data) {
    QPieSeries *series = new QPieSeries(chart);

    for (auto t: data) {
        bool ok = true;
        auto value = t.second.toFloat(&ok);

        if (ok) {
            series->append(t.first, value);
        } else return false;
    }

    chart->addSeries(series);
    chart->legend()->show();

    return 1;
}
