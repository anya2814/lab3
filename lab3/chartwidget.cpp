#include "chartwidget.h"

ChartWidget::ChartWidget(QWidget *parent, DataVector const& data)
    : QWidget(parent), m_data(data)
{
    m_chartView = new QChartView();
    m_typeComboBox = new QComboBox;
    m_colorbwCheckBox = new QCheckBox;
    m_PDFPushButton = new QPushButton("Сохранить в формате PDF");
    m_sharedView = new QStackedWidget;
    QVBoxLayout *vlayout = new QVBoxLayout(this);
    QHBoxLayout *hlayout = new QHBoxLayout();
    QChart *chart = new QChart;

    chart->layout()->setContentsMargins(0, 0, 0, 0);

    m_chartView->setMinimumSize(QSize(700, 500));

    m_typeComboBox->setEditable(false);
    m_typeComboBox->setMinimumWidth(80);

    for (int i = 0; i < (int) countTypes; i++) {
            m_typeComboBox->addItem(CHART_TYPE[i]);
        }

    setChartType(CHART_TYPE[0]);
    m_chartType = EChartType(0);

    m_typeComboBox->setDisabled(true);
    m_colorbwCheckBox->setDisabled(true);
    m_PDFPushButton->setDisabled(true);

    //m_chartView->setRenderHint(QPainter::Antialiasing);
    m_chartView->setFrameStyle(QFrame::StyledPanel);
    m_chartView->setChart(chart);

    QLabel *chartTypeLabel = new QLabel("Тип графика:");
    chartTypeLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

    QLabel *colorbwLabel = new QLabel ("чёрно/белый");
    colorbwLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

    hlayout->addWidget(chartTypeLabel);
    hlayout->addWidget(m_typeComboBox);
    hlayout->addWidget(m_colorbwCheckBox);
    hlayout->addWidget(colorbwLabel);
    hlayout->addStretch();
    hlayout->addWidget(m_PDFPushButton);

    m_sharedView->addWidget(m_chartView);

    vlayout->addLayout(hlayout);
    vlayout->addWidget(m_sharedView);

    // в конструкторе еще разные коннекты
}
