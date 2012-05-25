#include "FriendView.h"

FriendView::FriendView(QWidget *parent)
: QTreeView(parent) {
}

QSize FriendView::sizeHint() const {
    return QSize(150, 0);
}
