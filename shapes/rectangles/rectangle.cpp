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

void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(QBrush(color));   //меняем цвет заливки
    painter->setPen(penStyle);          //меняем тип линии

    //рисуем прямоугольник
    painter->drawRect(QRectF(leftTopPoint, rightBotPoint));

    Q_UNUSED(option);   //Чтобы Qt не ругалось на неиспользуемый параметр.
    Q_UNUSED(widget);   //Чтобы Qt не ругалось на неиспользуемый параметр.
}
