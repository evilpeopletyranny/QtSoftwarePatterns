#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QPainter>

#include "shapes/myshape.h"

/**
 * Фигура прямоугольник
 */
class Rectangle : public MyShape
{
public:
    /**
     * @param leftTopPoint - левая верхняя точка
     * @param rightBotPoint - правая нижняя точка
     * @param rotation - угол поворота фигуры
     * @param brushStyle - тип заливки
     * @param penStyle - тип линии
     */
    explicit Rectangle(QPoint leftTopPoint,
                       QPoint rightBotPoint,
                       qreal rotation = 0,
                       QColor color = QColor(255, 255, 255),
                       Qt::PenStyle penStyle = Qt::SolidLine);
    ~Rectangle();

protected:
    /**
     * ПереопределЯем рисование для прямоугольника
     */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // RECTANGLE_H
