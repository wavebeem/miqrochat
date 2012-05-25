#ifndef FRIENDVIEW_H
#define FRIENDVIEW_H

#include <QTreeView>
#include <QSize>

class FriendView: public QTreeView {
Q_OBJECT
public:
    explicit FriendView(QWidget *parent=0);
    virtual QSize sizeHint() const;
};

#endif
