#include "Buddy.h"

Buddy::Buddy(const QString &nick, const QString &id):
m_nick(nick),
m_id(id) {
}

void Buddy::rename(const QString &nick) {
    m_nick = nick;
}

QString Buddy::nick() const {
    return m_nick;
}

QString Buddy::id() const {
    return m_id;
}
