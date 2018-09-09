#include "controller.h"
#include <typeinfo>
#include <QDebug>
#include <QString>
#include <QMessageBox>

using std::cout;
using std::endl;

Controller::Controller(TabDialog* w): window(w){
    connect(this, SIGNAL(errorInput()), window, SLOT(errInputSlot()));
    connect(this, SIGNAL(secondTreeError()), window, SLOT(errSecondTreeSlot()));
    connect(this, SIGNAL(errorNode()), window, SLOT(errNodeSlot()));
    connect(this, SIGNAL(errTree()), window, SLOT(errTreeSlot()));
    connect(this, SIGNAL(errorTree()), window, SLOT(errTreeSlot()));
    connect(this, SIGNAL(errorDel()), window, SLOT(errDelSlot()));
}

Controller::~Controller(){}


void Controller::insertClicked(){
    Tab* senderTab = dynamic_cast<Tab*>(sender());  //vede chi ha mandato il segnale
    bool ok;

    if(dynamic_cast<HuffmanTab*>(senderTab)){
        std::string s = senderTab->getLine()->text().toStdString();

        // A digit one o more times
        QRegExp re("\\d*");


        if(re.exactMatch(QString::fromStdString(s))){
            emit errorInput();
            return;
        }

        if(s.length() == 0)
            emit errorInput();

        // emit(testingHuffman());
        HuffmanTree* p = new HuffmanTree(s);

        if(senderTab->getTree())
            senderTab->getTree()->elimTree();

        dynamic_cast<HuffmanTab*>(senderTab)->setTree(p);
        senderTab->update_draw(senderTab->getTree());
    }
    else{
        int c = senderTab->getLine()->text().toInt(&ok);
        if(ok){
            Intero* tmp = new Intero(c);
            senderTab->getTree()->insert(tmp);
            delete tmp;
            senderTab->update_draw(senderTab->getTree());
        }
        else
            emit errorInput();  //input non valido.. manda segnale alla view
    }
}

void Controller::deleteClicked(){
    Tab* senderTab = dynamic_cast<Tab*>(sender());

   // if(!senderTab->getTree())
   //     return;

    if(dynamic_cast<HuffmanTab*>(senderTab)){
        std::string s = senderTab->getLine()->text().toStdString();

        if(s.length() != 0){
            Huffman* tmp = new Huffman(0, s);

            try {
                senderTab->getTree()->deleteNodo(tmp);
            } catch (Exception* e) {
                emit errorNode();
            }

            delete tmp;

            if(senderTab->getTree()->empty()){
                senderTab->cleanScene();
             }
             else
                senderTab->update_draw(senderTab->getTree());

        }
        else
            emit errorInput();
    }
    else{
        bool ok;
        int c = senderTab->getLine()->text().toInt(&ok);


        if(ok){
            Intero* tmp = new Intero(c);
            try{
                senderTab->getTree()->deleteNodo(tmp);
            }
            catch(DeleteNotAllowed* e){
                emit errorDel();
                return;
            }
            catch(NodeNotFound* e){
                emit errorNode();
            }
            delete tmp;
            senderTab->cleanScene();
            senderTab->update_draw(senderTab->getTree());
        }
        else
            emit errorInput();
    }

}



void Controller::searchClicked(){
    Tab* senderTab = dynamic_cast<Tab*>(sender());

    if(dynamic_cast<HuffmanTab*>(senderTab)){
        std::string str_search = senderTab->getLine()->text().toStdString();

        if(str_search.length() == 0){
            emit errorInput();
            return;
        }

        Tipo* h_search = new Huffman(0, str_search);
        Tipo* auxT = senderTab->getTree()->search(h_search);
        delete h_search;

        if(!auxT){
            emit errorNode();
            return;
        }

        Node* nod = new Node(QString::fromStdString(auxT->to_string()));
        senderTab->drawOneNode(nod);
        delete auxT;
    }
    else{
        bool ok;
        int c = senderTab->getLine()->text().toInt(&ok);
        if(ok){

                Intero* tmp = new Intero(c);
                Tipo* auxT = nullptr;
                try{
                    auxT = senderTab->getTree()->search(tmp);
                }catch(BadTypeValue* e){
                    delete e;
                    delete tmp;
                    emit errorNode();

                    return;
                }

                delete tmp;
                Node* nod = new Node(QString::fromStdString(auxT->to_string()));
                delete auxT;
                senderTab->drawOneNode(nod);

        }
        else
            emit errorInput();
    }
}


void Controller::maxClicked(){
    Tab* senderTab = dynamic_cast<Tab*>(sender());

    BinaryTree* t = senderTab->getTree();
    if(t->returnRoot()){
        Tipo* auxT = t->max();
        Node* nod = new Node(QString::fromStdString(auxT->to_string()));
        senderTab->drawOneNode(nod);
        delete auxT;
    }
    else{
        emit errorTree();
    }
}
void Controller::minClicked(){
    Tab* senderTab = dynamic_cast<Tab*>(sender());
    BinaryTree* t = senderTab->getTree();
    if(t->returnRoot()){
        Tipo* auxT = t->min();
        Node* nod = new Node(QString::fromStdString(auxT->to_string()));
        senderTab->drawOneNode(nod);
        delete auxT;
    }
    else{
        emit errorTree();
    }

}

// clear button
void Controller::deleteTreeClicked(){
    Tab* senderTab = dynamic_cast<Tab*>(sender());

    if(!senderTab->getTree()){
        senderTab->cleanScene();
        return;
    }
    senderTab->getTree()->elimTree();
    senderTab->cleanScene();
}

void Controller::showTreeClicked(){
    Tab* senderTab = dynamic_cast<Tab*>(sender());

    if(!senderTab->getTree() || !senderTab->getTree()->returnRoot()){
        emit errTree();
        return;
    }

    senderTab->update_draw(senderTab->getTree());
}

//BINARY SEARCH
void Controller::keepClicked(){

    BinarySearchTab* senderTab = dynamic_cast<BinarySearchTab*>(sender());
    if(senderTab){  //il segnale deriva da BinarySearch
        BinarySearchTree* auxT = dynamic_cast<BinarySearchTree*>(senderTab->getTree());
        if(!senderTab->getTree()->returnRoot()){
            emit errTree();
            return;
        }
        if(auxT){
            senderTab->setSecondTree(auxT);
        }
        else{
            emit errTree();
            return;
        }
        senderTab->cleanScene();
    }
    else{   //il segnale deriva da Huffman
        HuffmanTab* senderTab = dynamic_cast<HuffmanTab*>(sender());
        HuffmanTree* auxT = dynamic_cast<HuffmanTree*>(senderTab->getTree());
        if(!senderTab->getTree() || !senderTab->getTree()->returnRoot()){
            emit errTree();
            return;
        }
        if(auxT){
            senderTab->setSecondTree(auxT);
            //senderTab->getSecondTree()->elimTree();
        }
        else{
            emit errTree();
            return;
        }
        senderTab->cleanScene();
    }

}


// operator+
void Controller::plusClicked(){
    BinarySearchTab* senderTab = dynamic_cast<BinarySearchTab*>(sender());

    if(senderTab){
        BinarySearchTree* auxT = dynamic_cast<BinarySearchTree*>(senderTab->getTree());

        if(!senderTab->getTree()->returnRoot()){
            emit errTree();
            return;
        }

        if(!senderTab->getSecondTree()){
            emit secondTreeError();
        }
        else{
            BinarySearchTree* result;
            if(auxT){
                BinaryTree* a = senderTab->getSecondTree();
                result = (dynamic_cast<BinarySearchTree*>(a))->operator +(auxT);
            }
            senderTab->setTree(result);
            senderTab->update_draw(senderTab->getTree());
        }
    }
    else{
        HuffmanTab* senderTab = dynamic_cast<HuffmanTab*>(sender());
        HuffmanTree* auxT = dynamic_cast<HuffmanTree*>(senderTab->getTree());

        if(!senderTab->getTree()){
            emit errTree();
            return;
        }

        if(!senderTab->getTree()->returnRoot()){
            emit secondTreeError();
            return;
        }
/*
        if(!senderTab->getSecondTree()){
            emit errTree();
            return;
        }
*/
        else{
            HuffmanTree* result = new HuffmanTree();
            if(auxT){

                BinaryTree* a;
                if(!senderTab->getSecondTree()){
                    emit errOrder();
                    return;
                }
                a = senderTab->getSecondTree();


                result = (dynamic_cast<HuffmanTree*>(a))->operator +(auxT);
            }
            senderTab->setTree(result);
            senderTab->update_draw(senderTab->getTree());
        }
    }
}

void Controller::compressClicked(){

    HuffmanTab* senderTab = dynamic_cast<HuffmanTab*>(sender());
    if(!senderTab->getTree() || !senderTab->getTree()->returnRoot()){
        emit errorTree();
        return;
    }

    std::map<std::string, std::string> dict = dynamic_cast<HuffmanTree*>(senderTab->getTree())->compression();
    senderTab->drawTextCompression(dict);

}

void Controller::minusClicked(){
    BinarySearchTab* senderTab = dynamic_cast<BinarySearchTab*>(sender());
    if(!senderTab->getTree()->returnRoot()){
        emit errTree();
        return;
    }
    BinarySearchTree* result;
    BinarySearchTree* auxT = dynamic_cast<BinarySearchTree*>(senderTab->getTree());
    if(auxT){
        BinaryTree* a = senderTab->getSecondTree();
        result = (dynamic_cast<BinarySearchTree*>(a))->operator -(auxT);
    }
    senderTab->setTree(result);
    senderTab->update_draw(senderTab->getTree());

}


//AVL
void Controller::subTPreClicked(){
    AvlTab* senderTab = dynamic_cast<AvlTab*>(sender());
    AVLTree* secT = dynamic_cast<AVLTree*>(senderTab->getTree());
    if(secT->returnRoot()){
        AVLTree* auxT = secT->subtree_preorder();
        if(auxT)
            senderTab->setSecondTree(auxT);
        senderTab->update_draw(senderTab->getSecondTree());
        delete auxT;
    }
    else
        emit errorTree();
}

void Controller::subTInvClicked(){
    AvlTab* senderTab = dynamic_cast<AvlTab*>(sender());
    AVLTree* secT = dynamic_cast<AVLTree*>(senderTab->getTree());
    if(secT->returnRoot()){
        AVLTree* auxT = secT->subtree_invertorder();
        if(auxT)
            senderTab->setSecondTree(auxT);
        senderTab->update_draw(senderTab->getSecondTree());
        delete auxT;
    }
    else
        emit errorTree();

}

//TWO THREE
void Controller::subPreClicked(){
    TwoThreeTab* senderTab = dynamic_cast<TwoThreeTab*>(sender());
    if(!senderTab->getTree()->returnRoot()){
        emit errorTree();
        return;
    }
    TwoThreeTree* secT = dynamic_cast<TwoThreeTree*>(senderTab->getTree());
    try{
        TwoThreeTree::node* n = secT->display_other_preorder();
        QString s = QString::fromStdString(n->info->to_string());
        s.append("&");
        s.append(QString::fromStdString(n->other->to_string()));
        Node* nod = new Node(s);
        senderTab->drawOneNode(nod);
    }
    catch(NodeNotFound* e){
        emit errorNode();
    }
}

void Controller::subInvClicked(){
    TwoThreeTab* senderTab = dynamic_cast<TwoThreeTab*>(sender());
    if(!senderTab->getTree()->returnRoot()){
        emit errorTree();
        return;
    }
    TwoThreeTree* secT = dynamic_cast<TwoThreeTree*>(senderTab->getTree());
    try{
        TwoThreeTree::node* n = secT->display_other_invertorder();
        QString s = QString::fromStdString(n->info->to_string());
        s.append("&");
        s.append(QString::fromStdString(n->other->to_string()));
        Node* nod = new Node(s);
        senderTab->drawOneNode(nod);
    }
    catch(NodeNotFound* e){
        emit errorNode();
    }

}
