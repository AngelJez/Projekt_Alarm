#include <iostream>
#include "typekey.h"
#include <QApplication>
#include <wiringPi.h>

using namespace std;

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    TypeKey w;
    w.show();

    return a.exec();
}
