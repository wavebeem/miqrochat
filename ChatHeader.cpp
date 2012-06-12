#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>

#include "ChatHeader.h"
#include "DotLabel.h"
#include "Util.h"

ChatHeader::ChatHeader(QWidget *parent)
: QWidget(parent) {
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(new QLabel("<b>Bobby Pickles</b>"));
    layout->setStretch(0, 0);
    layout->addWidget(new DotLabel(Util::randomString(64)));
    layout->setStretch(1, 1);
    //layout->addStretch();
    QLabel *friendStatus = new QLabel("Typing");
    friendStatus->setObjectName("theFriendStatus");
    layout->addWidget(friendStatus);
    layout->setStretch(2, 0);
    setLayout(layout);
}
