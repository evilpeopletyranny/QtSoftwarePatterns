#ifndef CIRCLE_H
#define CIRCLE_H

#include <QPainter>

#include "shapes/myshape.h"

/**
 * Фигура круг
 */
class Circle : public MyShape
{
public:
    /**
     * @param leftTopPoint - левая верхняя точка
     * @param rightBotPoint - правая нижняя точка
     * @param rotation - угол поворота фигуры
     * @param brushStyle - тип заливки
     * @param penStyle - тип линии
     */
    explicit Circle(QPoint leftTopPoint,
                    QPoint rightBotPoint,
                    qreal rotation = 0,
                    QColor color = QColor(255, 255, 255),
                    Qt::PenStyle penStyle = Qt::SolidLine);

    ~Circle();

    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QPolygon getShapePolygon() const override;
};

#endif // CIRCLE_H
