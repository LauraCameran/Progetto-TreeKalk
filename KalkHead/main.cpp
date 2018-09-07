#include "tabdialog.h"
#include <iostream>
#include <QApplication>
#include <binarysearchtree.h>

using namespace std;

int main(int argc, char *argv[]){


    QApplication app(argc, argv);

//    if (argc >= 2)
//        fileName = argv[1];
//    else
//        fileName = ".";

    TabDialog tabdialog(nullptr);
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
