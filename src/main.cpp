#include "tooltip.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    tooltip w;
    w.show();

    return app.exec();
}

