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

#include <iostream>

#include "MessageEdit.h"
#include "ChatHeader.h"

int main(int argc, char **argv) {
    const int smallPadding = 6;
    QMargins noMargin;
    QMargins smallMargin(smallPadding, smallPadding, smallPadding, smallPadding);

    QApplication app(argc, argv);
    QMainWindow *window = new QMainWindow;

    QStatusBar      *status      = window->statusBar();
    ChatHeader      *chatHeader  = new ChatHeader;
    QSplitter       *splitter    = new QSplitter;
    QTreeView       *friendView  = new QTreeView;
    QPlainTextEdit  *messageEdit = new MessageEdit;
    QPlainTextEdit  *chatView    = new QPlainTextEdit;
    QVBoxLayout     *layout      = new QVBoxLayout;
    QWidget         *chatArea    = new QWidget;

    layout->addWidget(chatHeader);
    layout->addWidget(chatView);
    layout->addWidget(messageEdit);
    chatArea->setLayout(layout);
    splitter->addWidget(friendView);
    splitter->addWidget(chatArea);
    splitter->setHandleWidth(smallPadding);

    layout->setSpacing(smallPadding);

    splitter->setContentsMargins(smallMargin);
    layout  ->setContentsMargins(noMargin);

    QToolButton *settingsButton = new QToolButton;
    settingsButton->setArrowType(Qt::DownArrow);
    settingsButton->setAutoRaise(true);
    QLabel *statusLabel = new QLabel("Online");
    QLabel *friendLabel = new QLabel("Typing");
    status->addWidget(settingsButton);
    status->addWidget(statusLabel);
    //status->addPermanentWidget(friendLabel);

    //window->setCentralWidget(chatArea);
    window->setCentralWidget(splitter);
    window->resize(300, 300);

    window->setWindowTitle("Title");
    window->show();
    return app.exec();
}
