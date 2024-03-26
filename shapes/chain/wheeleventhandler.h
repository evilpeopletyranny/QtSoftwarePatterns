#ifndef WHEELEVENTHANDLER_H
#define WHEELEVENTHANDLER_H

#include "eventhandler.h"
#include "shapes/myshape.h"

/**
 * Обработчик движения колеса без модификаторов
 */
class WheelEventHandler : public EventHandler
{
public:
    WheelEventHandler(Qt::KeyboardModifier modifire);
    void eventHandling(QGraphicsSceneWheelEvent* event, MyShape *shape) override;
};

#endif // WHEELEVENTHANDLER_H
