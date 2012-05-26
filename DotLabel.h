#ifndef DOTLABEL_H
#define DOTLABEL_H

#include <QResizeEvent>
#include <QString>
#include <QWidget>
#include <QLabel>
#include <QSize>

class DotLabel: public QLabel {
Q_OBJECT
public:
    explicit DotLabel(const QString &text, QWidget *parent=0);
    virtual QSize minimumSizeHint() const;
    virtual QSize sizeHint() const;
    void setText(const QString &);
    QString text() const;

protected:
    void resizeEvent(QResizeEvent *);

private:
    QString m_realText;
};

#endif
