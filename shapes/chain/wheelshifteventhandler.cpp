#include "wheelshifteventhandler.h"

WheelShiftEventHandler::WheelShiftEventHandler(Qt::KeyboardModifier modifire) :
    EventHandler(modifire)
{

}

/**
 * С модификатором нажатый шифт - увеличиваем фигуру
 */
void WheelShiftEventHandler::eventHandling(QGraphicsSceneWheelEvent* event, MyShape *shape)
{
    shape->resize(event->delta()/120);
}
