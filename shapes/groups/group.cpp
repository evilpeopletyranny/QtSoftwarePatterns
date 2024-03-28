#include "group.h"

Group::Group(QList<MyShape *> shapeList) :
    MyShape(QPoint(0, 0), QPoint(0, 0))
{
    this->shapeList = shapeList;
}

QRectF Group::boundingRect() const
{
    return shape().boundingRect();
}

QPainterPath Group::shape() const
{
    QPainterPath path;
    path.addPolygon(getShapePolygon());
    return path;
}

void Group::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    for (MyShape *shape: shapeList) shape->paint(painter, option, widget);

    Q_UNUSED(option);   //Чтобы Qt не ругалось на неиспользуемый параметр.
    Q_UNUSED(widget);   //Чтобы Qt не ругалось на неиспользуемый параметр.
}

QPolygon Group::getShapePolygon() const
{
    QPolygon polygon;
    for (MyShape *shape: shapeList) polygon = polygon.united(shape->getShapePolygon());
    return polygon;
}
