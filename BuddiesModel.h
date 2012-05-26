#ifndef BUDDIESMODEL_H
#define BUDDIESMODEL_H

#include <QAbstractItemModel>
#include <QStringList>
#include <QModelIndex>
#include <QVariant>
#include <QString>
#include <QObject>

#include "BuddyItem.h"

class BuddiesModel: public QAbstractItemModel {
Q_OBJECT

public:
    BuddiesModel(const QString &data, QObject *parent=0);
    ~BuddiesModel();

    QVariant data(const QModelIndex &index, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role=Qt::DisplayRole) const;
    QModelIndex index(int row, int column, const QModelIndex &parent=QModelIndex()) const;
    QModelIndex parent(const QModelIndex &index) const;
    int rowCount(const QModelIndex &parent=QModelIndex()) const;
    int columnCount(const QModelIndex &parent=QModelIndex()) const;

private:
     void setupModelData(const QStringList &lines, BuddyItem *parent);

     BuddyItem *m_root;
};

#endif
