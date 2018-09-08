#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H
#include "huffman.h"
#include "binarytree.h"
#include <map>

class HuffmanTree: public BinaryTree{
private:

    using typename BinaryTree::nodo;
    using BinaryTree::root;

    std::map<std::string, int> dict;

    // metodi virtuali
    nodo* copia(nodo*, nodo* = nullptr);
    nodo* searchNodo(nodo*, const Tipo*) const;

    // Metodo usato da std::sort
    static bool compare(const nodo*,const nodo*);

    void getCompression(std::map<std::string, std::string>&, nodo*, std::string) const;
    void print(std::ostream&, nodo*) const;

    void buildTree(std::map<std::string, int>&);

public:

    HuffmanTree(){}
    HuffmanTree(const std::string&);
    HuffmanTree(const HuffmanTree&);
    ~HuffmanTree();

    // Metodi virtuali puri da implementare
    HuffmanTree& operator=(BinaryTree const&);
    void insert(Tipo*);
    void deleteNodo(const Tipo*);
    Tipo* search(const Tipo*) const;
    Huffman* max() const;
    Huffman* min() const;

    // Funzionalita aggiuntive di HuffmanTree
    HuffmanTree* operator+(const HuffmanTree*) const;
    std::map<std::string, std::string> compression() const;

    friend std::ostream& operator<<(std::ostream&, const HuffmanTree*);
};


#endif // HUFFMANTREE_H
