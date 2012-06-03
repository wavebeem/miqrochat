#include "BuddyItem.h"

BuddyItem::BuddyItem(Buddy *buddy, BuddyItem *parent):
m_buddy(buddy),
m_group(0),
m_parent(parent) {
}

BuddyItem::BuddyItem(Group *group, BuddyItem *parent):
m_buddy(0),
m_group(group),
m_parent(parent) {
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

void BuddyItem::callMeIshmael() {
    if (m_buddy)
        m_buddy->rename("ISHMAEL");
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
    return 1;
}

QVariant BuddyItem::data(int /*column*/) const {
    if (m_buddy) return m_buddy->nick();
    if (m_group) return m_group->name();
    return QVariant();
}

BuddyItem *BuddyItem::parent() const {
    return m_parent;
}

Buddy *BuddyItem::buddy() const {
    return m_buddy;
}

Group *BuddyItem::group() const {
    return m_group;
}
