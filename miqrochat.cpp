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

void resizePlainTextEdit(QPlainTextEdit *edit, int rows) {
    QFontMetrics m(edit->font());
    int pad = 12;
    int s = m.lineSpacing();
    int h = pad + rows * s;
    edit->setFixedHeight(h);
    edit->setSizeIncrement(1, s);
}

int main(int argc, char **argv) {
    const int smallPadding = 6;
    QMargins noMargin;
    QMargins smallMargin(smallPadding, smallPadding, smallPadding, smallPadding);

    QApplication app(argc, argv);
    QMainWindow *window = new QMainWindow;

    QStatusBar      *status      = window->statusBar();
    QSplitter       *splitter    = new QSplitter;
    QTreeView       *friendView  = new QTreeView;
    QPlainTextEdit  *messageEdit = new QPlainTextEdit;
    QPlainTextEdit  *chatView    = new QPlainTextEdit;
    QVBoxLayout     *layout      = new QVBoxLayout;
    QWidget         *chatArea    = new QWidget;

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
    status->addPermanentWidget(friendLabel);

    resizePlainTextEdit(messageEdit, 1);

    //window->setCentralWidget(chatArea);
    window->setCentralWidget(splitter);
    window->resize(300, 300);

    window->setWindowTitle("Title");
    window->show();
    return app.exec();
}
