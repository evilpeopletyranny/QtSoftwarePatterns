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

void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(QBrush(color));   //меняем цвет заливки
    painter->setPen(penStyle);          //меняем тип линии

    //рисуем элипс
    painter->drawEllipse(QRectF(leftTopPoint, rightBotPoint));

    Q_UNUSED(option);   //Чтобы Qt не ругалось на неиспользуемый параметр.
    Q_UNUSED(widget);   //Чтобы Qt не ругалось на неиспользуемый параметр.
}
