#ifndef GROUP_H
#define GROUP_H

#include <QPainter>
#include <QPolygon>

#include "shapes/myshape.h"

/**
 * Собственный класс группы фигур.
 * Над ним пока ведется работа.
 */
class Group : public MyShape
{
public:
    explicit Group(QList<MyShape *> shapeList);

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);



private:
    QList<MyShape *> shapeList;

protected:
    QPolygon getShapePolygon() const;
};

#endif // GROUP_H
