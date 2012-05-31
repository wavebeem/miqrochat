#include <QHBoxLayout>
#include <QMargins>

#include "ChatViewFrame.h"
#include "ChatView.h"

ChatViewFrame::ChatViewFrame(QWidget *parent)
: QFrame(parent) {
    setObjectName("theChatViewFrame");

    setFrameStyle(QFrame::Box | QFrame::Raised);
    setLineWidth(1);

    const int p = 1;
    QMargins margins(p, p, p, p);

    m_chatView = new ChatView;
    QHBoxLayout *layout = new QHBoxLayout;

    setContentsMargins(margins);
    layout->setContentsMargins(QMargins());
    layout->setMargin(0);
    layout->setSpacing(0);
    layout->addWidget(m_chatView);

    setLayout(layout);
}
