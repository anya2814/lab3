#include "filewidget.h"

#include <QVBoxLayout>
#include <QListView>
#include <QTreeView>
#include <QFileSystemModel>
#include <QItemSelectionModel>
#include <QTableView>
#include <QHeaderView>
#include <QStatusBar>

FileWidget::FileWidget(QWidget *parent): QWidget(parent)
{
    m_catalogPushButton = new QPushButton(this);
    m_tableModel = new QFileSystemModel(this);
    m_tableModel->setFilter(QDir::NoDotAndDotDot | QDir::Files);
    QStringList filters;
    for (int i = 0; i < countFileExt; i++)
        filters << "*." + FILE_EXT[i];
    m_tableModel->setNameFilters(filters);
    m_tableModel->setRootPath(QDir::currentPath());
    QVBoxLayout *vlayout = new QVBoxLayout(this);

    m_tableView = new QTableView;
    m_tableView->setModel(m_tableModel);
    m_tableView->setRootIndex(m_tableModel->index(QDir::currentPath()));
    m_tableView->setMinimumSize(425, 400);

    m_catalogPushButton->setText("Выбранный путь: " + QDir::currentPath());
    m_catalogPushButton->setMinimumWidth(80);

    vlayout->addWidget(m_catalogPushButton);
    vlayout->addWidget(m_tableView);

    QItemSelectionModel *selectionModel = m_tableView->selectionModel();
    QObject::connect(selectionModel, &QItemSelectionModel::selectionChanged, this, &FileWidget::selectionChangedSlot);
    QObject::connect(m_catalogPushButton, &QPushButton::clicked, this, &FileWidget::PBcatalogClickedSlot);
}

void FileWidget::selectionChangedSlot(const QItemSelection& selected, const QItemSelection& deselected) {
    if (deselected == selected) return;

    //emit fileSelectedSignal(m_tableModel->index(QDir::currentPath()));
}

void FileWidget::PBcatalogClickedSlot() {
    auto directory = QFileDialog::getExistingDirectory();
        if (!directory.isEmpty()) {
            m_tableModel->setRootPath(directory);
            m_tableView->setRootIndex(m_tableModel->index(directory));
            m_catalogPushButton->setText("Выбранный путь: " + directory);
        }
}

FileWidget::~FileWidget()
{
}


