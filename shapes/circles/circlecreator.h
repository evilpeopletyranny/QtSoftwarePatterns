#ifndef CIRCLECREATOR_H
#define CIRCLECREATOR_H

#include "shapes/shapecreator.h"
#include "shapes/circles/circle.h"


/**
 * Конкретный создатель фигуры типа круг.
 * Реализация шаблоного метода.
 *
 * Таже является синглтоном. (Прост, оно на самом деле не надо)
 */
class CircleCreator : public virtual ShapeCreator
{
public:
    /**
     * @return единственный экземпляр
     */
    static CircleCreator *getInstance();

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
    explicit CircleCreator();
    ~CircleCreator();

    static CircleCreator *instance;     //ссылка на едиственный экземпляр


};

#endif // CIRCLECREATOR_H
