#include "rectangle.h"

Rectangle::Rectangle(QPoint leftTopPoint,
                     QPoint rightBotPoint,
                     qreal rotation,
                     QColor color,
                     Qt::PenStyle penStyle) :
          MyShape(leftTopPoint,
                rightBotPoint,
                rotation,
                color,
                penStyle)
{

}

Rectangle::~Rectangle()
{

}

QPainterPath Rectangle::shape() const
{
    QPainterPath path;
    path.addPolygon(getShapePolygon());
    return path;
}

void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(QBrush(color));   //меняем цвет заливки
    painter->setPen(penStyle);          //меняем тип линии

    //рисуем полигон фигуры
    painter->drawPolygon(getShapePolygon());

    Q_UNUSED(option);   //Чтобы Qt не ругалось на неиспользуемый параметр.
    Q_UNUSED(widget);   //Чтобы Qt не ругалось на неиспользуемый параметр.
}

QPolygon Rectangle::getShapePolygon() const
{
    QPolygon polygon;
    polygon << leftTopPoint;
    polygon << QPoint(leftTopPoint.x(), rightBotPoint.y());
    polygon << rightBotPoint;
    polygon << QPoint(rightBotPoint.x(), leftTopPoint.y());
    polygon << leftTopPoint;
    return polygon;
}
