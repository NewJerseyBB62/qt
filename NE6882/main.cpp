#include "mainwindow.h"
#include <QApplication>
#include <QSharedMemory>

int main(int argc, char *argv[])
{
    QSharedMemory shareMem;
    shareMem.setKey("NE6882");
    if(shareMem.attach())
        return 0;
    if(shareMem.create(1))
    {
        QApplication a(argc, argv);
        MainWindow w;
        w.show();
        return a.exec();
    }
    return 0;
}
