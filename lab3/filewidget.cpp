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
    //m_treeModel =  new QFileSystemModel(this);
    //m_treeModel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);

    m_tableModel = new QFileSystemModel(this);
    m_tableModel->setFilter(QDir::NoDotAndDotDot | QDir::Files);
    QStringList filters;
    for (int i = 0; i < countFileExt; i++)
        filters << "*." + FILE_EXT[i];
    m_tableModel->setNameFilters(filters);
    m_tableModel->setRootPath(QDir::currentPath());
    QVBoxLayout *vlayout = new QVBoxLayout(this);

    //Показатьв виде "дерева". Пользуемся готовым видом(TreeView):
    //m_treeView = new QTreeView();
    // Устанавливаем модель данных для отображения
    //m_treeView->setModel(leftPartModel);
    //Раскрываем все папки первого уровня
    //m_treeView->expandAll();

    m_tableView = new QTableView;
    m_tableView->setModel(m_tableModel);
    m_tableView->setRootIndex(m_tableModel->index(QDir::currentPath()));
    m_tableView->setMinimumSize(425, 400);
    vlayout->addWidget(m_tableView);
    /*
     * QItemSelectionModel *selectionModel отслеживает выбранные элементы в представлении treeView,
     * также отслеживает текущий выбранный элемент в представлении treeView.
    */
    //QItemSelectionModel *selectionModel = m_treeView->selectionModel();
    //m_treeView->header()->resizeSection(0, 200);

    //Выполняем соединения слота и сигнала который вызывается когда осуществляется выбор элемента в TreeView
    //connect(selectionModel, &QItemSelectionModel::selectionChanged, this, &FileWidget::on_selectionChangedSlot);

}

FileWidget::~FileWidget()
{
}

/*
 * Слот для обработки выбора элемента в TreeView.
 * Выбор осуществляется с помощью курсора.
 */

/*void FileWidget::on_selectionChangedSlot(const QItemSelection &selected, const QItemSelection &deselected)
{

}*/
