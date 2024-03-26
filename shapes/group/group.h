#ifndef GROUP_H
#define GROUP_H

#include <QList>
#include <QDebug>

#include "shapes/myshape.h"

/**
 * Группа фигур
 */
class Group : public MyShape
{
public:
    explicit Group(QList<MyShape *> shapeList);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
//    QRectF boundingRect() const;

private:
    QList<MyShape *> shapeList;

//    QPoint findLeftMost(QList<MyShape *> shapeList);
//    QPoint findRightMost(QList<MyShape *> shapeList);

//    QPoint findLeft(QPoint fPoint, QPoint sPoint);
//    QPoint findRight(QPoint fPoint, QPoint sPoint);


};

#endif // GROUP_H
