#include "eventhandler.h"

EventHandler::EventHandler(Qt::KeyboardModifier modifire)
{
    this->modifire = modifire;
    this->nextHandler = nullptr;
}

EventHandler::~EventHandler()
{

}

void EventHandler::setNext(EventHandler *handler)
{
    this->nextHandler = handler;
}

void EventHandler::handle(QGraphicsSceneWheelEvent *event, MyShape *shape)
{
    //Если модификатор совпадает - обрабатываем
    if (event->modifiers() == modifire) eventHandling(event, shape);

    //Иначе, если есть следующий обработчик - передаем дальше
    //если следующего обработчика нет - ничего не делаем
    if (nextHandler != nullptr) nextHandler->handle(event, shape);
}
