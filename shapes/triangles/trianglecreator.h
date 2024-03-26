#ifndef TRIANGLECREATOR_H
#define TRIANGLECREATOR_H

#include "shapes/shapecreator.h"
#include "shapes/triangles/triangle.h"


/**
 * Конкретный создатель фигуры типа треугольник.
 * Реализация шаблоного метода.
 *
 * Таже является синглтоном. (Прост, оно на самом деле не надо)
 */
class TriangleCreator : public virtual ShapeCreator
{
public:
    /**
     * @return единственный экземпляр
     */
    static TriangleCreator *getInstance();

    /**
     * Реализация метода создания треугольника
     */
    MyShape *createShape(QPoint leftTopPoint,
                       QPoint rightBotPoint,
                       qreal rotation = 0,
                       QColor color = QColor(255, 255, 255),
                       Qt::PenStyle penStyle = Qt::SolidLine) override;

    /**
     * Реализация метода создания треугольника через команду
     */
    MyShape *createShape(ShapeCommand *command) override;

private:
    explicit TriangleCreator();
    ~TriangleCreator();

    static TriangleCreator *instance;       //ссылка на едиственный экземпляр
};

#endif // TRIANGLECREATOR_H
