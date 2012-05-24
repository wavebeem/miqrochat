#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolButton>
#include <QStatusBar>
#include <QWidget>
#include <QLabel>

#include "MainSplitter.h"

class MainWindow: public QMainWindow {
Q_OBJECT
public:
    explicit MainWindow(QWidget *parent=0);

private:
    MainSplitter *m_mainSplitter;
    QToolButton  *m_settingsButton;
    QStatusBar   *m_statusBar;
    QLabel       *m_statusLabel;
};

#endif
