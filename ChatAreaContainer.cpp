#include "ChatAreaContainer.h"
#include <QTimer>
#include <cstdlib>

ChatAreaContainer::ChatAreaContainer(QWidget *parent):
QWidget(parent) {
    m_layout = new QStackedLayout;

    for (int i = 0; i < 4; i++) {
        ChatArea *chat = new ChatArea;
        QString str('A' + i);
        m_chattingWith[str] = chat;
        m_layout->addWidget(chat);
    }

    setLayout(m_layout);
    QTimer::singleShot(500, this, SLOT(doSillyStuff()));
}

void ChatAreaContainer::doSillyStuff() {
    m_layout->setCurrentIndex(rand() % m_layout->count());
    QTimer::singleShot(500, this, SLOT(doSillyStuff()));
}
