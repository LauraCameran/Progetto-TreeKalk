#include "tabdialog.h"
#include <iostream>
#include <QApplication>

using namespace std;
/*
int main(int argc, char *argv[]){

    QApplication app(argc, argv);

    TabDialog tabdialog(nullptr);
    tabdialog.show();

    return app.exec();
}
*/
int main(int argc, char *argv[]){

   BinaryTree* t = new TwoThreeTree();
   Tipo* ti = new Intero(4);
   Tipo* ti2 = new Intero(1);
   Tipo* ti3 = new Intero(3);
   t->insert(ti);
   t->insert(ti2);
   t->insert(ti3);
   cout<<t<<endl;
   t->deleteNodo(ti2);
   cout<<t<<endl;
}
