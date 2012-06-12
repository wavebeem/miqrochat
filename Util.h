#ifndef UTIL_H
#define UTIL_H

#include <QString>

namespace Util {
    QString readFile(const QString &filename);

    template<class T>
    T clamp(T x, T a, T b) {
        if (x < a) return a;
        if (x > b) return b;
        /* else */ return x;
    }

    QString randomString(int length);
}

#endif
