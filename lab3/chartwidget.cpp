#include "chartwidget.h"

ChartWidget::ChartWidget(QWidget *parent, DataVector const& data)
    : QWidget(parent), m_data(data)
{
    m_chartView = new QChartView;
    m_typeComboBox = new QComboBox;
    m_colorbwCheckBox = new QCheckBox;
    m_PDFPushButton = new QPushButton("Сохранить в формате PDF");
    m_sharedView = new QStackedWidget;
    QVBoxLayout *vlayout = new QVBoxLayout(this);
    QHBoxLayout *hlayout = new QHBoxLayout;
    QChart *chart = new QChart;

    chart->layout()->setContentsMargins(0, 0, 0, 0);    // для красоты
    m_chartView->setMinimumSize(QSize(700, 500));       // минимальный размер

    m_typeComboBox->setMinimumWidth(80);
    for (int i = 0; i < CHART_TYPE.size(); i++) {
            m_typeComboBox->addItem(CHART_TYPE[i]);
        }

    setChartType(CHART_TYPE[0]);
    m_chartType = CHART_TYPE[0];

    m_typeComboBox->setDisabled(true);
    m_colorbwCheckBox->setDisabled(true);
    m_PDFPushButton->setDisabled(true);

    m_chartView->setRenderHint(QPainter::Antialiasing); // сглаживание
    m_chartView->setFrameStyle(QFrame::StyledPanel);    // рамка
    m_chartView->setChart(chart);

    QLabel *chartTypeLabel = new QLabel("Тип графика:");
    QLabel *colorbwLabel = new QLabel ("чёрно-белый");

    hlayout->addWidget(chartTypeLabel);                 // добавляем компоненты в горизонтальный компоновщик
    hlayout->addWidget(m_typeComboBox);
    hlayout->addWidget(m_colorbwCheckBox);
    hlayout->addWidget(colorbwLabel);
    hlayout->addStretch();
    hlayout->addWidget(m_PDFPushButton);

    m_sharedView->addWidget(m_chartView);

    vlayout->addLayout(hlayout);                        // добавляем компоненты в вертикальный компоновщик
    vlayout->addWidget(m_sharedView);

    // сигнал о нажатии кнопки сохранить в формате PDF
    QObject::connect(m_PDFPushButton, &QPushButton::clicked, this, &ChartWidget::PBprintPDFSlot);
    // сигнал о выборе нового типа графика
    QObject::connect(m_typeComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &ChartWidget::CBchartTypeChangedSlot);
}

void ChartWidget::drawChartSlot() {
    m_typeComboBox->setDisabled(false);
    m_PDFPushButton->setDisabled(false);

    auto chartTemplate = injector.GetObject<ChartsTemplate>();

    if (!chartTemplate->setChart(m_chartView->chart(), m_data)) {
        m_typeComboBox->setDisabled(true);
        m_PDFPushButton->setDisabled(true);
    }
}

void ChartWidget::dataReadFailedSlot(QString const&)
{
    m_typeComboBox->setDisabled(true);
    m_PDFPushButton->setDisabled(true);
    m_colorbwCheckBox->setDisabled(true);
}

void ChartWidget::PBprintPDFSlot() {
    QString filePath = QFileDialog::getSaveFileName(nullptr, "Сохранить график в формате PDF", {}, "PDF (*.pdf)");
    if (filePath.isEmpty()) return;

    QPdfWriter pdfWriter(filePath);
    QPainter painter(&pdfWriter);
    m_chartView->render(&painter);
}

void ChartWidget::CBchartTypeChangedSlot(int index) {
    m_chartType = CHART_TYPE[index];
    setChartType(m_chartType);
    drawChartSlot();
}
