#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>

#include "ChatHeader.h"

ChatHeader::ChatHeader(QWidget *parent)
: QWidget(parent) {
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(new QLabel("<b>Bobby Pickles</p>"));
    layout->addWidget(new QLineEdit());
    //layout->addStretch();
    layout->addWidget(new QLabel("Typing..."));
    setLayout(layout);
}
