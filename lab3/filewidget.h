#ifndef FILEWIDGET_H
#define FILEWIDGET_H

#include <QMainWindow>
#include <QWidget>
#include <QObject>

#include <QFileSystemModel>
#include <QTableView>
#include <QFileDialog>
#include <QItemSelectionModel>
#include <QModelIndex>

#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "chartdata.h"

class FileWidget : public QWidget
{
    Q_OBJECT
public:
    FileWidget(QWidget *parent = nullptr);
    ~FileWidget();
private slots:
    void currentChangedSlot(const QModelIndex &selected, const QModelIndex &deselected);
    void PBcatalogClickedSlot();
signals:
    void fileSelectedSignal(QFileInfo const&);
private:
    QFileSystemModel *m_tableModel;
    QTableView *m_tableView;
    QPushButton *m_catalogPushButton;
};

#endif // FILEWIDGET_H
