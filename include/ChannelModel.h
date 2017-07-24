#ifndef CHANNELMODEL_H
#define CHANNELMODEL_H

#include <QAbstractTableModel>

class ChannelModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    ChannelModel(QObject *parent);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override ;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    void setRowCount(int mrowNumber);
    int rowNumber;
};
#endif
