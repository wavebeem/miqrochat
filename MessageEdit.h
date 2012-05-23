#ifndef MESSAGEEDIT_H
#define MESSAGEEDIT_H

#include <QPlainTextEdit>

class MessageEdit: public QPlainTextEdit { Q_OBJECT
public:
    explicit MessageEdit(QWidget *parent=0);

private:
    void setLineCount(int lines);

signals:
public slots:
    void sizeToFit();
};

#endif // MESSAGEEDIT_H
