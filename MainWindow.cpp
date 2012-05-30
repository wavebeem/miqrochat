#include "MainWindow.h"
#include "Util.h"

MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent) {
    m_statusBar      = statusBar();
    m_settingsButton = new QToolButton;
    m_statusLabel    = new QLabel("user@host.com (Online)");
    m_mainSplitter   = new MainSplitter;

    m_settingsButton->setArrowType(Qt::DownArrow);
    m_settingsButton->setAutoRaise(true);

    m_statusBar->addWidget(m_settingsButton);
    m_statusBar->addWidget(m_statusLabel);

    setStyleSheet(Util::readFile("resources/widgets.qss"));

    setCentralWidget(m_mainSplitter);
    resize(500, 500);

    setWindowTitle("Title");
}
