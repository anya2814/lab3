#include "chartwidget.h"

ChartWidget::ChartWidget(QWidget *parent, Data const& chartData)
    : QWidget(parent), m_data(chartData)
{
    m_chartView = new QChartView;
    m_typeComboBox = new QComboBox;
    m_colorCheckBox = new QCheckBox;
    m_PDFPushButton = new QPushButton("Сохранить в формате PDF");
    m_sharedView = new QStackedWidget;
    m_infoLabel = new QLabel("--Выберите файл для чтения--");
    QVBoxLayout *vlayout = new QVBoxLayout(this);
    QHBoxLayout *hlayout = new QHBoxLayout;
    QChart *chart = new QChart;

    m_infoLabel->setAlignment(Qt::AlignCenter);         // для красоты
    chart->layout()->setContentsMargins(0, 0, 0, 0);
    m_sharedView->setMinimumSize(QSize(700, 500));      // минимальный размер

    m_typeComboBox->setMinimumWidth(80);
    for (int i = 0; i < CHART_TYPE.size(); i++) {
            m_typeComboBox->addItem(CHART_TYPE[i]);
        }

    setChartType(CHART_TYPE[0]);
    m_chartType = CHART_TYPE[0];

    QGraphicsColorizeEffect *graphicsEffect = new QGraphicsColorizeEffect;
    graphicsEffect->setColor(Qt::black);
    graphicsEffect->setEnabled(false);
    chart->setGraphicsEffect(graphicsEffect);

    m_typeComboBox->setDisabled(true);
    m_colorCheckBox->setDisabled(true);
    m_PDFPushButton->setDisabled(true);

    m_chartView->setRenderHint(QPainter::Antialiasing); // сглаживание
    m_chartView->setFrameStyle(QFrame::StyledPanel);    // рамка
    m_chartView->setChart(chart);

    QLabel *chartTypeLabel = new QLabel("Тип графика:");
    QLabel *colorbwLabel = new QLabel ("чёрно-белый");

    hlayout->addWidget(chartTypeLabel);                 // добавляем компоненты в горизонтальный компоновщик
    hlayout->addWidget(m_typeComboBox);
    hlayout->addWidget(m_colorCheckBox);
    hlayout->addWidget(colorbwLabel);
    hlayout->addStretch();
    hlayout->addWidget(m_PDFPushButton);

    m_sharedView->addWidget(m_infoLabel);
    m_sharedView->addWidget(m_chartView);
    m_sharedView->setCurrentWidget(m_infoLabel);

    vlayout->addLayout(hlayout);                        // добавляем компоненты в вертикальный компоновщик
    vlayout->addWidget(m_sharedView);

    // сигнал о нажатии кнопки сохранить в формате PDF
    QObject::connect(m_PDFPushButton, &QPushButton::clicked, this, &ChartWidget::PBprintPDFSlot);
    // сигнал о выборе нового типа графика
    QObject::connect(m_typeComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &ChartWidget::CBchartTypeSlot);
    // сигнал о смене цветовой гаммы графика
    QObject::connect(m_colorCheckBox, &QCheckBox::stateChanged, this, &ChartWidget::CBcolorSlot);
}

void ChartWidget::drawChartSlot() {
    m_typeComboBox->setDisabled(false);
    m_PDFPushButton->setDisabled(false);
    m_colorCheckBox->setDisabled(false);

    auto chartTemplate = injector.GetObject<ChartsTemplate>();

    if (!chartTemplate->setChart(m_chartView->chart(), m_data)) {
        m_PDFPushButton->setDisabled(true);
        m_colorCheckBox->setDisabled(true);
        dataReadFailedSlot("--Не удалось построить график по данным выбранного файла--");
    }
    else {
        m_sharedView->setCurrentWidget(m_chartView);
    }
}

void ChartWidget::dataReadFailedSlot(QString const errorMsg)
{
    m_typeComboBox->setDisabled(true);
    m_PDFPushButton->setDisabled(true);
    m_colorCheckBox->setDisabled(true);
    m_infoLabel->setText(errorMsg);
    m_sharedView->setCurrentWidget(m_infoLabel);
}

void ChartWidget::PBprintPDFSlot() {
    QString filePath = QFileDialog::getSaveFileName(nullptr, "Save chart as a PDF document", {}, "PDF (*.pdf)");
    if (filePath.isEmpty()) return;

    bool f = m_colorCheckBox->isChecked();
    if (f) m_chartView->chart()->graphicsEffect()->setEnabled(false);
    QPdfWriter pdfWriter(filePath);
    QPainter painter(&pdfWriter);

    m_chartView->render(&painter);
    if (f) m_chartView->chart()->graphicsEffect()->setEnabled(true);
    painter.end();
}

void ChartWidget::CBchartTypeSlot(int index) {
    m_chartType = CHART_TYPE[index];
    setChartType(m_chartType);
    drawChartSlot();
}

void ChartWidget::CBcolorSlot(int state) {
    if (state) m_chartView->chart()->graphicsEffect()->setEnabled(true);
    else m_chartView->chart()->graphicsEffect()->setEnabled(false);
}
