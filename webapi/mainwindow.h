#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "postthread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

enum class RequestState{
    ENM_REQUEST_OK = 0,
    ENM_REQUEST_WAIT,
    ENM_REQUEST_TIMEOUT,
    ENM_REQUEST_ERROR
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void init(int p_timeOut);
    int getRequestState();

private slots:
    void slotResult();

private:
    Ui::MainWindow *ui;
    QTimer *m_TimeoutTimer;
    RequestState m_RequestState;
    PostThread *m_post;
};
#endif // MAINWINDOW_H
