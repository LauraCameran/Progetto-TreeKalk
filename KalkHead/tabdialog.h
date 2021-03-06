﻿#ifndef TABDIALOG_H
#define TABDIALOG_H

#include "controller.h"

#include <QDialog>
#include <QTableWidget>
#include <QDialogButtonBox>
#include <QFileInfo>
#include <QWidget>
#include <QLineEdit>
#include <QGridLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QString>

// travis

class Controller;
class Node;

class TabDialog : public QDialog{
    Q_OBJECT

public:
    explicit TabDialog(/*const QString& fileName,*/ QWidget *parent = nullptr);
    virtual ~TabDialog();

public slots:
    void helpPressed();
    void errInputSlot();
    void errSecondTreeSlot();
    void triggerHuffmanTest();
    void errNodeSlot();
    void errTreeSlot();
    void errDelSlot();

private:
    QTabWidget *tabWidget;
    QDialogButtonBox *buttonBox;
    Controller* controller;
};


class Tab : public QWidget{
    Q_OBJECT
public:
    Tab(QWidget* parent = nullptr, Controller* c = nullptr);
    virtual ~Tab();

    virtual void update_draw(BinaryTree*);
    virtual void addDrawNode(BinaryTree::nodo*, QPointF, int, int, int);
    virtual void drawOneNode(Node*);
    virtual void cleanScene();
    virtual QLineEdit* getLine() const;
    virtual QGridLayout* getLayout() const;
    virtual BinaryTree* getTree() const;
   // virtual void wheelEvent(QWheelEvent* event);

public slots:
    void insertClicked();
    void linePressed();
    void deleteClicked();
    void searchClicked();
    void maxClicked();
    void minClicked();
    void deleteTreeClicked();
    void showTreeClicked();

signals:
    void auxiliaryIns();
    void auxiliaryLine();
    void auxiliaryDel();
    void auxiliarySearch();
    void auxiliaryMax();
    void auxiliaryMin();
    void auxiliaryDelT();
    void auxiliaryShowT();

protected:

    BinaryTree* tree;
    Controller* controller;
    QGridLayout* mainLayout;
    QLineEdit* line;
    QGraphicsView* view;
    QGraphicsScene* scene;
    QPushButton* insert;
    QPushButton* del;
    QPushButton* search;
    QPushButton* max;
    QPushButton* min;
    QPushButton* delTree;
    QPushButton* showTree;
};


class BinarySearchTab : public Tab{
    Q_OBJECT
public:
    BinarySearchTab(QWidget *parent = nullptr, Controller* control = nullptr);
    void setTree(BinarySearchTree*);
    void setSecondTree(BinarySearchTree*);
    BinaryTree* getSecondTree() const;
    virtual ~BinarySearchTab();

public slots:
    void keepClicked();
    void plusClicked();
    void minusClicked();

signals:
    void auxiliaryKeep();
    void auxiliaryPlus();
    void auxiliaryMinus();

private:
    QPushButton* keep;
    QPushButton* plus;
    QPushButton* minus;
    BinaryTree* tree2;
};


class AvlTab : public Tab{
    Q_OBJECT
public:
    AvlTab(QWidget *parent = 0, Controller* control=0);
    void setSecondTree(AVLTree*);
    BinaryTree* getSecondTree() const;
    virtual ~AvlTab();

public slots:
    void subTPreClicked();
    void subTInvClicked();

signals:
    void auxiliarySubTPre();
    void auxiliarySubTInv();

private:
    QPushButton* balancedSubTreePre;
    QPushButton* balancedSubTreeInv;
    BinaryTree* tree2;
};


class HuffmanTab : public Tab{
    Q_OBJECT
public:
    HuffmanTab(QWidget* parent=0, Controller* control=0);
    void setTree(HuffmanTree*);
    void setSecondTree(HuffmanTree*);
    BinaryTree* getSecondTree() const;
    void drawTextCompression(std::map<std::string, std::string>&);

public slots:
    void keepClicked();
    void plusClicked();
    void compressClicked();

signals:
    void auxiliaryKeep();
    void auxiliaryPlus();
    void auxiliaryCompress();

private:
    QPushButton* plus;
    QPushButton* compress;
    QPushButton* keep;
    BinaryTree* tree2;
};


class TwoThreeTab : public Tab{
    Q_OBJECT
public:
    explicit TwoThreeTab(QWidget *parent = 0, Controller* control=0);
    ~TwoThreeTab();
    void update_draw(BinaryTree*);
    void addDrawNode(BinaryTree::nodo*, QPointF, int, int, int);

public slots:
    void subPreClicked();
    void subInvClicked();

signals:
    void auxiliarySubPre();
    void auxiliarySubInv();

private:
    QPushButton* threeNodePre;
    QPushButton* threeNodeInv;
};


#endif // TABDIALOG_H
