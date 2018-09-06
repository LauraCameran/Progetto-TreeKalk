#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "tipo.h"
#include "intero.h"
#include "exception.h"

#include "node.h"

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
    // Non serve il costruttore se non si può instanziare una classe virtuale pura
    // Se tolgo il costruttore errore run-time
    BinaryTree():root(nullptr){}

    // Aggiungo assegnazione virtuale
    // Assegnazione virtuale che deve essere controllata
    // dalle classe figlie con RTTI

    virtual void insert(Tipo*) =0;
    virtual Tipo* search(const Tipo*) const =0;
    virtual Tipo* max() const =0;
    virtual Tipo* min() const =0;

    virtual BinaryTree& operator =(const BinaryTree&);

    // Delete un singolo nodo virtuale poiche le operazioni di delete possono
    // cambiare a seconda della struttura dell'albero. Es Alberi Rossi/Neri
    virtual void deleteNodo(const Tipo*) =0;

    friend std::ostream& operator <<(std::ostream& os, const BinaryTree* t){
        t->print(os, t->root);
        return os;
    }

protected:
    nodo* root;

    // Distruttore profondo
    static void distruggi(nodo*);
    // Contatore dei nodi
    static int conta(nodo*);

    // Redifinizione del metodo a seconda dei campi dati da copiare
    virtual nodo* copia(nodo*, nodo* = nullptr) =0;
    // Inserimento new nodo
//    virtual void insertNodo(nodo*, Tipo*) =0;
    // Search basata sul parametro che si vuole
    virtual nodo* searchNodo(nodo*, const Tipo*) const =0;

    virtual void print(std::ostream&, nodo*) const =0;




};

#endif // BINARYTREE_H
