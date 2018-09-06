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
#include <QObject>
#include "exception.h"

class TabDialog;
class AvlTab;
class HuffmanTab;
class TwoThreeTab;
class BinarySearchTab;

class Controller: public QObject{

    Q_OBJECT

public:
    Controller(TabDialog* =0);
    void setTree(BinaryTree*);

public slots:
    //generics
    void insertClicked(); //fare i check
    void deleteClicked();
    void searchClicked();
    void maxClicked();
    void minClicked();
    void deleteTreeClicked();
    void showTreeClicked();

    void keepClicked(); //binarys
    void plusClicked(); //binarys
    void minusClicked(); //binarys
    void subTPreClicked();  //AVL
    void subTInvClicked();  //AVL
    void subPreClicked();  //2-3
    void subInvClicked();  //2-3
    void compressClicked(); //huffman

    // creazione di segnali con void
signals:
    void errorInput();
    void secondTreeError();
    void testingHuffman();
    void deleteException();

private:
    TabDialog* window;  //view
    BinaryTree* tree; //model
};

#endif // CONTROLLER_H
