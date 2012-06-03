#include "Group.h"

Group::Group(const QString &name):
m_name(name) {
}

void Group::rename(const QString &name) {
    m_name = name;
}

QString Group::name() const {
    return m_name;
}
