#include "filewidget.h"

#include <QSplitter>
#include <QListView>
#include <QTreeView>
#include <QFileSystemModel>
#include <QItemSelectionModel>
#include <QTableView>
#include <QHeaderView>
#include <QStatusBar>

/*FileWidget::FileWidget(QWidget *parent)
    : QWidget(parent)
{
    QString homePath = QDir::homePath();
    m_model = new QFileSystemModel(this);
    m_model->setFilter(QDir::NoDotAndDotDot | QDir::Files);

    m_model->setRootPath(homePath);

    m_tableView = new QTableView;
    m_tableView->setModel(m_model);

    m_tableView->setRootIndex(homePath);
}*/

/*
 * Слот для обработки выбора элемента в TreeView.
 * Выбор осуществляется с помощью курсора.
 */

/*void FileWidget::on_selectionChangedSlot(const QItemSelection &selected, const QItemSelection &deselected)
{

}*/
