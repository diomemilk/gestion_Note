#include "flowcontroller.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FlowController w;
    w.exec();
    return a.exec();
}
