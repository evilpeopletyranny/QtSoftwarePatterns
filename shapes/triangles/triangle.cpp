#include "triangle.h"

Triangle::Triangle(QPoint leftTopPoint,
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

Triangle::~Triangle()
{

}

QRectF Triangle::boundingRect() const
{
    return shape().boundingRect();
}

QPainterPath Triangle::shape() const
{
    QPainterPath path;
    path.addPolygon(getShapePolygon());
    return path;
}

void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //тяжелые математические расчеты, чтобы вписать треугольник в прямоугольник
    painter->setBrush(QBrush(color));   //меняем цвет заливки
    painter->setPen(penStyle);          //меняем тип линии

    //Рисуем треугольник через полигон
    painter->drawPolygon(getShapePolygon());

    Q_UNUSED(option);   //Чтобы Qt не ругалось на неиспользуемый параметр.
    Q_UNUSED(widget);   //Чтобы Qt не ругалось на неиспользуемый параметр.
}

QPolygon Triangle::getShapePolygon() const
{
    QPolygon polygon;
    polygon << QPoint(leftTopPoint.x(), rightBotPoint.y());
    polygon << QPoint((leftTopPoint.x() + (rightBotPoint.x()-leftTopPoint.x())/2), leftTopPoint.y());
    polygon << rightBotPoint;
    return polygon;
}
