#ifndef TWOTHREETREE_H
#define TWOTHREETREE_H
#include "binarytree.h"

class TwoThreeTree: public BinaryTree{

public:

    class node: public BinaryTree::nodo{
    public:
        Tipo* other;    // Secondo campo info
        int num;        // Tiene conto di quanti campi info
        nodo* middle;
        node(Tipo* i = nullptr, nodo* p = nullptr, nodo* l = nullptr, nodo* r = nullptr, Tipo* o = nullptr, nodo* m = nullptr);
        ~node();
    };

    TwoThreeTree(){}
    TwoThreeTree(const TwoThreeTree&);
    ~TwoThreeTree();

    void insert(Tipo*);
    void deleteNodo(const Tipo*);
    Tipo* search(const Tipo*) const;
    Tipo* max() const;
    Tipo* min() const;

    //Funzionalità aggiuntive di TwoThree
    node* display_other_invertorder() const;
    node* display_other_preorder() const;

    friend std::ostream& operator<<(std::ostream&, const TwoThreeTree*);

private:

    // Distruttore profondo reimplementato
    static void distruggi(nodo*);
    // Contatore dei nodi reimplementato
    static int conta(nodo*);

    node* copia( nodo*, nodo* = nullptr);
    void insertNodo(nodo*, Tipo*);
    node* searchNodo(nodo*, const Tipo*) const;

    node* maxNodo(nodo*) const;
    node* minNodo(nodo*) const;

    void print(std::ostream&, nodo*) const;

    //METODI SPECIFICI DI TWOTHREE
    // Divide i due campi di un nodo, fixando di conseguenza
    // la struttura dell'albero
    void split(node*, Tipo*);

    // Ricerca il campo centrale tra 3(info, other e uno in input)
    Tipo* searchMiddle(node*, Tipo*);

    // return 1 se esiste figlio sx
    // return 2 se figlio centrale
    // return 3 se figlio dx
    int child(node*) const;
    void addInfo(node*, Tipo*); //aggiunge il secondo campo info

    // Toglie il secondo campo info
    void removeOther(node*);
    // se foglia return true
    bool leaf(node*) const;

    //node 3-node nel sottoalbero dx
    node* invertorder(node*) const;
    //node 3-node nel sottoalbero sx
    node* preorder(node*) const;
};

#endif // TWOTHREETREE_H
