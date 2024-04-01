#ifndef CIRCLECREATOR_H
#define CIRCLECREATOR_H

#include "shapes/shapecreator.h"
#include "shapes/circles/circle.h"


/**
 * Конкретный создатель фигуры типа круг.
 * Реализация шаблоного метода.
 */
class CircleCreator : public virtual ShapeCreator
{
public:
    explicit CircleCreator();

    /**
     * Реализация метода создания круга
     */
    MyShape *createShape(QPoint leftTopPoint,
                         QPoint rightBotPoint,
                         qreal rotation = 0,
                         QColor color = QColor(255, 255, 255),
                         Qt::PenStyle penStyle = Qt::SolidLine) override;

    /**
     * Реализация метода создания круга через команлу
     */
    MyShape *createShape(ShapeCommand *command) override;

private:
    ~CircleCreator();
};

#endif // CIRCLECREATOR_H
