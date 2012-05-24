#include <QApplication>
#include <QPushButton>
#include <QToolButton>
#include <QPlainTextEdit>
#include <QTreeView>
#include <QSplitter>
#include <QLabel>
#include <QMainWindow>
#include <QStatusBar>
#include <QVBoxLayout>
#include <QSpacerItem>

#include "MainSplitter.h"
#include "MessageEdit.h"
#include "MainWindow.h"
#include "FriendView.h"
#include "ChatHeader.h"
#include "ChatArea.h"
#include "ChatView.h"

int main(int argc, char **argv) {
    QApplication app(argc, argv);
    QMainWindow *window = new MainWindow;
    window->show();
    return app.exec();
}
