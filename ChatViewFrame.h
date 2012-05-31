#ifndef CHATVIEWFRAME_H
#define CHATVIEWFRAME_H

#include <QFrame>
#include <QWidget>
#include "ChatView.h"

class ChatViewFrame: public QFrame {
Q_OBJECT
public:
    explicit ChatViewFrame(QWidget *parent=0);

private:
    ChatView *m_chatView;
};

#endif
