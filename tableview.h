#ifndef TABLEVIEW_H
#define TABLEVIEW_H


#include <QAbstractTableModel>
#include "ctrl.h"

class table_veiw: public QAbstractTableModel
{
public:
    table_veiw(ctrl* c, QObject* parent = NULL);
    ~table_veiw();
    int rowCount(const QModelIndex &parent = QModelIndex{}) const override;
    int columnCount(const QModelIndex &parent = QModelIndex{}) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex & index) const override;


private:
    ctrl* _ctrl;
};

#endif // TABLEVIEW_H
