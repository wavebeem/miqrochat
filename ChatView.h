#ifndef CHATVIEW_H
#define CHATVIEW_H

#include <QWebView>

class ChatView: public QWebView {
Q_OBJECT
public:
    explicit ChatView(QWidget *parent=0);
};

#endif
