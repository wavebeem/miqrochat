#include <QApplication>
#include <QPushButton>
#include <QToolButton>
#include <QTreeView>
#include <QSplitter>
#include <QLabel>
#include <QMainWindow>
#include <QStatusBar>
#include <QHBoxLayout>
#include <QSpacerItem>

int main(int argc, char **argv) {
    QApplication app(argc, argv);
    QMainWindow window;

    QSplitter splitter;
    QTreeView   friendView;
    QPushButton b2("Chat");
    QStatusBar *status = window.statusBar();
    //status->showMessage("Status");
    splitter.addWidget(&friendView);
    splitter.addWidget(&b2);

    const int padding = 3;
    splitter.setContentsMargins(padding, padding, padding, padding);

    QToolButton settingsButton;
    settingsButton.setArrowType(Qt::DownArrow);
    settingsButton.setAutoRaise(true);
    QLabel statusLabel("Online");
    QLabel friendLabel("Typing");
    //status->addPermanentWidget(&settingsButton);
    status->addWidget(&settingsButton);
    status->addWidget(&statusLabel);
    status->addPermanentWidget(&friendLabel);

    window.setCentralWidget(&splitter);
    window.resize(300, 300);

    window.setWindowTitle("Title");
    window.show();
    return app.exec();
}
