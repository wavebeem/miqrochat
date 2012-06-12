#ifndef MAINSPLITTER_H
#define MAINSPLITTER_H

#include <QSplitter>

#include "FriendView.h"
#include "ChatAreaContainer.h"

class MainSplitter: public QSplitter {
Q_OBJECT
public:
    explicit MainSplitter(QWidget *parent=0);

private:
    FriendView          *m_friendView;
    ChatAreaContainer   *m_chatAreaC;
};

#endif
