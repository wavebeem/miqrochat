#ifndef CHATAREA_H
#define CHATAREA_H

#include <QWidget>
#include <QVBoxLayout>

#include "ChatView.h"
#include "ChatHeader.h"
#include "MessageEdit.h"

class ChatArea: public QWidget {
Q_OBJECT
public:
    explicit ChatArea(QWidget *parent=0);

private:
    ChatView    *m_chatView;
    MessageEdit *m_messageEdit;
    QVBoxLayout *m_layout;
    ChatHeader  *m_chatHeader;
};

#endif
