#include "huffmantree.h"
#include <vector>
#include <algorithm>
#include "exception.h"

HuffmanTree::HuffmanTree(const HuffmanTree &t){
    root = copia(t.root);
    dict = t.dict;
}

HuffmanTree::~HuffmanTree(){
    distruggi(root);
    dict.clear();
}

HuffmanTree::nodo* HuffmanTree::copia( nodo* t, nodo* p){
    if(t){
        HuffmanTree::nodo* x = new HuffmanTree::nodo(t->info->copia(), p);
        x->left = copia(t->left, x);
        x->right = copia(t->right, x);
        return x;
    }
    else
        return nullptr;
}


// A finish tree have n nodes and n-1 internal nodes
// Don't omits unused symbols
HuffmanTree::HuffmanTree(const std::string& s){
    if(s.length() == 0)
        throw new BadValueConstructor("BadValueConstructor", "Stringa vuota");

    std::string tmp = "";

    for(int i = 0; i < s.length(); i++){
        tmp = s[i];
        if(dict.find(tmp) == dict.end())
            dict[tmp] = 1;
        else
            dict[tmp] += 1;
    }

    buildTree(dict);
}

// Metodo di supporto al costruttore per costruire l'albero e nel caso di ricostruzione di esso
void HuffmanTree::buildTree(std::map<std::string, int>& d){
    if(root != nullptr)
        distruggi(root);

    std::vector<HuffmanTree::nodo*> queue;
    queue.reserve(d.size());



    for(auto it = d.begin(); it != d.end(); ++it)
        queue.push_back(new HuffmanTree::nodo(new Huffman(it->second, it->first)));

    queue.resize(queue.size());

    while(queue.size() > 1){
        std::sort(queue.begin(), queue.end(), compare);

        HuffmanTree::nodo* a = (*queue.begin());
        queue.erase(queue.begin());
        HuffmanTree::nodo* b = (*queue.begin());
        queue.erase(queue.begin());

        Huffman* x = dynamic_cast<Huffman*>(a->info);
        Huffman* y = dynamic_cast<Huffman*>(b->info);

        Huffman* tmp = new Huffman(x->getFrequency() + y->getFrequency(), x->getData() + y->getData());
        HuffmanTree::nodo* t = new HuffmanTree::nodo(tmp, nullptr, a, b);

        a->parent = t;
        b->parent = t;

        queue.push_back(t);
    }

    root = (*queue.begin());

    // Se d != dict (non passato da costruttore) then copio anche il dict
    if(&d != &dict){
        dict = d;
    }
}


void HuffmanTree::print(std::ostream& os, nodo* x) const{
    if(x){
        x->info->print(os);
        os << "(";
        print(os, x->left);
        os << ",";
        print(os, x->right);
        os << ")";
    }
    else
        os << "_";
}


Huffman* HuffmanTree::max() const{
    auto save = dict.begin();

    for(auto it = dict.begin(); it != dict.end(); ++it){
        if(it->second > save->second)
            save = it;
    }

    return new Huffman(save->second, save->first);
}

Huffman* HuffmanTree::min() const{
    auto save = dict.begin();

    for(auto it = dict.begin(); it != dict.end(); ++it){
        if(it->second < save->second)
            save = it;
    }
    return new Huffman(save->second, save->first);
}



bool HuffmanTree::compare(const nodo* a,const nodo* b) {
    if(!a || !b)
        return false;
    return a->info->operator <(b->info);
}

std::ostream& operator<<(std::ostream& os, const HuffmanTree* x){
    x->print(os, x->root);
    return os;
}


HuffmanTree& HuffmanTree::operator=(const BinaryTree& t){
    const HuffmanTree& p = dynamic_cast<const HuffmanTree&>(t);
    if(&p){
        if(this != &t){
            distruggi(root);
            root = copia(p.root);
        }
        return *this;
    }
    else
        throw new BadDynamicCast();
}

HuffmanTree* HuffmanTree::operator+(const HuffmanTree* t) const{
    if(!t || !root)
        return new HuffmanTree();

    std::map<std::string, int> tmp;
    tmp = dict;

    for(auto it = t->dict.begin(); it != t->dict.end(); ++it){
        if(tmp.find(it->first) == dict.end())
            tmp[it->first] = it->second;
        else
            tmp[it->first] += it->second;
    }

    std::string string_tmp = "";

    for(auto it = tmp.begin(); it != tmp.end(); ++it)
        for(int i = 0; i < it->second; i++)
            string_tmp += it->first;

    return new HuffmanTree(string_tmp);
}

void HuffmanTree::getCompression(std::map<std::string, std::string>&t,HuffmanTree::nodo* x, std::string path) const{
    if(x){
        getCompression(t, x->left, path += "1");

        if(!x->left && !x->right){
            Huffman* x_cast = dynamic_cast<Huffman*>(x->info);

            if(!x_cast)
                throw new BadDynamicCast();

            t[x_cast->getData()] = path;
            delete x_cast;
        }

        path.pop_back();
        getCompression(t, x->right, path += "0");
    }
}

std::map<std::string, std::string> HuffmanTree::compression() const{
    std::map<std::string, std::string> dict;
    getCompression(dict, root, "");
    return dict;
}

HuffmanTree::nodo* HuffmanTree::searchNodo(nodo* x, const Tipo* t) const{
    const Huffman* p = dynamic_cast<const Huffman*>(t);

    if(!x)
        return nullptr;


    if(p->checkKey(x->info))
        return x;
    else{
        nodo* s = searchNodo(x->left,t);
        if(s)
            return s;
        return searchNodo(x->right, t);
    }
}


Tipo* HuffmanTree::search(const Tipo* x) const{
    // Verifico se un certo nodo Huffman e presente nell'albero
    HuffmanTree::nodo* s = searchNodo(root, x);

    if(!s)
        return nullptr;

    return s->info->copia();
}

// problema del insertNodo
//void HuffmanTree::insertNodo(nodo* x, Tipo* t){}

// Si potrebbe aggiungere il valore Huffman al dizionario
// e ricostruire l'albero
void HuffmanTree::insert(Tipo* x){}


void HuffmanTree::deleteNodo(const Tipo *x){
    const Huffman* x_cast = dynamic_cast<const Huffman*>(x);

    if(!x_cast)
        throw new BadDynamicCast();

    bool check = true;
    auto it = dict.begin();


    while(check && it != dict.end()){
        if(it->first == x_cast->getData() && it->second == x_cast->getFrequency())
            check = false;
        ++it;
    }


    // Ricostruisci albero dal dict
    if(!check){
        it--;
        dict.erase(it);
        buildTree(dict);
    }
    // Throw Exception ? node not found ?

}
