#include "node.h"
#include <QDebug>
#include <QFont>

Node::Node(QString _text, QGraphicsItem* parent): QGraphicsEllipseItem(parent), text(_text) {}
Node::~Node(){}

void Node::paint (QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setRenderHint(QPainter::Antialiasing, true);
    QRectF rec = QRectF(QPoint(0, 0),QSizeF(dimension, dimension));
    painter->setPen(QPen(Qt::black, 1));
    painter->drawEllipse(rec);
    //painter->font().setStretch(150);
//    QFont* f = new QFont();

    QFont f = QFont();

    int n_char = text.size();
    if(n_char>2)    //rimpicciolisce il testo da 3 cifre in poi
        f.setPixelSize(13-n_char);
    painter->setFont(f);
    painter->drawText(rec, Qt::AlignCenter, text);
}

/*
ThreeNode::ThreeNode(QString txt, QString twoTxt): Node(txt), secondText(twoTxt){
    txt.append("&");
    txt.append(secondText);
}
*/
