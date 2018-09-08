#include "node.h"
#include <QFont>

Node::Node(QString _text, QGraphicsItem* parent): QGraphicsEllipseItem(parent), text(_text) {}

void Node::paint (QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget){
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setRenderHint(QPainter::Antialiasing, true);
    QRectF rec = QRectF(QPoint(0, 0),QSizeF(dimension, dimension));
    painter->setPen(QPen(Qt::black, 1));
    painter->drawEllipse(rec);
    QFont f = QFont();
    int n_char = text.size();
    if(n_char>2)    //rimpicciolisce il testo da 3 cifre in poi
        f.setPixelSize(13-n_char);
    painter->setFont(f);
    painter->drawText(rec, Qt::AlignCenter, text);
}
