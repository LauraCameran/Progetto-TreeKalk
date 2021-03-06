#ifndef AVLTREE_H
#define AVLTREE_H
#include "binarytree.h"

class AVLTree: public BinaryTree{

public:

    class node: public BinaryTree::nodo{
    public:
        int balance;
        node(Tipo* i = nullptr, nodo* p = nullptr, nodo* l = nullptr, nodo* r = nullptr):BinaryTree::nodo(i, p, l, r), balance(0){}
        ~node(){}
    };

    AVLTree(){}
    AVLTree(const AVLTree&);
    ~AVLTree();

    void insert(Tipo*);
    Tipo* search(const Tipo*) const;
    Tipo* max() const;
    Tipo* min() const;

    // Funzionalità di AVL
    // Trova il primo sottoalbero bilanciato in ordine prefisso
    AVLTree* subtree_preorder();
    //trova il primo sottoalbero bilanciato in ordine "inverso"
    //ovvero guardando prima a dx, poi a sx
    AVLTree* subtree_invertorder();

    void deleteNodo(const Tipo*);


    // Friends
    friend std::ostream& operator<<(std::ostream&, const AVLTree*);


private:

    //Metodi virtuali
    node* copia(nodo*,  nodo* = nullptr);
    void insertNodo(nodo*, Tipo*);
    node* searchNodo(nodo*, const Tipo*) const;
    node* maxNodo(nodo*) const;
    node* minNodo(nodo*) const;
    void print(std::ostream&, nodo*) const;

    // Metodi specifici della classe
    void setBalance(node*);
    node* rotateLeft(node*);
    node* rotateRight(node*);
    node* rotateLeftThenRight(node*);
    node* rotateRightThenLeft(node*);

    void rebalance(node*);
    int height(node*) const;

    //Funzionalità aggiuntive di AVL
    node* invertorder(node*) const;
    node* preorder(node*) const;

    node* succ(node*);


};

#endif // AVLTREE_H
