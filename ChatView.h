#ifndef CHATVIEW_H
#define CHATVIEW_H

#include <QPlainTextEdit>

class ChatView: public QPlainTextEdit {
Q_OBJECT
public:
    explicit ChatView(QWidget *parent=0);
};

#endif
