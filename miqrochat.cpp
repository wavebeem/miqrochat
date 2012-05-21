/*
 * This file is part of miqrochat.
 */
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

int main(int argc, char **argv) {
    const int padding = 6;
    const int none = 0;

    QApplication app(argc, argv);
    QMainWindow *window = new QMainWindow;

    QStatusBar      *status      = window->statusBar();
    QSplitter       *splitter    = new QSplitter;
    QTreeView       *friendView  = new QTreeView;
    QPlainTextEdit  *messageEdit = new QPlainTextEdit;
    QPlainTextEdit  *chatView    = new QPlainTextEdit;
    QVBoxLayout     *layout      = new QVBoxLayout;
    QWidget         *chatArea    = new QWidget;

    layout->addWidget(messageEdit);
    layout->addWidget(chatView);
    chatArea->setLayout(layout);
    splitter->addWidget(friendView);
    splitter->addWidget(chatArea);

    layout->setSpacing(padding);

    splitter    ->setContentsMargins(padding, padding, padding, padding);
    layout      ->setContentsMargins(none, none, none, none);

    QToolButton *settingsButton = new QToolButton;
    settingsButton->setArrowType(Qt::DownArrow);
    settingsButton->setAutoRaise(true);
    QLabel *statusLabel = new QLabel("Online");
    QLabel *friendLabel = new QLabel("Typing");
    status->addWidget(settingsButton);
    status->addWidget(statusLabel);
    status->addPermanentWidget(friendLabel);

    //window->setCentralWidget(chatArea);
    window->setCentralWidget(splitter);
    window->resize(300, 300);

    window->setWindowTitle("Title");
    window->show();
    return app.exec();
}
