#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_minBtn_clicked();

    void on_closeBtn_clicked();

    void on_testBtn_clicked();

    void on_programBtn_clicked();

    void on_reportBtn_clicked();

    void on_settingBtn_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
