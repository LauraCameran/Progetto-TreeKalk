#include "avltree.h"

AVLTree::AVLTree(const AVLTree& t){
    root = copia(t.root);
}

AVLTree::~AVLTree(){
    distruggi(root);
}

// Effetua la copia ricorsiva di un albero partendo
// da un nodo dato e un nodo padre, nullptr di default
AVLTree::node* AVLTree::copia(nodo* t, nodo* p){
    node* t_cast = dynamic_cast<node*>(t);
    if(t_cast){
        node* x = new node(t->info->copia(), p);
        x->balance = t_cast->balance;
        x->left = copia(t_cast->left, x);
        x->right = copia(t_cast->right, x);
        return x;
    }
    else
        return nullptr;
}

// Metodo ricorsivo per l'inserimento di un nuovo nodo
void AVLTree::insertNodo(nodo* x, Tipo* t){
    node* x_cast = dynamic_cast<node*>(x);
    if(x_cast){
        if(t->operator<(x_cast->info)){
            if(x_cast->left)
                insertNodo(x_cast->left, t);
            else
                x_cast->left = new AVLTree::node(t, x_cast);
        }
        else{
            if(x_cast->right)
                insertNodo(x_cast->right, t);
            else{
                x_cast->right = new AVLTree::node(t, x_cast);
            }
        }
    }
    rebalance(x_cast);
}

// Chiamata base di ricerca
Tipo* AVLTree::search(const Tipo* t) const{
    node* p = searchNodo(dynamic_cast<node*>(root), t);
    if(!p)
        throw new NodeNotFound();
    return p->info->copia();
}

// Ricerca di un nodo tramite la chiave all'interno di un albero
AVLTree::node* AVLTree::searchNodo(nodo* x, const Tipo* t) const{
    if(!x)
        return nullptr;

    node* x1 = dynamic_cast<node*>(x);
    if(t->operator==(x1->info))
        return x1;
    else{
        if(t->operator<(x1->info))
            return searchNodo(x1->left, t);
        else
            return searchNodo(x1->right, t);
    }
}

// Trova il successivo di un nodo
AVLTree::node* AVLTree::succ(node* x){
    if(x->right != nullptr)
        return minNodo(x->right);
    else{
        node* p = dynamic_cast<node*>(x->parent);
        while(p != nullptr && p->right){
            x = p;
            p = dynamic_cast<node*>(p->parent);
        }
        return p;
    }
}


// Effettua la cancellazione definitiva di un nodo senza ritornare una copia al chiamante
// stacca il nodo ricollegando i suoi figli e il padre
void AVLTree::deleteNodo(const Tipo* t){
    node* x = nullptr;
    node* y = nullptr;
    node* z = searchNodo(dynamic_cast<node*>(root), t);
    if(!z)
        throw new NodeNotFound();

    if(z->left == nullptr || z->right == nullptr)
        y = z;
    else
        y = succ(dynamic_cast<node*>(z));

    if(y->left != nullptr)
        x = dynamic_cast<node*>(y->left);
    else
        x = dynamic_cast<node*>(y->right);

    if(x != nullptr)
        x->parent =dynamic_cast<node*>(y->parent);

    if(y->parent == nullptr)
        root = x;

    else if(y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;

    if(y != z)
        z->info = y->info->copia();

    delete y;

    if(x)
        rebalance(x);

    if(root){
        node* auxNMin = minNodo(root);
        if(x!=auxNMin)
            rebalance(auxNMin);
        node* auxNMax = maxNodo(root);
        if(x!=auxNMax)
            rebalance(auxNMax);
    }

}


// Chiamata base di inserimento
void AVLTree::insert(Tipo* t){
    if(root)
        insertNodo(dynamic_cast<node*>(root), t->copia());
    else
        root = new node(t->copia());

}

// Metodo ricorsivo per la ricerca del massimo
AVLTree::node* AVLTree::maxNodo(nodo* x) const{
    if(x->right != nullptr){
        return maxNodo(x->right);
    }
    return dynamic_cast<node*>(x);
}

// Metodo base
Tipo* AVLTree::max() const{
    if(root)
        return maxNodo(dynamic_cast<node*>(root))->info->copia();

    throw new TreeInexistent();
}

// metodo ricorsivo per la ricerca del minimo
AVLTree::node* AVLTree::minNodo(nodo* x) const{
    if(x->left != nullptr){
        return minNodo(x->left);
    }
    return dynamic_cast<node*>(x);
}

Tipo* AVLTree::min() const{
    if(root)
        return minNodo(dynamic_cast<node*>(root))->info->copia();

    throw new TreeInexistent();
}

int AVLTree::height(node* n) const{
    if(!n)
        return -1;
    return 1 + std::max(height(dynamic_cast<node*>(n->left)), height(dynamic_cast<node*>(n->right)));
}


void AVLTree::setBalance(node* n){
    n->balance = height(dynamic_cast<node*>(n->right)) - height(dynamic_cast<node*>(n->left));
}

AVLTree::node* AVLTree::rotateLeft(node* a){
    node* b = dynamic_cast<node*>(a->right);
    b->parent = a->parent;
    a->right = b->left;

    if(a->right != nullptr)
        a->right->parent = a;

    b->left = a;
    a->parent = b;

    if(b->parent != nullptr){
        if(b->parent->right == a){
            b->parent->right = b;
        }
        else{
            b->parent->left = b;
        }
    }
    setBalance(a);
    setBalance(b);
    return b;
}

AVLTree::node* AVLTree::rotateRight(node* a){
    node* b = dynamic_cast<node*>(a->left);
    b->parent = a->parent;
    a->left = b->right;

    if(a->left != nullptr)
        a->left->parent = a;

    b->right = a;
    a->parent = b;

    if(b->parent != nullptr){
        if(b->parent->right == a){
            b->parent->right = b;
        }
        else{
            b->parent->left = b;
        }
    }
    setBalance(a);
    setBalance(b);
    return b;
}


AVLTree::node* AVLTree::rotateLeftThenRight(node* n){
    n->left = rotateLeft(dynamic_cast<node*>(n->left));
    return rotateRight(n);
}

AVLTree::node* AVLTree::rotateRightThenLeft(node* n){
    n->right = rotateRight(dynamic_cast<node*>(n->right));
    return rotateLeft(n);
}

void AVLTree::rebalance(node* n){
    setBalance(n);
    if(n->balance == -2){
        if(height(dynamic_cast<node*>(n->left->left)) >= height(dynamic_cast<node*>(n->left->right)))
            n = rotateRight(n);
        else
            n = rotateLeftThenRight(n);
    }
    else{
        if(n->balance == 2){
            if(height(dynamic_cast<node*>(n->right->right)) >= height(dynamic_cast<node*>(n->right->left)))
                n = rotateLeft(n);
            else
                n = rotateRightThenLeft(n);
        }
    }
    if(n->parent != nullptr)
        rebalance(dynamic_cast<node*>(n->parent));
    else
        root = n;
}

AVLTree::node* AVLTree::invertorder(node* n) const{
    if(n->balance == 0)
        return n;

    if(n->right)
        return invertorder(dynamic_cast<node*>(n->right));

    if(n->left)
        return invertorder(dynamic_cast<node*>(n->left));

    return nullptr;
}

AVLTree::node* AVLTree::preorder(node* n) const{
    if(n->balance == 0){
        return n;
    }
    if(n->left)
        return preorder(dynamic_cast<node*>(n->left));
    if(n->right)
        return preorder(dynamic_cast<node*>(n->right));

    return nullptr;
}

AVLTree* AVLTree::subtree_preorder(){
    node* radix = preorder(dynamic_cast<node*>(root));
    if(!radix)
        throw new NodeNotFound();

    AVLTree* subTree = new AVLTree();
    subTree->root = copia(radix);
    return subTree;
}


AVLTree* AVLTree::subtree_invertorder(){
    nodo* radix = invertorder(dynamic_cast<node*>(root));
    if(!radix){
        throw new NodeNotFound();
    }
    AVLTree* subTree = new AVLTree();
    subTree->root = copia(radix);
    return subTree;
}

void AVLTree::print(std::ostream& os, nodo* x) const{
    node* x_cast = dynamic_cast<node*>(x);
    if(x_cast){
        x_cast->info->print(os);
        os << "{B: " << x_cast->balance << "}(";
        print(os, x->left);
        os << ",";
        print(os, x_cast->right);
        os << ")";
    }
    else
        os << "_";
}

std::ostream& operator<<(std::ostream& os, const AVLTree* t){
    t->print(os, t->root);
    return os;
}




























