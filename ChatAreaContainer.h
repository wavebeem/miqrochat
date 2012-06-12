#ifndef CHATAREACONTAINER_H
#define CHATAREACONTAINER_H

#include <QHash>
#include <QString>
#include <QWidget>
#include <QStackedLayout>

#include "ChatArea.h"

class ChatAreaContainer: public QWidget {
Q_OBJECT
public:
    explicit ChatAreaContainer(QWidget *parent=0);

private:
    QStackedLayout *m_layout;
    QHash<QString, ChatArea *> m_chattingWith;

private slots:
    void doSillyStuff();
};

#endif
