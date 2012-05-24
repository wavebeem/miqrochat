#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent) {
    m_statusBar      = statusBar();
    m_settingsButton = new QToolButton;
    m_statusLabel    = new QLabel("Online");
    m_mainSplitter   = new MainSplitter;

    m_settingsButton->setArrowType(Qt::DownArrow);
    m_settingsButton->setAutoRaise(true);

    m_statusBar->addWidget(m_settingsButton);
    m_statusBar->addWidget(m_statusLabel);

    setCentralWidget(m_mainSplitter);
    resize(300, 300);

    setWindowTitle("Title");
}
