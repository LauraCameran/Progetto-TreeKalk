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
    virtual ~Node() {}
    void paint(QPainter* painter, const QStyleOptionGraphicsItem * option, QWidget * widget = nullptr);
};


#endif // NODE_H
