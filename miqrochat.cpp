#include <QApplication>
#include <QMainWindow>

#include "MainWindow.h"

int main(int argc, char **argv) {
    QApplication app(argc, argv);
    QMainWindow *window = new MainWindow;
    window->show();
    return app.exec();
}
