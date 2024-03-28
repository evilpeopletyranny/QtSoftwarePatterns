#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QPainter>
#include <QPolygon>

#include "shapes/myshape.h"

/**
 * Фигура треугольник
 */
class Triangle : public MyShape
{
public:
    /**
     * @param leftTopPoint - левая верхняя точка
     * @param rightBotPoint - правая нижняя точка
     * @param rotation - угол поворота фигуры
     * @param brushStyle - тип заливки
     * @param penStyle - тип линии
     */
    explicit Triangle(QPoint leftTopPoint,
                    QPoint rightBotPoint,
                    qreal rotation = 0,
                    QColor color = QColor(255, 255, 255),
                    Qt::PenStyle penStyle = Qt::SolidLine);
    ~Triangle();

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QPolygon getShapePolygon() const override;
};

#endif // TRIANGLE_H
