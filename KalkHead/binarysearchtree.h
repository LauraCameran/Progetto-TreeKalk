#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include "binarytree.h"

class BinarySearchTree: public BinaryTree{

private:

    nodo* succ(const nodo*) const;
    nodo* pred(const nodo*) const;

    nodo* copia( nodo*,  nodo* = nullptr);
    void insertNodo(nodo*, Tipo*);
    nodo* searchNodo(nodo*, const Tipo*) const;

    // non fa side-effect sull'oggetto di invocazione
    nodo* somma(const nodo*, const nodo*, nodo* p) const;
    nodo* sottrazione(const nodo*, const nodo*) const;

    nodo* maxNodo(nodo*) const;
    nodo* minNodo(nodo*) const;

    void print(std::ostream&, nodo*) const;

public:

    BinarySearchTree(){}
    ~BinarySearchTree();
    BinarySearchTree(const BinarySearchTree&);

    void insert(Tipo*);
    Tipo* search(const Tipo*) const;
    Tipo* max() const;
    Tipo* min() const;

    // Assegnazione virtuale
    BinarySearchTree& operator=(const BinaryTree&);

    // Operatori
    BinarySearchTree* operator+(const BinarySearchTree*) const;
    BinarySearchTree* operator-(const BinarySearchTree*) const;

    // metoodo per cancellare un singolo nodo;
    void deleteNodo(const Tipo*);

    friend std::ostream& operator<<(std::ostream&, const BinarySearchTree*);
};

#endif // BINARYSEARCHTREE_H
