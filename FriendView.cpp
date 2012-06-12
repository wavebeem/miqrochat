#include "FriendView.h"
#include "BuddiesModel.h"
#include "Util.h"

#include <QList>
#include <QMenu>
#include <QDebug>
#include <QAction>
#include <QModelIndex>

FriendView::FriendView(QWidget *parent)
: QTreeView(parent) {
    QString buddies = Util::readFile("resources/buddies.txt");
    setHeaderHidden(true);
    setModel(new BuddiesModel(buddies));
    setRootIsDecorated(false);
    setIndentation(10);
    expandAll();
    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, SIGNAL(customContextMenuRequested(const QPoint &)),
            this, SLOT(showContextMenu(const QPoint &)));
}

void FriendView::showContextMenu(const QPoint &p) {
    qDebug() << "Clicked at:" << p;
    QModelIndex index = indexAt(p);
    if (index.isValid()) {
        QMenu actions;
        BuddyItem *item = (BuddyItem *)index.internalPointer();
        if (item->group())
            return;

        QAction *username = actions.addAction(item->buddy()->id());
        actions.addSeparator();
        actions.addAction("Chat");
        actions.addAction("Rename");
        actions.addAction("Remove");

        username->setDisabled(true);

        QAction *action = actions.exec(mapToGlobal(p));

        if (action) {
            qDebug() << "Selected action:" << action->text();
        }
    }
}

QSize FriendView::sizeHint() const {
    return QSize(150, 0);
}

void FriendView::currentChanged(const QModelIndex &cur, const QModelIndex & /*prev*/) {
    if (cur.isValid()) {
        BuddyItem *item = (BuddyItem *)cur.internalPointer();
        if (item->buddy()) {
            Buddy *bud = item->buddy();
            qDebug() << "Selected the following buddy:" << bud->nick() << bud->id();
        }
    }
}
