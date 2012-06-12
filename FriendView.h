#ifndef FRIENDVIEW_H
#define FRIENDVIEW_H

#include <QTreeView>
#include <QPoint>
#include <QSize>

class FriendView: public QTreeView {
Q_OBJECT
public:
    explicit FriendView(QWidget *parent=0);
    virtual QSize sizeHint() const;

public slots:
    void showContextMenu(const QPoint &);

protected slots:
    virtual void currentChanged(const QModelIndex &current, const QModelIndex &previous);
};

#endif
