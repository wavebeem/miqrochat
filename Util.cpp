#include "Util.h"
#include <QFile>
#include <cstdlib>

QString Util::readFile(const QString &filename) {
    QFile file(filename);

    return file.open(QIODevice::ReadOnly)
        ? QString(file.readAll())
        : QString();
}

QString Util::randomString(int length) {
    QString str;
    int i = length;

    while (i --> 0) {
        str += 'a' + rand() % 26;
    }

    return str;
}
