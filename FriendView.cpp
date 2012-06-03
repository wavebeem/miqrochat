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
    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, SIGNAL(customContextMenuRequested(const QPoint &)),
            this, SLOT(showContextMenu(const QPoint &)));
}

void FriendView::showContextMenu(const QPoint &p) {
    qDebug() << "Clicked at:" << p;
    QModelIndex index = indexAt(p);
    if (index.isValid()) {
        QMenu actions;
        QAction *username = actions.addAction("username@host.com");
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
