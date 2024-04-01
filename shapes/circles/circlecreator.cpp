#include "circlecreator.h"

CircleCreator::CircleCreator()
{

}

CircleCreator::~CircleCreator()
{

}

MyShape *CircleCreator::createShape(QPoint leftTopPoint, QPoint rightBotPoint, qreal rotation, QColor color, Qt::PenStyle penStyle)
{
    return new Circle(leftTopPoint, rightBotPoint, rotation, color, penStyle);
}

MyShape *CircleCreator::createShape(ShapeCommand *command)
{
    return createShape(command->getLeftTopPoint(),
                       command->getRightBotPoint(),
                       command->getRotation(),
                       command->getColor(),
                       command->getPenStyle());
}
