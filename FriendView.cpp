#include "FriendView.h"
#include "BuddiesModel.h"

FriendView::FriendView(QWidget *parent)
: QTreeView(parent) {
    const char *buddies =
"foo\n"
"foo\n"
"foo\n"
"foo\n"
"foo\n"
"foo\n"
"foo\n"
"foo\n"
"foo\n"
"foo";
    setHeaderHidden(true);
    setModel(new BuddiesModel(buddies));
}

QSize FriendView::sizeHint() const {
    return QSize(150, 0);
}
