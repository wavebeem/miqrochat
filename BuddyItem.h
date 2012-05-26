#ifndef BUDDYITEM_H
#define BUDDYITEM_H

#include <QList>
#include <QVariant>

class BuddyItem {
public:
    BuddyItem(const QList<QVariant> &data, BuddyItem *parent=0);
    ~BuddyItem();

    void appendChild(BuddyItem *child);

    BuddyItem *child(int row);
    int childCount() const;
    int columnCount() const;
    QVariant data(int column) const;
    int row() const;
    BuddyItem *parent();

private:
    QList<BuddyItem *> m_children;
    QList<QVariant>    m_items;
    BuddyItem *m_parent;
};

#endif
