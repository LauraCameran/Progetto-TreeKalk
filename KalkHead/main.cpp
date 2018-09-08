#include "tabdialog.h"
#include <iostream>
#include <QApplication>

using namespace std;

int main(int argc, char *argv[]){

    QApplication app(argc, argv);

    TabDialog tabdialog(nullptr);
    tabdialog.show();

    return app.exec();
}
