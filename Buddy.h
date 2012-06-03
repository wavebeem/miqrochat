#ifndef BUDDY_H
#define BUDDY_H

#include <QString>

class Buddy {
public:
    explicit Buddy(const QString &nick, const QString &id);
    void rename(const QString &nick);
    QString nick() const;
    QString id() const;

private:
    QString m_nick;
    QString m_id;
};

#endif
