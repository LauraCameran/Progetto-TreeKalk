#include "controller.h"
#include <typeinfo>
#include <QDebug>

Controller::Controller(TabDialog* w): window(w){
    connect(this, SIGNAL(errorInput()), window, SLOT(errInputSlot()));
    connect(this, SIGNAL(secondTreeError()), window, SLOT(errSecondTreeSlot()));
    connect(this, SIGNAL(errorNode()), window, SLOT(errNodeSlot()));

    // connect(this, SIGNAL(testingHuffman()), window, SLOT(triggerHuffmanTest()));
}

void Controller::setTree(BinaryTree* t){
    tree = t;
}

void Controller::insertClicked(){
    Tab* senderTab = dynamic_cast<Tab*>(sender());  //vede chi ha mandato il segnale
    bool ok;

    if(dynamic_cast<HuffmanTab*>(senderTab)){
        std::string s = senderTab->getLine()->text().toStdString();

        if(s.length() == 0)
            emit errorInput();


        // emit(testingHuffman());
        HuffmanTree* p = new HuffmanTree(s);
        dynamic_cast<HuffmanTab*>(senderTab)->setTree(p);
        senderTab->update_draw(senderTab->getTree());
    }
    else{
        int c = senderTab->getLine()->text().toInt(&ok);    //[TODO] modificare gli int in string
        if(ok){
            senderTab->getTree()->insert(new Intero(c));
            senderTab->update_draw(senderTab->getTree());
        }
        else
            emit errorInput();  //input non valido.. manda segnale alla view
    }
}

void Controller::deleteClicked(){
    Tab* senderTab = dynamic_cast<Tab*>(sender());

    if(!senderTab->getTree())
        return;


    std::cout << senderTab->getTree() << std::endl;

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

            std::cout << senderTab->getTree()->empty() << std::endl;
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
        //ATT!
        //mandare c a model e accertarsi che c ci sia [TODO]
        if(ok){
            Intero* tmp = new Intero(c);
            senderTab->getTree()->deleteNodo(tmp);
            delete tmp;
            senderTab->update_draw(senderTab->getTree());
        }
        else
            emit errorInput();
    }

}

void Controller::searchClicked(){
    Tab* senderTab = dynamic_cast<Tab*>(sender());
    if(dynamic_cast<HuffmanTab*>(senderTab)){

    }
    else{
        bool ok;
        int c = senderTab->getLine()->text().toInt(&ok);
        //ATT!
        //mandare c a model e accertarsi che c ci sia [TODO]
        if(ok){
            Tipo* auxT = senderTab->getTree()->search(new Intero(c));
            Node* nod = new Node(QString::fromStdString(auxT->to_string()));
            senderTab->drawOneNode(nod);
        }
        else
            emit errorInput();
    }
}
void Controller::maxClicked(){
    Tab* senderTab = dynamic_cast<Tab*>(sender());
    //ATT!
    //accertarsi da model che l'albero esista   [TODO]
    Tipo* auxT = senderTab->getTree()->max();
    Node* nod = new Node(QString::fromStdString(auxT->to_string()));
    senderTab->drawOneNode(nod);
}
void Controller::minClicked(){
    Tab* senderTab = dynamic_cast<Tab*>(sender());
    //ATT!
    //accertarsi da model che l'albero esista   [TODO]
    Tipo* auxT = senderTab->getTree()->min();
    //Node* nod = new Node(QString::number(dynamic_cast<Intero*>(auxT)->getData()));
    Node* nod = new Node(QString::fromStdString(auxT->to_string()));
    senderTab->drawOneNode(nod);
}

void Controller::deleteTreeClicked(){
    Tab* senderTab = dynamic_cast<Tab*>(sender());

    //accertarsi da model che l'albero esista prima di eliminarlo

    senderTab->getTree()->elimTree();
    senderTab->cleanScene();
}
void Controller::showTreeClicked(){
    Tab* senderTab = dynamic_cast<Tab*>(sender());
    //ATT!
    //accertarsi da model che l'albero esista
    senderTab->update_draw(senderTab->getTree());
}

//BINARY SEARCH
void Controller::keepClicked(){
    BinarySearchTab* senderTab = dynamic_cast<BinarySearchTab*>(sender());
    if(senderTab){  //il segnale deriva da BinarySearch
        BinarySearchTree* auxT = dynamic_cast<BinarySearchTree*>(senderTab->getTree());
        if(auxT)
            senderTab->setSecondTree(auxT);
        senderTab->cleanScene();
    }
    else{   //il segnale deriva da Huffman
        HuffmanTab* senderTab = dynamic_cast<HuffmanTab*>(sender());
        HuffmanTree* auxT = dynamic_cast<HuffmanTree*>(senderTab->getTree());
        if(auxT)
            senderTab->setSecondTree(auxT);


        senderTab->cleanScene();
    }

}


// operator+
void Controller::plusClicked(){
    BinarySearchTab* senderTab = dynamic_cast<BinarySearchTab*>(sender());
    if(senderTab){
        BinarySearchTree* auxT = dynamic_cast<BinarySearchTree*>(senderTab->getTree());
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

        if(!senderTab->getSecondTree())
            emit secondTreeError();

        else{
            HuffmanTree* result = new HuffmanTree();
            if(auxT){

                // Se il second tree non e impostato
                // mandare un messaggio di errore
                BinaryTree* a;
                if(!senderTab->getSecondTree())
                    emit errOrder();
                a = senderTab->getSecondTree();

                try{
                    result = (dynamic_cast<HuffmanTree*>(a))->operator +(auxT);
                }catch(Exception* p){
                    std::cout << p->getMessage() << std::endl;
                }


                std::cout << result << std::endl;
            }
            senderTab->setTree(result);
            senderTab->update_draw(senderTab->getTree());
        }
    }
}

void Controller::minusClicked(){
    BinarySearchTab* senderTab = dynamic_cast<BinarySearchTab*>(sender());
    BinarySearchTree* auxT = dynamic_cast<BinarySearchTree*>(senderTab->getTree());
    BinarySearchTree* result;
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
    AVLTree* auxT = secT->subtree_preorder();
    if(auxT)
        senderTab->setSecondTree(auxT);
    senderTab->update_draw(senderTab->getSecondTree());
}

void Controller::subTInvClicked(){
    AvlTab* senderTab = dynamic_cast<AvlTab*>(sender());
    AVLTree* secT = dynamic_cast<AVLTree*>(senderTab->getTree());
    AVLTree* auxT = secT->subtree_invertorder();
    if(auxT)
        senderTab->setSecondTree(auxT);
    senderTab->update_draw(senderTab->getSecondTree());

}

//TWO THREE
//[TODO] se cerco di cancellare un nodo normale ECCEZIONE
void Controller::subPreClicked(){
    TwoThreeTab* senderTab = dynamic_cast<TwoThreeTab*>(sender());
    TwoThreeTree* secT = dynamic_cast<TwoThreeTree*>(senderTab->getTree());
    Node* nod = new Node(QString::fromStdString(secT->display_other_preorder()->info->to_string()));
    senderTab->drawOneNode(nod);
}

void Controller::subInvClicked(){
    TwoThreeTab* senderTab = dynamic_cast<TwoThreeTab*>(sender());
    TwoThreeTree* secT = dynamic_cast<TwoThreeTree*>(senderTab->getTree());
    Node* nod = new Node(QString::fromStdString(secT->display_other_invertorder()->info->to_string()));
    senderTab->drawOneNode(nod);

}

void Controller::compressClicked(){
/*
    HuffmanTab* senderTab = dynamic_cast<HuffmanTab*>(sender());
    HuffmanTree* auxT = dynamic_cast<HuffmanTree*>(senderTab->getTree());
    HuffmanTree* result;
    if(auxT){
        BinaryTree* a = senderTab->getSecondTree();
        result = (dynamic_cast<BinarySearchTree*>(a))->operator -(auxT);
    }
    senderTab->setTree(result);
    senderTab->update_draw(senderTab->getTree());
*/
}
