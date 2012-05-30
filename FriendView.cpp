#include "FriendView.h"
#include "BuddiesModel.h"

FriendView::FriendView(QWidget *parent)
: QTreeView(parent) {
    const char *buddies =
"#Online\n"
"Abal\n"
"Abir\n"
"Badra\n"
"Banan\n"
"Cantara\n"
"Daliyah\n"
"Fatima\n"
"Hasibah\n"
"Hayed\n"
"Hijrah\n"
"#Away\n"
"Hubab\n"
"Huma\n"
"Husn\n"
"Inaya\n"
"Insaf\n"
"Jada\n"
"Jana\n"
"Kamilah\n"
"Kulus\n"
"Lamya\n"
"Lunah";
    setHeaderHidden(true);
    setModel(new BuddiesModel(buddies));
    setRootIsDecorated(false);
}

QSize FriendView::sizeHint() const {
    return QSize(150, 0);
}
