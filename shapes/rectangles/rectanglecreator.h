#ifndef RECTANGLECREATOR_H
#define RECTANGLECREATOR_H

#include "shapes/shapecreator.h"
#include "shapes/rectangles/rectangle.h"

/**
 * Конкретный создатель фигуры типа квадрат.
 * Реализация шаблоного метода.
 */
class RectangleCreator : public virtual ShapeCreator
{
public:
    explicit RectangleCreator();

    /**
     * Реализация метода создания прямоугольника
     */
    MyShape *createShape(QPoint leftTopPoint,
                         QPoint rightBotPoint,
                         qreal rotation = 0,
                         QColor color = QColor(255, 255, 255),
                         Qt::PenStyle penStyle = Qt::SolidLine) override;

    /**
     * Реализация метода создания прямоугольника через команлу
     */
    MyShape *createShape(ShapeCommand *command) override;

private:
    ~RectangleCreator();
};

#endif // RECTANGLECREATOR_H
