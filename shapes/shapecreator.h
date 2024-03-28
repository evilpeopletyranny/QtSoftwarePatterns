#ifndef SHAPECREATOR_H
#define SHAPECREATOR_H

#include "myshape.h"
#include "commands/shapecommand.h"

/**
 * Базовый абстрактный создатель фигур.
 *
 * Паттерны: фабричный метод.
 */
class ShapeCreator
{
public:
    /**
     * Фабричный метод создания фигуры
     *
     * @param leftTopPoint - левая верхняя точка
     * @param rightBotPoint - правая нижняя точка
     * @param rotation - угол поворота фигуры
     * @param brushStyle - тип заливки
     * @param penStyle - тип линии
     * @return созданная фигура
     */
    virtual MyShape *createShape(QPoint leftTopPoint,
                                 QPoint rightBotPoint,
                                 qreal rotation = 0,
                                 QColor color = QColor(255, 255, 255),
                                 Qt::PenStyle penStyle = Qt::SolidLine) = 0;       //фабричный метод создания фигуры

    /**
     * Фабричный метод создания фигуры через команду
     */
    virtual MyShape *createShape(ShapeCommand *command) = 0;       //фабричный метод создания фигуры
};

#endif // SHAPECREATOR_H
