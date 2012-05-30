 #include "BuddiesModel.h"
 #include <QFont>

 BuddiesModel::BuddiesModel(const QString &data, QObject *parent)
 : QAbstractItemModel(parent) {
     QList<QVariant> rootData;
     rootData << "Buddies";
     m_root = new BuddyItem(rootData);
     setupModelData(data.split("\n"), m_root);
 }

BuddiesModel::~BuddiesModel() {
    delete m_root;
}

QModelIndex BuddiesModel::index(int row, int column, const QModelIndex &parent) const {
    if (!hasIndex(row, column, parent))
        return QModelIndex();

    BuddyItem *parentItem;

    if (! parent.isValid())
        parentItem = m_root;
    else
        parentItem = static_cast<BuddyItem *>(parent.internalPointer());

    BuddyItem *childItem = parentItem->child(row);

    if (childItem)
        return createIndex(row, column, childItem);
    else
        return QModelIndex();
}

QModelIndex BuddiesModel::parent(const QModelIndex &index) const
{
    if (! index.isValid())
        return QModelIndex();

    BuddyItem *childItem = static_cast<BuddyItem*>(index.internalPointer());
    BuddyItem *parentItem = childItem->parent();

    if (parentItem == m_root)
        return QModelIndex();

    return createIndex(parentItem->row(), 0, parentItem);
}

int BuddiesModel::rowCount(const QModelIndex &parent) const {
    BuddyItem *parentItem;
    if (parent.column() > 0)
        return 0;

    if (! parent.isValid())
        parentItem = m_root;
    else
        parentItem = static_cast<BuddyItem *>(parent.internalPointer());

    return parentItem->childCount();
}

int BuddiesModel::columnCount(const QModelIndex &parent) const {
    if (parent.isValid())
        return static_cast<BuddyItem *>(parent.internalPointer())->columnCount();
    else
        return m_root->columnCount();
}

QVariant BuddiesModel::data(const QModelIndex &index, int role) const {
    BuddyItem *item = static_cast<BuddyItem *>(index.internalPointer());

    if (role == Qt::FontRole && item && item->isGroup()) {
        QFont font;
        font.setBold(true);
        return QVariant(font);
    }

    if (! index.isValid())
        return QVariant();

    if (role != Qt::DisplayRole)
        return QVariant();

    return item->data(index.column());
}

Qt::ItemFlags BuddiesModel::flags(const QModelIndex &index) const {
    if (! index.isValid())
        return 0;

    return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

QVariant BuddiesModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        return m_root->data(section);

    return QVariant();
}

void BuddiesModel::setupModelData(const QStringList &list, BuddyItem *root) {
    BuddyItem *parent = root;
    BuddyItem *item = 0;
    foreach (const QString &str, list) {
        QList<QVariant> data;
        if (str.startsWith("#")) {
            data << str.mid(1);
            parent = root;
            item   = new BuddyItem(data, parent, true);
            parent->appendChild(item);
            parent = item;
        }
        else {
            data << str;
            item = new BuddyItem(data, parent);
            parent->appendChild(item);
        }
    }
}
