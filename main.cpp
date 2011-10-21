#include <QtGui/QApplication>
#include "map.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    map w;
    w.show();

    return a.exec();
}
