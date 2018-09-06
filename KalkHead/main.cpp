#include "tabdialog.h"
#include <iostream>
#include <QApplication>
using namespace std;

int main(int argc, char *argv[]){



    QApplication app(argc, argv);
    QString fileName;

    if (argc >= 2)
        fileName = argv[1];
    else
        fileName = ".";

    TabDialog tabdialog(fileName);
    tabdialog.show();

    return app.exec();

}


/*
#include "window.h"

#include <QApplication>
#include <QDebug>

using namespace std;

int main(int argc, char **argv){
    QApplication app(argc, argv);

    Window w;
    w.show();

    return app.exec();
}
*/
