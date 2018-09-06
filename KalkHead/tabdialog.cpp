#include "tabdialog.h"

#include <QFileInfo>
#include <QVBoxLayout>
#include <QDebug>
#include <QList>
#include <QtMath>
#include <QPushButton>
#include <QMessageBox>
#include <QString>

TabDialog::TabDialog(const QString &fileName, QWidget *parent): QDialog(parent){
    controller = new Controller(this);
    QFileInfo fileInfo(fileName);
    tabWidget = new QTabWidget;
    tabWidget->insertTab(1, new AvlTab(this, controller), tr("AVL"));
    tabWidget->insertTab(2, new TwoThreeTab(this, controller), tr("TWO-THREE"));
    tabWidget->insertTab(3, new HuffmanTab(this, controller), tr("HUFFMAN"));
    tabWidget->insertTab(4, new BinarySearchTab(this, controller), tr("BINARY-SEARCH"));

    buttonBox = new QDialogButtonBox(QDialogButtonBox::Help);
    connect(buttonBox, SIGNAL(helpRequested()), this, SLOT(helpPressed()));

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(tabWidget);
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);

    setWindowTitle(tr("Tab Tree"));
}

void TabDialog::helpPressed(){
    QMessageBox msgBox;
    msgBox.setText("Write in the line and than press the button. \nThe display shows the tree you are creating. \n+ and - are operations between the current tree and the tree you will create afterwards (create the first tree, click keep, create the second tree, click the operator to make the operation and see the result). \nSUBTREE PRE and SUBTREE INV display the first balanced sub-trees within your current tree (following the pre-order and invert-order respectively). \n3-NODE PRE and 3-NODE INV display the first 3-nodes within your current tree (following the pre-order and invert-order respectively)");
    msgBox.setWindowTitle("HELP");
    msgBox.exec();
}

void TabDialog::errInputSlot(){
    QMessageBox msgBox;
    msgBox.setText("Write a valid input!");
    msgBox.setWindowTitle("INPUT ERROR");
    msgBox.exec();
}

void TabDialog::errSecondTreeSlot(){
    QMessageBox msgBox;
    msgBox.setText("Create another tree!");
    msgBox.setWindowTitle("NOT ENOUGH TREE");
    msgBox.exec();
}

void TabDialog::triggerHuffmanTest(){
    QMessageBox msg;
    msg.setText("Stringa inserita");
    msg.setWindowTitle("testing by laura");
    msg.exec();
}

void TabDialog::errNodeSlot(){
    QMessageBox msg;
    msg.setText("Node Not Found");
    msg.setWindowTitle("NODE ERROR");
    msg.exec();
}

void TabDialog::errTreeSlot(){
    QMessageBox msg;
    msg.setText("Tree Not Exist");
    msg.setWindowTitle("TREE ERROR");
    msg.exec();
}

void TabDialog::errDelSlot(){
    QMessageBox msg;
    msg.setText("Delete Not Allowed");
    msg.setWindowTitle("DELETE ERROR");
    msg.exec();
}


Tab::Tab(QWidget* parent, Controller* control): QWidget(parent), controller(control){
    mainLayout = new QGridLayout;  //layout
    insert = new QPushButton(tr("INSERT"), this);
    del = new QPushButton(tr("DELETE"), this);
    search = new QPushButton(tr("SEARCH"), this);
    max = new QPushButton(tr("MAX"), this);
    min = new QPushButton(tr("MIN"), this);
    delTree = new QPushButton(tr("DELETE TREE"), this);
    showTree = new QPushButton(tr("SHOW TREE"), this);

    //tree = new BinaryTree();
    line = new QLineEdit();
    controller->setTree(tree);
    QVBoxLayout* boxl = new QVBoxLayout();
    view = new QGraphicsView();
    scene = new QGraphicsScene();
    view->setMinimumHeight(300);
    view->setScene(scene);
    boxl->addWidget(view);
    //aggiunta dei widget
    mainLayout->addLayout(boxl, 0, 0, 1, 3);
    mainLayout->addWidget(line, 1, 0, 1, 3);
    mainLayout->addWidget(insert, 2, 0, 1, 1);
    mainLayout->addWidget(del, 2, 1, 1, 1);
    mainLayout->addWidget(search, 2, 2, 1, 1);
    mainLayout->addWidget(max, 3, 0, 1, 1);
    mainLayout->addWidget(min, 3, 1, 1, 1);
    mainLayout->addWidget(showTree, 3, 2, 1, 1);
    mainLayout->addWidget(delTree, 4, 0, 1, 1);
    //connessioni tra widget
    //connect(line, SIGNAL(returnPressed()), insert, SIGNAL(clicked()));    //PROBLEMA!!!
    connect(insert, SIGNAL(clicked()), this, SLOT(insertClicked()));
    connect(this, SIGNAL(auxiliaryIns()), controller, SLOT(insertClicked()));
    connect(del, SIGNAL(clicked()), this, SLOT(deleteClicked()));
    connect(this, SIGNAL(auxiliaryDel()), controller, SLOT(deleteClicked()));
    connect(search, SIGNAL(clicked()), this, SLOT(searchClicked()));
    connect(this, SIGNAL(auxiliarySearch()), controller, SLOT(searchClicked()));
    connect(max, SIGNAL(clicked()), this, SLOT(maxClicked()));
    connect(this, SIGNAL(auxiliaryMax()), controller, SLOT(maxClicked()));
    connect(min, SIGNAL(clicked()), this, SLOT(minClicked()));
    connect(this, SIGNAL(auxiliaryMin()), controller, SLOT(minClicked()));
    connect(delTree, SIGNAL(clicked()), this, SLOT(deleteTreeClicked()));
    connect(this, SIGNAL(auxiliaryDelT()), controller, SLOT(deleteTreeClicked()));
    connect(showTree, SIGNAL(clicked()), this, SLOT(showTreeClicked()));
    connect(this, SIGNAL(auxiliaryShowT()), controller, SLOT(showTreeClicked()));

    setLayout(mainLayout);
}

void Tab::linePressed(){
    emit auxiliaryLine();
}

void Tab::insertClicked(){
    emit auxiliaryIns();
}

void Tab::deleteClicked(){
   emit auxiliaryDel();
}

void Tab::searchClicked(){
   emit auxiliarySearch();
}

void Tab::maxClicked(){
   emit auxiliaryMax();
}

void Tab::minClicked(){
    emit auxiliaryMin();
}

void Tab::deleteTreeClicked(){
    emit auxiliaryDelT();
}
void Tab::showTreeClicked(){
    emit auxiliaryShowT();
}

QLineEdit* Tab::getLine() const{
    return line;
}

QGridLayout* Tab::getLayout() const{
    return mainLayout;
}

BinaryTree* Tab::getTree() const{
    return tree;
}

BinarySearchTab::BinarySearchTab(QWidget *parent, Controller* control): Tab(parent,control){
    plus = new QPushButton(tr("+"), this);
    minus = new QPushButton(tr("-"), this);
    keep = new QPushButton(tr("KEEP"), this);
    getLayout()->addWidget(plus, 4, 1, 1, 1);
    getLayout()->addWidget(minus, 4, 2, 1, 1);
    getLayout()->addWidget(keep, 5, 0, 1, 1);
    tree = new BinarySearchTree;
    tree2 = new BinarySearchTree;

    //fare connessioni..
    connect(line, SIGNAL(returnPressed()), this, SLOT(insertClicked()));
    connect(keep, SIGNAL(clicked()), this, SLOT(keepClicked()));
    connect(this, SIGNAL(auxiliaryKeep()), controller, SLOT(keepClicked()));
    connect(plus, SIGNAL(clicked()), this, SLOT(plusClicked()));
    connect(this, SIGNAL(auxiliaryPlus()), controller, SLOT(plusClicked()));
    connect(minus, SIGNAL(clicked()), this, SLOT(minusClicked()));
    connect(this, SIGNAL(auxiliaryMinus()), controller, SLOT(minusClicked()));
}

void BinarySearchTab::keepClicked(){
    emit auxiliaryKeep();
}

void BinarySearchTab::plusClicked(){
    emit auxiliaryPlus();
}

void BinarySearchTab::minusClicked(){
    emit auxiliaryMinus();
}

void BinarySearchTab::setTree(BinarySearchTree* t){
    tree->operator =(*t);
    t->elimTree();
    // Testing
}

BinaryTree* BinarySearchTab::getSecondTree() const{
    return tree2;
}

void BinarySearchTab::setSecondTree(BinarySearchTree* t){
    tree2->operator =(*t);
    t->elimTree();
}


HuffmanTab::HuffmanTab(QWidget *parent, Controller* control): Tab(parent,control){
    keep = new QPushButton(tr("KEEP"), this);
    plus = new QPushButton(tr("+"), this);
    compress = new QPushButton(tr("COMPRESS"), this);
    getLayout()->addWidget(plus, 4, 1, 1, 1);
    getLayout()->addWidget(keep, 4, 2, 1, 1);
    getLayout()->addWidget(compress, 5, 0, 2, 3);
    tree = nullptr;
    tree2 = nullptr;

    //fare connessioni..
    // MANCANO CONNESSIONI ?
    // [TODO]
    connect(line, SIGNAL(returnPressed()), this, SLOT(insertClicked()));
    connect(keep, SIGNAL(clicked()), this, SLOT(keepClicked()));
    connect(this, SIGNAL(auxiliaryKeep()), controller, SLOT(keepClicked()));
    connect(plus, SIGNAL(clicked()), this, SLOT(plusClicked()));
    connect(this, SIGNAL(auxiliaryPlus()), controller, SLOT(plusClicked()));
    connect(compress, SIGNAL(clicked()), this, SLOT(compressClicked()));
    connect(this, SIGNAL(auxiliaryCompress()), controller, SLOT(compressClicked()));
}


void HuffmanTab::drawTextCompression(std::map<std::string, std::string>& dict){
    int n_righe = 1;
    int spaziatura = 100;

    cleanScene();

    for(auto it = dict.begin(); it != dict.end(); ++it){
        QGraphicsTextItem* a = new QGraphicsTextItem();
        a->setPos(spaziatura, n_righe*20);
        n_righe++;
        QString tmp = QString::fromStdString(it->first+" -> "+it->second);
        a->setPlainText(tmp);
        scene->addItem(a);
    }
}


void HuffmanTab::keepClicked(){
    emit auxiliaryKeep();
}

void HuffmanTab::plusClicked(){
    emit auxiliaryPlus();
}

void HuffmanTab::compressClicked(){
    emit auxiliaryCompress();
}

void HuffmanTab::setTree(HuffmanTree* t){
    //tree->operator =(*t);
    tree = new HuffmanTree(*t);
}

BinaryTree* HuffmanTab::getSecondTree() const{
    return tree2;
}

void HuffmanTab::setSecondTree(HuffmanTree* t){
    //tree2->operator =(*t);    [TODO] da checkare
    tree2 = new HuffmanTree(*t);
    t->elimTree();
}


AvlTab::AvlTab(QWidget *parent, Controller* control): Tab(parent, control){
    balancedSubTreePre = new QPushButton(tr("SUBTREE PRE"), this);
    balancedSubTreeInv = new QPushButton(tr("SUBTREE INVERT"), this);
    getLayout()->addWidget(balancedSubTreePre, 4, 1, 1, 1);
    getLayout()->addWidget(balancedSubTreeInv, 4, 2, 1, 1);
    tree = new AVLTree;
    tree2 = new AVLTree;

    //fare connessioni..
    connect(balancedSubTreePre, SIGNAL(clicked()), this, SLOT(subTPreClicked()));
    connect(this, SIGNAL(auxiliarySubTPre()), controller, SLOT(subTPreClicked()));
    connect(balancedSubTreeInv, SIGNAL(clicked()), this, SLOT(subTInvClicked()));
    connect(this, SIGNAL(auxiliarySubTInv()), controller, SLOT(subTInvClicked()));
}

void AvlTab::subTPreClicked(){
    emit auxiliarySubTPre();
}

void AvlTab::subTInvClicked(){
    emit auxiliarySubTInv();
}

void AvlTab::setSecondTree(AVLTree* t){
    tree2->operator =(*t);
}

BinaryTree* AvlTab::getSecondTree() const{
    return tree2;
}

TwoThreeTab::TwoThreeTab(QWidget *parent, Controller* control): Tab(parent,control){
    threeNodePre = new QPushButton(tr("3NODE PRE"), this);
    threeNodeInv = new QPushButton(tr("3NODE INVERT"), this);
    getLayout()->addWidget(threeNodePre, 4, 1, 1, 1);
    getLayout()->addWidget(threeNodeInv, 4, 2, 1, 1);
    tree = new TwoThreeTree;

    //fare connessioni..
    connect(line, SIGNAL(returnPressed()), this, SLOT(insertClicked()));
    connect(threeNodePre, SIGNAL(clicked()), this, SLOT(subPreClicked()));
    connect(this, SIGNAL(auxiliarySubPre()), controller, SLOT(subPreClicked()));
    connect(threeNodeInv, SIGNAL(clicked()), this, SLOT(subInvClicked()));
    connect(this, SIGNAL(auxiliarySubInv()), controller, SLOT(subInvClicked()));
}

void TwoThreeTab::subPreClicked(){
    emit auxiliarySubPre();
}

void TwoThreeTab::subInvClicked(){
    emit auxiliarySubInv();
}



//TAB

//rifacciamo il disegno da zero
void Tab::update_draw(BinaryTree* tree){


     if(tree->returnRoot() != nullptr){
        cleanScene(); //cancello il disegno prima
        view->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
        int n_livello = tree->max_depth();   //altezza

        if(n_livello>0){
            //qDebug()<<n_livello;
            int altezza_max = n_livello * 110; //spazio da dedicare al disegno in lunghezza
            int n_ultimo = qPow(2,n_livello); //numero di nodi nell'ultima riga
            int larg = 50 + 25*n_ultimo + 30*(n_ultimo-1);
            scene->setSceneRect(0,0,larg,altezza_max);

            BinaryTree::nodo* no = tree->returnRoot();
            Tipo* auxInt = no->info;
            QString s = QString::fromStdString(auxInt->to_string());
            Node* n = new Node(s);
            //Node* n = new Node(QString::number(no->info));
            n->setPos(10+(25*(n_ultimo/2)) + (30*((n_ultimo/2)-1)) + 15, 10); //posizione primo nodo (centrale)
            scene->addItem(n);  //aggiungo la radice alla scena
            //qDebug() << tree->print();
            int h = 50; //altezza che separa ogni nodo dal livello precedente

            addDrawNode(no, n->pos(), h, 1, n_ultimo);
        }
        else{   //solo un nodo da disegnare
            scene->setSceneRect(0,0,90,90);
            //FARE UNA FUNZIONE PER QUESTE RIGHE
            BinaryTree::nodo* no = tree->returnRoot();
            QString s = QString::fromStdString(no->info->to_string());
            Node* n = new Node(s);
            /*
            Intero* auxInt = dynamic_cast<Intero*>(tree->returnRoot()->info);
            Node* n;
            if(auxInt)
                n = new Node(QString::number(auxInt->getData()));
            Huffman* auxStr = dynamic_cast<Huffman*>(tree->returnRoot()->info);
            if(auxStr)
                n = new Node(QString::fromStdString(auxStr->getData()));
            */
            scene->addItem(n);
        }
    }
}

void Tab::addDrawNode(BinaryTree::nodo* no, QPointF point, int h, int n_livelli, int n_ultimo){
    QPointF temp = point;

    if(no->left){
        Tipo* auxInt = no->left->info;
        QString s = QString::fromStdString(auxInt->to_string());
        Node* n = new Node(s);

        n->setPos(point.rx()-((25*n_ultimo/(qPow(2,n_livelli)) + 30*n_ultimo/(qPow(2,n_livelli)))/2), h);
        scene->addItem(n); //aggiungo il nuovo nodo al disegno
        //coordinate per collegare in modo corretto la linea ai nodi
        double x1 = temp.rx()+12.5;
        double y1 = temp.ry()+25;
        double x2 = n->pos().rx()+12.5;
        double y2 = n->pos().ry();
        scene->addLine(x1, y1, x2, y2);

        addDrawNode(no->left, n->pos(), h+50, n_livelli+1, n_ultimo);  //andiamo a disegnare il prossimo nodo
    }

    if(no->right){
        Tipo* auxInt = no->right->info;
        QString s = QString::fromStdString(auxInt->to_string());
        Node* n = new Node(s);

        n->setPos(point.rx()+((25*n_ultimo/(qPow(2,n_livelli)) + 30*n_ultimo/(qPow(2,n_livelli)))/2), h);
        scene->addItem(n); //aggiungo il nuovo nodo al disegno
        //coordinate per collegare in modo corretto la linea ai nodi
        double x1 = temp.rx()+12.5;
        double y1 = temp.ry()+25;
        double x2 = n->pos().rx()+12.5;
        double y2 = n->pos().ry();
        scene->addLine(x1, y1, x2, y2);

        addDrawNode(no->right, n->pos(), h+50, n_livelli+1, n_ultimo);
    }
}

void Tab::drawOneNode(Node* n){
    cleanScene();
    scene->addItem(n);
}




void Tab::cleanScene(){ //ripulisce la scena e resetta la dimensione
    scene->clear();
    scene->setSceneRect(0,0,300,290);
}


//TWO THREE TAB

void TwoThreeTab::update_draw(BinaryTree* tree){
     if(tree->returnRoot() != nullptr){
        cleanScene(); //cancello il disegno prima
        view->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
        int n_livello = tree->max_depth();   //altezza

        if(n_livello>0){
            int altezza_max = n_livello * 110; //spazio da dedicare al disegno in lunghezza
            int n_ultimo = qPow(2,n_livello); //numero di nodi nell'ultima riga
            int larg = 50 + 25*n_ultimo + 30*(n_ultimo-1);
            scene->setSceneRect(0,0,larg,altezza_max);

            BinaryTree::nodo* nod = tree->returnRoot();
            TwoThreeTree::node* no = dynamic_cast<TwoThreeTree::node*>(nod);
            Tipo* auxInt = no->info;
            QString s = QString::fromStdString(auxInt->to_string());
            Node* n;
            if(no->num == 2){
                Tipo* auxIntP = no->other;
                s.append("&");
                s.append(QString::fromStdString(auxIntP->to_string()));
            }
            n = new Node(s);
            n->setPos(10+(25*(n_ultimo/2)) + (30*((n_ultimo/2)-1)) + 15, 10); //posizione primo nodo (centrale)
            scene->addItem(n);  //aggiungo la radice alla scena
            int h = 50; //altezza che separa ogni nodo dal livello precedente

            addDrawNode(no, n->pos(), h, 1, n_ultimo);
        }
        else{   //solo un nodo da disegnare
            scene->setSceneRect(0,0,90,90);
            //FARE UNA FUNZIONE PER QUESTE RIGHE
            BinaryTree::nodo* nod = tree->returnRoot();
            TwoThreeTree::node* no = dynamic_cast<TwoThreeTree::node*>(nod);
            QString s = QString::fromStdString(no->info->to_string());
            Node* n;
            if(no->num == 2){
                Tipo* auxIntP = no->other;
                s.append("&");
                s.append(QString::fromStdString(auxIntP->to_string()));
            }
            n = new Node(s);
            scene->addItem(n);
        }
    }
}

void TwoThreeTab::addDrawNode(BinaryTree::nodo* nod, QPointF point, int h, int n_livelli, int n_ultimo){
    TwoThreeTree::node* no = dynamic_cast<TwoThreeTree::node*>(nod);
    QPointF temp = point;

    if(no->left){
        //qDebug()<<"TWO TAB left";
        Tipo* auxInt = no->left->info;
        QString s = QString::fromStdString(auxInt->to_string());
        Node* n;

        if(dynamic_cast<TwoThreeTree::node*>(no->left)->num == 2){
            Tipo* auxIntP = dynamic_cast<TwoThreeTree::node*>(no->left)->other;
            s.append("&");
            QString s2 = QString::fromStdString(auxIntP->to_string());
            s.append(&s2);
        }
        n = new Node(s);
        n->setPos(point.rx()-((25*n_ultimo/(qPow(2,n_livelli)) + 30*n_ultimo/(qPow(2,n_livelli)))/2), h);
        scene->addItem(n); //aggiungo il nuovo nodo al disegno
        //coordinate per collegare in modo corretto la linea ai nodi
        double x1 = temp.rx()+12.5;
        double y1 = temp.ry()+25;
        double x2 = n->pos().rx()+12.5;
        double y2 = n->pos().ry();
        scene->addLine(x1, y1, x2, y2);

        addDrawNode(no->left, n->pos(), h+50, n_livelli+1, n_ultimo);  //andiamo a disegnare il prossimo nodo
    }

    if(no->middle){
        Tipo* auxInt = no->middle->info;
        QString s = QString::fromStdString(auxInt->to_string());
        Node* n = new Node(s);
        n->setPos(point.rx()+((25*n_ultimo/(qPow(2,n_livelli)) + 30*n_ultimo/(qPow(2,n_livelli)))/2) - 27.5, h);
        scene->addItem(n); //aggiungo il nuovo nodo al disegno
        //coordinate per collegare in modo corretto la linea ai nodi
        double x1 = temp.rx()+12.5;
        double y1 = temp.ry()+25;
        double x2 = n->pos().rx()+12.5;
        double y2 = n->pos().ry();
        scene->addLine(x1, y1, x2, y2);
    }

    if(no->right){
        //qDebug()<<"TWO TAB right";
        Tipo* auxInt = no->right->info;
        QString s = QString::fromStdString(auxInt->to_string());
        Node* n;
        if(dynamic_cast<TwoThreeTree::node*>(no->right)->num == 2){
            Tipo* auxIntP = dynamic_cast<TwoThreeTree::node*>(no->right)->other;
            s.append("&");
            s.append(QString::fromStdString(auxIntP->to_string()));
        }
        n = new Node(s);
        n->setPos(point.rx()+((25*n_ultimo/(qPow(2,n_livelli)) + 30*n_ultimo/(qPow(2,n_livelli)))/2), h);
        scene->addItem(n); //aggiungo il nuovo nodo al disegno
        //coordinate per collegare in modo corretto la linea ai nodi
        double x1 = temp.rx()+12.5;
        double y1 = temp.ry()+25;
        double x2 = n->pos().rx()+12.5;
        double y2 = n->pos().ry();
        scene->addLine(x1, y1, x2, y2);

        addDrawNode(no->right, n->pos(), h+50, n_livelli+1, n_ultimo);
    }
}
