#include "twothreetree.h"

TwoThreeTree::node::node(Tipo* i, nodo* p, nodo* l, nodo* r, Tipo* o, nodo* m):nodo(i, p, l, r), other(o), middle(m){
    if(i)
        num = 1;
    else
        num = 0;
}


TwoThreeTree::node::~node(){
    if(num == 2)
        delete other;
}


TwoThreeTree::~TwoThreeTree(){
    delete dynamic_cast<node*>(root);
}

TwoThreeTree::TwoThreeTree(const TwoThreeTree& t){
    root = copia(t.root);
}

// Ridifinizioni di metodi statici
void TwoThreeTree::distruggi(nodo* n){
    node* n_cast = dynamic_cast<node*>(n);
    if(n_cast){
        distruggi(n_cast->left);
        distruggi(n_cast->middle);
        distruggi(n_cast->right);
        delete n_cast;
    }
}
int TwoThreeTree::conta(nodo* n){
    node* n_cast = dynamic_cast<node*>(n);
    if(n_cast)
        return 1 + conta(n_cast->left) + conta(n_cast->middle) + conta(n_cast->right);
    else
        return 0;
}


TwoThreeTree::node* TwoThreeTree::copia( nodo* t, nodo* p){
    node* t_cast = dynamic_cast<node*>(t);
    node* p_cast = dynamic_cast<node*>(p);

    if(t_cast){
        TwoThreeTree::node* x = new node();
        x->other->operator=(*(t_cast->other->copia()));
        x->info->operator=(*(t_cast->info->copia()));
        x->parent = p_cast;
        x->left = copia(t_cast->left, x);
        x->middle = copia(t_cast->middle, x);
        x->right = copia(t_cast->right, x);
        return x;
    }
    else
        return nullptr;
}


void TwoThreeTree::insertNodo(nodo* x, Tipo* t){
    node* x_cast = dynamic_cast<node*>(x);

    if(x_cast){
        if(t->operator<(x_cast->info)){
            if(x_cast->left){
                node* x_left = dynamic_cast<node*>(x->left);
                if(leaf(x_left)){
                    if(x_left->num == 1){
                        addInfo(x_left, t);
                    }
                    else{
                        split(x_left, t);
                    }
                }
                else{
                    insertNodo(x_cast->left, t);
                }
            }
            else{
                x_cast->left = new TwoThreeTree::node(t, x_cast);
            }
        }
        else{
            if(x_cast->right){
                node* x_right = dynamic_cast<node*>(x_cast->right);
                if(leaf(x_right)){
                    if(x_right->num == 1){
                        addInfo(x_right, t);
                    }
                    else{
                        split(x_right, t);
                    }
                }
                else{
                    insertNodo(x_cast->right, t);
                }
            }
            else{
                x_cast->right = new TwoThreeTree::node(t, x_cast);
            }
        }
    }
}


// FATTO

TwoThreeTree::node* TwoThreeTree::searchNodo(nodo* x, const Tipo* t) const{
    node* x_cast = dynamic_cast<node*>(x);

    if(x_cast){
        if(t->operator==(x_cast->other) || t->operator==(x_cast->info)){
            return x_cast;
        }
        // t > info NO minore... PECCATO CEH DC NON E DEFINITO MAGGIORE
        if(t->operator>(x_cast->info) && t->operator<(x_cast->other))
            return searchNodo(x_cast->middle, t);
        if(t->operator<(x_cast->info))
            return searchNodo(x_cast->left, t);
        else{
            if(x_cast->info->operator<(t))
                return searchNodo(x->right, t);
        }
    }
    // check nullptr;
    return nullptr;
}


// tolto elim
// FATTO
void TwoThreeTree::deleteNodo(const Tipo* t){
    node* aux = searchNodo(dynamic_cast<node*>(root), t);
    if(!aux)
        throw new NodeNotFound();
    if(aux->num == 2){  //tolgo il campo info o other in base a quale dei due è t
        if(aux->info == t){ //il campo da rimuovere è il primo (info)
              //tengo solo il secondo campo, other (che ora diventa info)
               aux->info = aux->other->copia();
               removeOther(aux);
               if(aux->middle){    //ATT: elimina anche figlio centrale
                   delete aux->middle;    //elimino il figlio centrale
                   aux->middle = nullptr;
               }
        }
        else{   //il campo da rimuovere è il secondo (other)
              //tengo il campo info, rimuovo l'altro
            removeOther(aux);
            if(aux->middle){  //ATT: elimina anche figlio centrale
                delete aux->middle;
                aux->middle = nullptr;
            }
        }
    }
    else    //il nodo non viene eliminato perchè ha un solo campo info
        throw new DeleteNotAllowed();

}




TwoThreeTree::node* TwoThreeTree::maxNodo(nodo* x) const{
    node* x_cast = dynamic_cast<node*>(x);
    if(!x_cast)
        return nullptr;

    if(x_cast->right != nullptr)
        return maxNodo(x_cast->right);

    return x_cast;
}


TwoThreeTree::node* TwoThreeTree::minNodo(nodo* x) const{
    node* x_cast = dynamic_cast<node*>(x);
    if(!x_cast)
        return nullptr;

    if(x_cast->left != nullptr)
        return minNodo(x->left);

    return x_cast;
}


void TwoThreeTree::print(std::ostream& os, nodo* n) const{
    node* x = dynamic_cast<node*>(n);
    if(x){
        x->info->print(os);

        if(x->num == 2){
            os << "&";
            x->other->print(os);
        }

        os << "(";
        print(os, x->left);
        os << ",";
        print(os, x->middle);
        os << ",";
        print(os, x->right);
        os << ")";
    }
    else
        os << "_";
}



void TwoThreeTree::insert(Tipo* t){
    if(root)
        insertNodo(dynamic_cast<node*>(root), t->copia());
    else
        root = new node(t->copia());
}

// Ritorno il campo info
Tipo* TwoThreeTree::search(const Tipo* t) const{
    node* p = searchNodo(dynamic_cast<node*>(root), t);
    if(!p)
        throw new NodeNotFound();
    return p->info->copia();
}

Tipo* TwoThreeTree::max() const{
    node* p;
    if(root){
        p = maxNodo(dynamic_cast<node*>(root));
    }
    else{
        throw new TreeInexistent();
    }
    return p->info->copia();
}


Tipo* TwoThreeTree::min() const{
    node* p;
    if(root){
        p = minNodo(dynamic_cast<node*>(root));
    }
    else{
        throw new TreeInexistent();
    }
    return p->info->copia();
}



// CHECK COPIATO TUTTO
// DON'T TRUST
void TwoThreeTree::split(node* n, Tipo* t){
    Tipo* mid = searchMiddle(n, t);
    if(n->parent){
        node* n_parent = dynamic_cast<node*>(n->parent);
        if(n_parent->other == nullptr){
            addInfo(n_parent, mid);
            int c = child(n);

            if(c == 1){
                n_parent->middle = new TwoThreeTree::node(n->other->copia(), n->parent);
                removeOther(n);
            }
            else{
                if(c == 3){
                    n_parent->middle = new node(n->info->copia(), n->parent);
                    n->info = n->other->copia();
                    removeOther(n);
                }
            }
        }
        else{   // Padre con 2 info
            int c = child(n);
            if(c == 1){
                node* tmp = new node(n->other->copia(), n->parent);
                removeOther(n);

                Tipo* midParent = searchMiddle(n_parent, mid);
                node* grandad = dynamic_cast<node*>(n_parent->parent);

                node* p = new node(n_parent->other->copia());

                removeOther(n_parent);

                p->left = n_parent->middle;
                p->right = n_parent->right;

                p->left->parent = p;
                p->right->parent = p;

                n->parent->right = tmp;
                n_parent->middle = nullptr;

                node* boss = new node(midParent->copia(), grandad);

                n->parent->parent = boss;
                p->parent = boss;
                boss->left = n->parent;
                boss->right = p;
                if(boss->parent == nullptr)
                    root = boss;
                else
                    grandad->left = boss;
            }
            if(c == 3){
                node* tmp = new node(n->info->copia());

                n->info = n->other->copia();
                removeOther(n);

                Tipo* midParent = searchMiddle(n_parent, mid);
                node* grandad = dynamic_cast<node*>(n_parent->parent);

                node* p = new node(n->parent->info->copia(), grandad);

                n->parent->info = n_parent->other->copia();
                removeOther(n_parent);

                p->right = n_parent->middle;
                p->left = n->parent->left;

                p->left->parent = p;
                p->right->parent = p;

                n->parent->left = tmp;
                n_parent->middle = nullptr;

                node* boss = new node(midParent->copia(), grandad);

                n->parent->parent = boss;
                p->parent = boss;
                boss->left = p;
                boss->right = n->parent;
                if(boss->parent == nullptr)
                    root = boss;
                else
                    grandad->right = boss;

            }
        }
    }
}

// FATTO
Tipo* TwoThreeTree::searchMiddle(node* n, Tipo* t){
    if(t->operator<=(n->info)){
        Tipo* aux = n->info;
        n->info = t->copia();
        return aux;
    }
    else{
        if(t->operator>=(n->other)){
            Tipo* aux = n->other;
            n->other = t->copia();
            return aux;
        }
    }
    return t;
}

// FATTO
int TwoThreeTree::child(node* n) const{
    if(n->parent->left == n)
        return 1;
    else{
        if(n->parent->right == n)
            return 3;
        else
            return 2;
    }
    return 0;
}

// FATTO
void TwoThreeTree::addInfo(node* n, Tipo* t){
    if(t->operator<(n->info)){
        n->other = n->info;
        n->info = t;
    }
    else{
        n->other = t;
    }
    n->num = 2;
}

// FATTO
// [TODO] GARBAGE SE OTHER punta a un oggetto ??
void TwoThreeTree::removeOther(node* n){
    //n->other = nullptr;
    delete n->other;    //RISOLVE? DIO CAN
    n->other = nullptr;
    n->num = 1;
}

bool TwoThreeTree::leaf(node* n) const{
    return (!n->left && !n->right && !n->middle);
}

TwoThreeTree::node* TwoThreeTree::preorder(node* n) const{
    if(n->num == 2){
        return n;
    }
    if(n->left)
        return invertorder(dynamic_cast<node*>(n->left));
    if(n->right)
        return invertorder(dynamic_cast<node*>(n->right));

    return nullptr;
}


TwoThreeTree::node* TwoThreeTree::display_other_preorder() const{
    node* auxNode = preorder(dynamic_cast<node*>(root));
    if(!auxNode){
        throw new NodeNotFound();
    }
    return auxNode;
}

TwoThreeTree::node* TwoThreeTree::invertorder(node* n) const{
    if(n->num == 2){
        return n;
    }
    if(n->right)
        return invertorder(dynamic_cast<node*>(n->right));
    if(n->left)
        return invertorder(dynamic_cast<node*>(n->left));

    return nullptr;
}

// A COSA CAZZO GLI SERVE ?
TwoThreeTree::node* TwoThreeTree::display_other_invertorder() const{
    node* auxNode = invertorder(dynamic_cast<node*>(root));
    if(!auxNode){
        throw new NodeNotFound();
    }
    return auxNode;
}


std::ostream& operator<<(std::ostream& os, const TwoThreeTree* t){
    t->print(os, t->root);
    return os;
}





