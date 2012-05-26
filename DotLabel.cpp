#include <QFontMetrics>
#include <iostream>
#include "DotLabel.h"

DotLabel::DotLabel(const QString &text, QWidget *parent)
: QLabel(parent) {
    setText(text);
}

void DotLabel::resizeEvent(QResizeEvent *e) {
    setText(m_realText);
}

QSize DotLabel::minimumSizeHint() const {
    QSize s = QLabel::minimumSizeHint();
    s.setWidth(-1);
    return s;
}

QSize DotLabel::sizeHint() const {
    QFontMetrics m(font());
    const int w = m.width(m_realText);
    const int h = QLabel::sizeHint().height();
    return QSize(w, h);
}

void DotLabel::setText(const QString &text) {
    m_realText = text;
    QFontMetrics m(font());
    const QString &t = m.elidedText(text, Qt::ElideRight, width());
    setToolTip(t == text? QString(): text);
    QLabel::setText(t);
}

QString DotLabel::text() const {
    return m_realText;
}
