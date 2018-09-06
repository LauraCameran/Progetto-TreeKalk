#include "avltree.h"

//AVLTree::node::~node(){}


AVLTree::AVLTree(const AVLTree& t){
    root = copia(t.root);
}

AVLTree::~AVLTree(){
    distruggi(root);
}

// Guardare cosa passa in p alla prima chiamata
// Mi fido della laura (1)
// sboraghe sora
AVLTree::node* AVLTree::copia( nodo* t, nodo* p){
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

void AVLTree::insertNodo(nodo* x, Tipo* t){
    node* x_cast = dynamic_cast<node*>(x);
    if(x_cast){
        if(t->operator<(x_cast->info)){
            if(x_cast->left)
                insertNodo(x_cast->left, t);
            else
                x_cast->left = new AVLTree::node(t->copia(), x_cast);
        }
        else{
            if(x_cast->right)
                insertNodo(x_cast->right, t);
            else
                x_cast->right = new AVLTree::node(t->copia(), x_cast);
        }
    }
    rebalance(x_cast);
}

// Invece di fare il dynamic_cast subito ogni chiamata ricorsiva
// Fare il dynamic_cast solo quando si trova il nodo interessato
// Poiche il la ricerca usa solo info
// ok
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

// prima di fare dynamic_cast di x->parent
// CHECK IF EXIST PARENT
// Perche fare quel dynamic cast ad ogni ciclo while
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
        //z->info->operator=(*(y->info->copia()));
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



AVLTree::node* AVLTree::maxNodo(nodo* x) const{
    if(x->right != nullptr){
        return maxNodo(x->right);
    }
    return dynamic_cast<node*>(x);
}

AVLTree::node* AVLTree::minNodo(nodo* x) const{
    if(x->left != nullptr){
        return minNodo(x->left);
    }
    return dynamic_cast<node*>(x);
}

void AVLTree::insert(Tipo* t){
    if(root)
        insertNodo(dynamic_cast<node*>(root), t);
    else
        root = new node(t->copia());

}

Tipo* AVLTree::search(const Tipo* t) const{
    node* p = searchNodo(dynamic_cast<node*>(root), t);
    if(!p)
        throw new NodeNotFound();
    return p->info->copia();
}

Tipo* AVLTree::max() const{
    if(root)
        return maxNodo(dynamic_cast<node*>(root))->info->copia();
    return nullptr;
}

Tipo* AVLTree::min() const{
    if(root)
        return minNodo(dynamic_cast<node*>(root))->info->copia();
    return nullptr;
}

// E SE INVECE DI FARE TUTTI STI CAZZO DI CAST
// Modifico la classe node e metto left, right e parten a node* ?!!?
// L: NO! left right e parent vengono ereditati da nodo
int AVLTree::height(node* n){
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

AVLTree* AVLTree::subtree_preorder() {
    node* radix = preorder(dynamic_cast<node*>(root));
    if(!radix){
        throw new NodeNotFound();
    }
    AVLTree* subTree = new AVLTree();
    subTree->root = copia(radix);
    return subTree;
}


AVLTree* AVLTree::subtree_invertorder() {
    nodo* radix = invertorder(dynamic_cast<node*>(root));
    if(!radix){
        throw new NodeNotFound();
    }
    AVLTree* subTree = new AVLTree();
    subTree->root = copia(radix);
    return subTree;
}



// dynamic_cast di null ritorna null ?
// L: ovviamente
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
    //std::cout << "operator << " << std::endl;
    t->print(os, t->root);
    return os;
}




























