#include "visualizer3d.h"
#include "qtscenedrawer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Visualizer3D w;
    w.show();
    return a.exec();
}
