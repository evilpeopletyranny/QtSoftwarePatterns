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

void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //тяжелые математические расчеты, чтобы вписать треугольник в прямоугольник
    QPolygon polygon;
    polygon << QPoint(leftTopPoint.x(), rightBotPoint.y());
    polygon << QPoint((leftTopPoint.x() + (rightBotPoint.x()-leftTopPoint.x())/2), leftTopPoint.y());
    polygon << rightBotPoint;

    painter->setBrush(QBrush(color));   //меняем цвет заливки
    painter->setPen(penStyle);          //меняем тип линии

    //Рисуем треугольник через полигон
    painter->drawPolygon(polygon);

    Q_UNUSED(option);   //Чтобы Qt не ругалось на неиспользуемый параметр.
    Q_UNUSED(widget);   //Чтобы Qt не ругалось на неиспользуемый параметр.
}
