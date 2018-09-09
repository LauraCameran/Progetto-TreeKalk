#include "binarysearchtree.h"
#include "intero.h"
#include <typeinfo>

BinarySearchTree::~BinarySearchTree(){
    distruggi(root);
}


BinarySearchTree::BinarySearchTree(const BinarySearchTree& t){
    root = copia(t.root);
}


// Controllo che il tipo di root sia uguale a quello da inserire.
void BinarySearchTree::insert(Tipo* t){
    if(root){
        if(!(typeid(root->info) == typeid(t)))
            throw new BadTypeValue();

        insertNodo(root, t->copia());
    }
    else
        root = new BinarySearchTree::nodo(t->copia());
}

void BinarySearchTree::insertNodo(nodo* x, Tipo* t){
    if(x){
        if(t->operator <(x->info)){
            if(x->left){
                insertNodo(x->left, t);
            }
            else{

                x->left = new BinarySearchTree::nodo(t, x);

            }
        }
        else{
            if(x->right){
                insertNodo(x->right, t);
            }
            else {
                x->right = new BinarySearchTree::nodo(t, x);
            }
        }
    }
}

// copia profonda dei nodi di un albero
BinarySearchTree::nodo* BinarySearchTree::copia(nodo* t, nodo* p){
    if(t){
        BinarySearchTree::nodo* x = new nodo(t->info->copia(), p);
        x->left = copia(t->left, x);
        x->right = copia(t->right, x);
        return x;
    }
    else
        return nullptr;
}

// delete di un nodo senza ritorno del nodo eliminato
void BinarySearchTree::deleteNodo(const Tipo* t){
    BinarySearchTree::nodo* x = nullptr;
    BinarySearchTree::nodo* y = nullptr;
    BinarySearchTree::nodo* z = searchNodo(root, t);

    if(!z)
        throw new NodeNotFound();

    if(z->left == nullptr || z->right == nullptr)
        y = z;
    else
        y = succ(z);

    if(y->left != nullptr)
        x = y->left;
    else
        x = y->right;

    if(x != nullptr)
        x->parent = y->parent;

    if(y->parent == nullptr)
        root = x;
    else if(y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;

    if(y != z)
        z->info = y->info;

    delete y;

}
// ricerca di un nodo sull'albero ricorsivamente tramite chiave
BinarySearchTree::nodo* BinarySearchTree::searchNodo(nodo* x, const Tipo* t) const{
    if(!x)
        return nullptr;

    if(x->info->operator==(t))
        return x;

    if(t->operator<(x->info))
        return searchNodo(x->left, t);
    else
        return searchNodo(x->right, t);

}

Tipo* BinarySearchTree::search(const Tipo* t) const{
    //if(!(typeid(root->info) == typeid(t)))
    //    throw new BadTypeValue();

    BinarySearchTree::nodo* p = searchNodo(root, t);
    if(!p)
        throw new NodeNotFound();
    Tipo* ret = p->info->copia();
    return ret;
}

void BinarySearchTree::print(std::ostream& os, nodo* x) const{
    if(x){
        x->info->print(os);
        os << "(";
        print(os, x->left);
        os << ",";
        print(os, x->right);
        os << ")";
    }
    else{
        os << "_";
    }
}

BinarySearchTree::nodo* BinarySearchTree::maxNodo(nodo* x) const{
    if(x->right != nullptr)
        return maxNodo(x->right);
    return x;
}

Tipo* BinarySearchTree::max() const{
    BinarySearchTree::nodo* p = maxNodo(root);
    return p->info->copia();
}

BinarySearchTree::nodo* BinarySearchTree::minNodo(nodo* x) const{
    if(x->left != nullptr){
        return minNodo(x->left);
    }
    return x;
}

Tipo* BinarySearchTree::min() const{
    BinarySearchTree::nodo* p = minNodo(root);
    return p->info->copia();
}

BinarySearchTree::nodo* BinarySearchTree::succ(const nodo* x) const{
    if(x->right != nullptr){
        return minNodo(x->right);
    }
    else{
        BinarySearchTree::nodo* p = x->parent;
        while(p != nullptr && p->right){
            x = p;
            p = p->parent;
        }
        return p;
    }
}



BinarySearchTree::nodo* BinarySearchTree::somma(const nodo* a, const nodo* b, nodo* p) const{
    if(a && b){
        nodo* x;
        x = new nodo((a->info->operator +(b->info)), p, somma(a->left, b->left, x), somma(a->right, b->right, x));
        return x;
    }
    else
        return nullptr;
}

BinarySearchTree* BinarySearchTree::operator+(const BinarySearchTree* x) const{
    BinarySearchTree* p = new BinarySearchTree();
    p->root = somma(root, x->root, nullptr);
    return p;
}


BinarySearchTree::nodo* BinarySearchTree::sottrazione(const nodo* a, const nodo* b, nodo* p) const{
    if(a && b){
        nodo* x;
        x = new nodo((a->info->operator -(b->info)), p, sottrazione(a->left, b->left, x), sottrazione(a->right, b->right, x));
        return x;
    }
    else
        return nullptr;
}

BinarySearchTree* BinarySearchTree::operator-(const BinarySearchTree* x) const{
    BinarySearchTree* p = new BinarySearchTree();
    p->root = sottrazione(root, x->root, nullptr);
    return p;
}

BinarySearchTree& BinarySearchTree::operator=(const BinaryTree& t){
    if(this != &t){
        const BinarySearchTree& p = dynamic_cast<const BinarySearchTree&>(t);
        if(&p){
            distruggi(root);
            root = copia(p.root, nullptr);
        }
    }
    return *this;
}


std::ostream& operator<<(std::ostream& os, const BinarySearchTree* t){
    t->print(os, t->root);
    return os;
}
