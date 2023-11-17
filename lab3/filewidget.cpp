#include "filewidget.h"

FileWidget::FileWidget(QWidget *parent): QWidget(parent)
{
    m_catalogPushButton = new QPushButton();
    m_tableModel = new QFileSystemModel(this);  // модель файловой системы
    m_tableModel->setFilter(QDir::Files);       // только файлы показываются в таблице
    QStringList filters;
    for (int i = 0; i < FILE_EXT.size(); i++)   // только удовл. фильтрам файлы активны
        filters << "*." + FILE_EXT[i];
    m_tableModel->setNameFilters(filters);
    m_tableModel->setRootPath(QDir::currentPath());
    QHBoxLayout *hlayout = new QHBoxLayout();
    QVBoxLayout *vlayout = new QVBoxLayout(this);

    m_tableView = new QTableView();             // представление модели в виде таблицы
    m_tableView->setModel(m_tableModel);
    m_tableView->setRootIndex(m_tableModel->index(QDir::currentPath()));
    m_tableView->setMinimumSize(425, 400);

    QLabel *pathLabel = new QLabel("Выбранный путь:");

    m_catalogPushButton->setText(QDir::currentPath());
    m_catalogPushButton->setMinimumWidth(80);

    hlayout->addWidget(pathLabel);
    hlayout->addWidget(m_catalogPushButton);
    hlayout->setAlignment(Qt::AlignLeft );

    vlayout->addLayout(hlayout);
    vlayout->addWidget(m_tableView);

    QItemSelectionModel *selectionModel = m_tableView->selectionModel();
    // сигнал о выборе файла в таблице
    QObject::connect(selectionModel, &QItemSelectionModel::currentChanged, this, &FileWidget::currentChangedSlot);
    // сигнал о нажатии кнопки выбора каталога с файлами
    QObject::connect(m_catalogPushButton, &QPushButton::clicked, this, &FileWidget::PBcatalogSlot);
}

void FileWidget::currentChangedSlot(const QModelIndex &selected, const QModelIndex &deselected)
{
    Q_UNUSED(deselected);
    emit fileSelectedSignal(m_tableModel->fileInfo(selected));
}

void FileWidget::PBcatalogSlot() {
    QString directory = QFileDialog::getExistingDirectory();
        if (!directory.isEmpty()) {
            m_tableModel->setRootPath(directory);
            m_tableView->setRootIndex(m_tableModel->index(directory));
            m_catalogPushButton->setText(directory);
        }
}

FileWidget::~FileWidget()
{
}


