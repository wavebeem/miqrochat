#ifndef BUDDYITEM_H
#define BUDDYITEM_H

#include "Buddy.h"
#include "Group.h"

#include <QList>
#include <QVariant>

class BuddyItem {
public:
    explicit BuddyItem(Buddy *, BuddyItem *parent=0);
    explicit BuddyItem(Group *, BuddyItem *parent=0);
    ~BuddyItem();

    void appendChild(BuddyItem *child);

    BuddyItem *child(int row);
    int childCount() const;
    int columnCount() const;
    QVariant data(int column) const;
    int row() const;
    void callMeIshmael();

    BuddyItem *parent() const;

    Group *group() const;
    Buddy *buddy() const;

private:
    QList<BuddyItem *> m_children;
    BuddyItem *m_parent;
    Buddy *m_buddy;
    Group *m_group;
    bool m_is_Group;
};

#endif
