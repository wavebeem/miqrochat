#include <QMargins>
#include "MainSplitter.h"

MainSplitter::MainSplitter(QWidget *parent)
: QSplitter(parent) {
    const int smallPadding = 6;
    QMargins smallMargin(6, 6, 6, 6);

    m_friendView = new FriendView;
    m_chatAreaC  = new ChatAreaContainer;

    addWidget(m_friendView);
    addWidget(m_chatAreaC);
    setHandleWidth(smallPadding);

    setContentsMargins(smallMargin);

    setStretchFactor(0, 0);
    setStretchFactor(1, 1);
}
