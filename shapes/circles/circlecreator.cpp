#include "circlecreator.h"

CircleCreator *CircleCreator::instance = nullptr;

CircleCreator::CircleCreator()
{

}

CircleCreator::~CircleCreator()
{

}

CircleCreator *CircleCreator::getInstance()
{
    if (instance == nullptr) instance = new CircleCreator();
    return instance;
}

MyShape *CircleCreator::createShape(QPoint leftTopPoint, QPoint rightBotPoint, qreal rotation, QColor color, Qt::PenStyle penStyle)
{
    return new Circle(leftTopPoint, rightBotPoint, rotation, color, penStyle);
}

MyShape *CircleCreator::createShape(ShapeCommand *command)
{
    return new Circle(command->getLeftTopPoint(),
                      command->getRightBotPoint(),
                      command->getRotation(),
                      command->getColor(),
                      command->getPenStyle());
}
