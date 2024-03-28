#include "circle.h"

Circle::Circle(QPoint leftTopPoint,
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

Circle::~Circle()
{

}

QRectF Circle::boundingRect() const
{
    return shape().boundingRect();
}

QPainterPath Circle::shape() const
{
    QPainterPath path;
    path.addEllipse(getShapePolygon().boundingRect());
    return path;

}

void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(QBrush(color));   //меняем цвет заливки
    painter->setPen(penStyle);          //меняем тип линии

    //рисуем элипс
    painter->drawEllipse(getShapePolygon().boundingRect());

    Q_UNUSED(option);   //Чтобы Qt не ругалось на неиспользуемый параметр.
    Q_UNUSED(widget);   //Чтобы Qt не ругалось на неиспользуемый параметр.
}

QPolygon Circle::getShapePolygon() const
{
    QPolygon polygon;
    polygon << leftTopPoint;
    polygon << QPoint(leftTopPoint.x(), rightBotPoint.y());
    polygon << rightBotPoint;
    polygon << QPoint(rightBotPoint.x(), leftTopPoint.y());
    polygon << leftTopPoint;
    return polygon;

}
