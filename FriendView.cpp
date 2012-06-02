#include "FriendView.h"
#include "BuddiesModel.h"
#include "Util.h"

#include <QList>
#include <QMenu>
#include <QAction>
#include <QDebug>

FriendView::FriendView(QWidget *parent)
: QTreeView(parent) {
    QString buddies = Util::readFile("resources/buddies.txt");
    setHeaderHidden(true);
    setModel(new BuddiesModel(buddies));
    setRootIsDecorated(false);
    setIndentation(10);
    expandAll();

    connect(this, SIGNAL(customContextMenuRequested(const QPoint &)),
            this, SLOT(showContextMenu(const QPoint &)));
}

void FriendView::showContextMenu(const QPoint &p) {
    qDebug() << "Clicked at:" << p;
    QModelIndex index = indexAt(p);
    if (index.isValid()) {
        QList<QAction *> actions;
        actions << new QAction("Chat", this);
        actions << new QAction("Rename", this);
        actions << new QAction("Remove", this);
        QAction *action = QMenu::exec(actions, mapToGlobal(p), actions[0], this);
        if (action) {
            qDebug() << "Selected action:" << action->text();
        }
    }
}

QSize FriendView::sizeHint() const {
    return QSize(150, 0);
}
