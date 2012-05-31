#include "ChatArea.h"

ChatArea::ChatArea(QWidget *parent)
: QWidget(parent) {
    const int smallPadding = 6;
    QMargins noMargin;

    m_messageEdit   = new MessageEdit;
    m_chatHeader    = new ChatHeader;
    m_chatViewFrame = new ChatViewFrame;
    m_layout        = new QVBoxLayout;

    m_layout->addWidget(m_chatHeader);
    m_layout->addWidget(m_chatViewFrame);
    m_layout->addWidget(m_messageEdit);


    m_layout->setSpacing(smallPadding);
    m_layout->setContentsMargins(noMargin);

    setLayout(m_layout);
}
