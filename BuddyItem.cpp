#include "BuddyItem.h"

BuddyItem::BuddyItem(const QList<QVariant> &data, BuddyItem *parent, bool isGroup) {
    m_isGroup = isGroup;
    m_parent  = parent;
    m_items   = data;
}

BuddyItem::~BuddyItem() {
    qDeleteAll(m_children);
}

void BuddyItem::appendChild(BuddyItem *item) {
    m_children.append(item);
}

BuddyItem *BuddyItem::child(int row) {
    return m_children.value(row);
}

int BuddyItem::childCount() const {
    return m_children.count();
}

int BuddyItem::row() const {
    if (m_parent)
        return m_parent->m_children.indexOf(const_cast<BuddyItem *>(this));

    return 0;
}

int BuddyItem::columnCount() const {
    return m_items.count();
}

QVariant BuddyItem::data(int column) const {
    return m_items.value(column);
}

BuddyItem *BuddyItem::parent() {
    return m_parent;
}

bool BuddyItem::isGroup() const {
    return m_isGroup;
}
