#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <QGraphicsSceneWheelEvent>

#include "shapes/myshape.h"

/**
 * Базовый абстрактный класс обработчика из цепочки.
 * Паттерн: цепочка обязанностей (chain of responsibility) - поведенческий.
 */
class EventHandler
{
public:
    /**
     * @param modifire тип модификатора, с которым будет работать обработчик
     */
    explicit EventHandler(Qt::KeyboardModifier modifire);
    ~EventHandler();

    /**
     * Задание следующего обработчика
     *
     * @param handler следующий обработчик
     */
    void setNext(EventHandler *handler);

    /**
     * Метод перехвата события
     *
     * @param event событие, связанное с движением колесика на фигуре
     * @param shape фигура, к которой применяется данное событие
     */
    virtual void handle(QGraphicsSceneWheelEvent *event, MyShape *shape);

    /**
     * Обработка события
     *
     * @param event событие, связанное с движением колесика на фигуре
     * @param shape фигура, к которой применяется данное событие
     */
    virtual void eventHandling(QGraphicsSceneWheelEvent* event, MyShape *shape) = 0;

protected:
    EventHandler *nextHandler;      //следующий обработчик
    Qt::KeyboardModifier modifire;  //модификатор
};

#endif // EVENTHANDLER_H
