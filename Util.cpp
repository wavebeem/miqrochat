#include "Util.h"
#include <QFile>

QString Util::readFile(const QString &filename) {
    QFile file(filename);

    return file.open(QIODevice::ReadOnly)
        ? QString(file.readAll())
        : QString();
}
