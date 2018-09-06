#include "binarytree.h"

void BinaryTree::distruggi(nodo* t){
    if(t){
        distruggi(t->left);
        distruggi(t->right);
        delete t;
    }
}

int BinaryTree::conta(nodo* t){
    if(t)
        return 1 + conta(t->left) + conta(t->right);
    return 0;
}


BinaryTree& BinaryTree::operator =(const BinaryTree& t){
    if(this != &t){
        distruggi(root);
        root = copia(t.root);
    }
    return *this;
}

BinaryTree::nodo::~nodo(){
    if(info)
        delete info;
}

bool BinaryTree::empty() const{

    if(root == nullptr){
        std::cout << "INSIDE EMPTY" << std::endl;
        return true;
    }
    else{
        return false;
    }
}
//PER GUI

int BinaryTree::max_depth() const{
    return height(root);
}

int BinaryTree::height(nodo *n) const{
    if (!n)
        return -1;
    return 1 + std::max(height(n->left), height(n->right));
}

BinaryTree::nodo* BinaryTree::returnRoot() const{
    return root;
}

void BinaryTree::elimTree(){
    if(root){
        delete root;
        root = nullptr;
    }
}
