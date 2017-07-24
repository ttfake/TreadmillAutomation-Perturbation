#include "include/ChannelModel.h"

ChannelModel::ChannelModel(QObject *parent)
    :QAbstractTableModel(parent)
{
}

int ChannelModel::rowCount(const QModelIndex & /*parent*/) const
{
   return rowNumber;
}

int ChannelModel::columnCount(const QModelIndex & /*parent*/) const
{
    return 4;
}

QVariant ChannelModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
       return QString("Row%1, Column%2")
                   .arg(index.row() + 1)
                   .arg(index.column() +1);
     }
    return QVariant();
}

void ChannelModel::setRowCount(int mrowNumber)
{
    rowNumber = mrowNumber;
}

#include "../include/moc_ChannelModel.cpp"
