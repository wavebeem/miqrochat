#ifndef MAINSPLITTER_H
#define MAINSPLITTER_H

#include <QSplitter>

#include "FriendView.h"
#include "ChatArea.h"

class MainSplitter: public QSplitter {
Q_OBJECT
public:
    explicit MainSplitter(QWidget *parent=0);

private:
    FriendView *m_friendView;
    ChatArea   *m_chatArea;
};

#endif
