#include "chartstemplate.h"

/*QString typeAsString(EChartType type){
    QString s;
    switch (type) {
        case EChartType::Pie: s = "Pie"; break;
        case EChartType::Bar: s = "Bar"; break;
        default: s = ""; break;
    }
    return s;
}*/

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
