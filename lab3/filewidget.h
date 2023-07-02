#ifndef FILEVIEW_H
#define FILEVIEW_H

#include <QMainWindow>
#include <QWidget>
#include <QFileSystemModel>
#include <QTreeView>
#include <QTableView>

#include "chartdata.h"

class FileWidget : public QWidget

{
    //Q_OBJECT

public:
    FileWidget(QWidget *parent = nullptr);
    ~FileWidget();
private:
    QFileSystemModel *m_tableModel;
    //QFileSystemModel *m_treeModel;
    QTableView *m_tableView;
    //QTreeView *m_treeView;
};

#endif // FILEVIEW_H
