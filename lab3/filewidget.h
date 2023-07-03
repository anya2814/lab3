#ifndef FILEVIEW_H
#define FILEVIEW_H

#include <QMainWindow>
#include <QWidget>
#include <QObject>
#include <QFileSystemModel>
#include <QTreeView>
#include <QTableView>
#include <QPushButton>
#include <QFileDialog>
#include <QStatusBar>
#include <QModelIndex>
#include <QLabel>
#include <memory>

#include "chartdata.h"
#include "chartstemplate.h"

class FileWidget : public QWidget
{
    Q_OBJECT
public:
    FileWidget(QWidget *parent = nullptr);
    ~FileWidget();
private slots:
    void selectionChangedSlot(const QItemSelection& selected, const QItemSelection& deselected);
    void PBcatalogClickedSlot();
signals:
    void fileSelectedSignal(QFileInfo const&);
private:
    QFileSystemModel *m_tableModel;
    QTableView *m_tableView;
    QPushButton *m_catalogPushButton;
};

#endif // FILEVIEW_H
