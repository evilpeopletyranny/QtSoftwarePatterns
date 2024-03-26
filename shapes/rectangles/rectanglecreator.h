#ifndef RECTANGLECREATOR_H
#define RECTANGLECREATOR_H

#include "shapes/shapecreator.h"
#include "shapes/rectangles/rectangle.h"

/**
 * Конкретный создатель фигуры типа квадрат.
 * Реализация шаблоного метода.
 *
 * Таже является синглтоном. (Прост, оно на самом деле не надо)
 */
class RectangleCreator : public virtual ShapeCreator
{
public:
    /**
     * @return единственный экземпляр
     */
    static RectangleCreator *getInstance();

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
    explicit RectangleCreator();
    ~RectangleCreator();

    static RectangleCreator *instance;      //ссылка на едиственный экземпляр
};

#endif // RECTANGLECREATOR_H
