#ifndef NODE_H
#define NODE_H
#include <QGraphicsItem>
#include <QPainter>
#include <QPaintEvent>

class Node : public QGraphicsEllipseItem{
protected:
    const unsigned int dimension = 25;
    QString text;
public:
    Node(QString, QGraphicsItem* = Q_NULLPTR);
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0 );
};

/*
class ThreeNode : public Node{
private:
    QString secondText;
public:
    ThreeNode(QString, QString);
}
*/

#endif // NODE_H
