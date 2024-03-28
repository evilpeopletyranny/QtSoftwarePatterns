#ifndef SHAPECOMMAND_H
#define SHAPECOMMAND_H

#include <QPoint>

#include "shapes/myshape.h"

/**
 * Паттерн команда.
 * Команда на создание фигуры.
 * Содержит необходимые для создания фигуры сведения.
 */
class ShapeCommand
{
public:
    /**
     * @param shapeType - тип фигуры
     * @param leftTopPoint - левая верхняя точка
     * @param rightBotPoint - правая нижняя точка
     * @param rotation - угол поворота фигуры
     * @param brushStyle - тип заливки
     * @param penStyle - тип линии
     * @return созданная фигура
     */
    explicit ShapeCommand(ShapeType shapeType,
                          QPoint leftTopPoint,
                          QPoint rightBotPoint,
                          qreal rotation = 0,
                          QColor color = QColor(255, 255, 255),
                          Qt::PenStyle penStyle = Qt::SolidLine);

    ShapeType getShapeType() const;

    QPoint getLeftTopPoint() const;

    QPoint getRightBotPoint() const;

    Qt::PenStyle getPenStyle() const;

    qreal getRotation() const;

    const QColor &getColor() const;

private:
    ShapeType shapeType;        //тип фигуры
    QPoint leftTopPoint;        //левая-верхняя точка
    QPoint rightBotPoint;       //правая-нижняя точка
    qreal rotation;             //поворот
    QColor color;               //цвет заливки
    Qt::PenStyle penStyle;      //стиль линии
};

#endif // SHAPECOMMAND_H
