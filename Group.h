#ifndef GROUP_H
#define GROUP_H

#include <QString>

class Group {
public:
    explicit Group(const QString &name);
    void rename(const QString &name);
    QString name() const;

private:
    QString m_name;
};

#endif
