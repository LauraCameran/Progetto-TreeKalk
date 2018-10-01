#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "binarytree.h"
#include "avltree.h"
#include "twothreetree.h"
#include "binarysearchtree.h"
#include "huffmantree.h"
#include "tipo.h"
#include "intero.h"
#include "huffman.h"
#include "tabdialog.h"
#include "exception.h"
#include "node.h"
#include <QObject>

class TabDialog;
class AvlTab;
class HuffmanTab;
class TwoThreeTab;
class BinarySearchTab;

class Controller: public QObject{

    Q_OBJECT

public:
    Controller(TabDialog* = nullptr);
    virtual ~Controller();

public slots:
    //generics
    void insertClicked();
    void deleteClicked();
    void searchClicked();
    void maxClicked();
    void minClicked();
    void deleteTreeClicked();
    void showTreeClicked();

    void keepClicked();
    void plusClicked();
    void minusClicked();
    void subTPreClicked();
    void subTInvClicked();
    void subPreClicked();
    void subInvClicked();
    void compressClicked();

signals:
    void errorInput();
    void secondTreeError();
    void testingHuffman();
    void deleteException();
    void errorNode();
    void errorTree();
    void errorDel();
    void errOrder();
    void errTree();



private:
    TabDialog* window;  //view

};

#endif // CONTROLLER_H
