#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "tipo.h"
#include "intero.h"
#include "exception.h"

class BinaryTree{

public:

    class nodo{
    public:
        Tipo* info;
        nodo *parent, *left, *right;
        nodo():info(),parent(nullptr),left(nullptr),right(nullptr){}
        nodo(Tipo* i, nodo* p = nullptr, nodo* sx = nullptr, nodo* dx = nullptr):info(i), parent(p), left(sx), right(dx){}
        virtual ~nodo();
    };

    //PER GUI
    int max_depth() const;
    virtual int height(nodo*) const;
    nodo* returnRoot() const;
    void elimTree();

    virtual ~BinaryTree(){}
    BinaryTree():root(nullptr){}

    virtual void insert(Tipo*) =0;
    virtual Tipo* search(const Tipo*) const =0;
    virtual Tipo* max() const =0;
    virtual Tipo* min() const =0;

    virtual BinaryTree& operator =(const BinaryTree&);

    virtual void deleteNodo(const Tipo*) =0;
    virtual bool empty() const;
    friend std::ostream& operator <<(std::ostream& os, const BinaryTree* t){
        t->print(os, t->root);
        return os;
    }

protected:
    nodo* root;

    // Distruttore profondo
    virtual void distruggi(nodo*);
    // Contatore dei nodi
    virtual int conta(nodo*);
    // Redifinizione del metodo a seconda dei campi dati da copiare
    virtual nodo* copia(nodo*, nodo* = nullptr) =0;
    // Search basata sul parametro che si vuole
    virtual nodo* searchNodo(nodo*, const Tipo*) const =0;

    virtual void print(std::ostream&, nodo*) const =0;

};

#endif // BINARYTREE_H
