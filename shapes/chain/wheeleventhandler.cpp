#include "wheeleventhandler.h"

WheelEventHandler::WheelEventHandler(Qt::KeyboardModifier modifire) :
    EventHandler(modifire)
{

}

/**
 * Без модификатора поворачиваем фигуру
 */
void WheelEventHandler::eventHandling(QGraphicsSceneWheelEvent* event, MyShape *shape)
{
    shape->rotate(event->delta()/120);
}
