#include "mainwindow.h"
#include <QApplication>
#include <QSharedMemory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSharedMemory sharedMem(qApp->applicationName());
    if(sharedMem.attach())
        return 0;
    else
        sharedMem.create(1);
    MainWindow w;
    w.show();
    w.initMainWindow();
    a.exec();
    sharedMem.detach();
    return 0;
}
