#include "group.h"

Group::Group(QList<MyShape *> shapeList) :
    MyShape(QPoint(0, 0), QPoint(0, 0))
{
    this->shapeList = shapeList;

    for (auto *shape: shapeList) qDebug() << shape->sceneBoundingRect();

    //    qDebug() << leftTopPoint << rightBotPoint;
}

void Group::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

}
