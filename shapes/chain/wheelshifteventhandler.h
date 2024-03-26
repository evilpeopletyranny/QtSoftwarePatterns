#ifndef WHEELSHIFTEVENTHANDLER_H
#define WHEELSHIFTEVENTHANDLER_H

#include "eventhandler.h"

class WheelShiftEventHandler : public EventHandler
{
public:
    WheelShiftEventHandler(Qt::KeyboardModifier modifire);

    void eventHandling(QGraphicsSceneWheelEvent* event, MyShape *shape) override;
};

#endif // WHEELSHIFTEVENTHANDLER_H
