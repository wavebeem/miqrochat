#ifndef FRIENDVIEW_H
#define FRIENDVIEW_H

#include <QTreeView>

class FriendView: public QTreeView {
Q_OBJECT
public:
    explicit FriendView(QWidget *parent=0);
};

#endif
