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
    if(!(typeid(root->info) == typeid(t)))
        throw new BadTypeValue();

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

//// SE uno dei due nodi non esiste, esso viene considerato come 0 e dunque si annulla
//BinarySearchTree::nodo* BinarySearchTree::moltiplicazione(const nodo* a, const nodo* b) const{
//    // Se non esiste a provo con b
//    if(!a && b)
//        return new nodo(b->info, nullptr, moltiplicazione(nullptr, b->left), moltiplicazione(nullptr, b->right));

//    if(!b && a)
//        return new nodo(a->info, nullptr, moltiplicazione(a->left, nullptr), moltiplicazione(a->right, nullptr));

//    if(a && b)
//        return new nodo((a->info->operator*(b->info)), nullptr, moltiplicazione(a->left, b->left), moltiplicazione(a->right, b->right));

//    else
//        return nullptr;

//}

//BinarySearchTree* BinarySearchTree::operator*(const BinarySearchTree* x) const{
//    BinarySearchTree* p = new BinarySearchTree();
//    p->root = moltiplicazione(root, x->root);
//    return p;
//}

// [TODO]
// se il nodo A or il nodo B non esiste lancio un'eccezzione
//BinarySearchTree::nodo* BinarySearchTree::divisione(const nodo* a, const nodo* b) const{
//    // Se non esiste a cosa ci faccio ?
//    // Sarebbe come fare 0/n => 0

//    if(!a && b)
//        return new nodo(nullptr, nullptr, divisione(a->left, b->left), divisione(a->right, b->right));

//    if(!b && a)
//        return nullptr;

//    if(a && b){
//        return new nodo(a->info->operator /(b->info), nullptr, divisione(a->left, b->left), divisione(a->right, b->right));
//    }
//    else
//        return nullptr;
//}

//BinarySearchTree* BinarySearchTree::operator /(const BinarySearchTree* x) const{
//    BinarySearchTree* p = new BinarySearchTree();
//    try{
//        p->root = divisione(root, x->root);
//    }catch(DivideByZero* e){
//        std::cout << e->getMessage();
//        return nullptr;
//    }
//    return p;
//}


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
