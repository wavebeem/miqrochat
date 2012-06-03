#include "MessageEdit.h"
#include "Util.h"
#include <QDebug>

MessageEdit::MessageEdit(QWidget *parent)
: QPlainTextEdit(parent) {
    setLineCount(1);
    connect(this, SIGNAL(textChanged()), this, SLOT(sizeToFit()));
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void MessageEdit::sizeToFit() {
    QSize size = document()->documentLayout()->documentSize().toSize();
    setLineCount(size.height());
}

void MessageEdit::setLineCount(int requestedRows) {
    const int max = 3;
    const int min = 1;
    const int rows = Util::clamp(requestedRows, min, max);
    QFontMetrics m(font());
    int pad = m.lineSpacing();
    int s = m.lineSpacing();
    int h = pad + rows * s;
    setFixedHeight(h);
}
