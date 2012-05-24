#ifndef MAINSPLITTER_H
#define MAINSPLITTER_H

#include <QSplitter>
class MainSplitter: public QSplitter {
Q_OBJECT
public:
    explicit MainSplitter(QWidget *parent=0);
};

#endif
