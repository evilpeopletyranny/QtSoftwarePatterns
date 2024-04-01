#include "trianglecreator.h"

MyShape *TriangleCreator::createShape(QPoint leftTopPoint, QPoint rightBotPoint, qreal rotation, QColor color, Qt::PenStyle penStyle)
{
    return new Triangle(leftTopPoint, rightBotPoint, rotation, color, penStyle);
}

MyShape *TriangleCreator::createShape(ShapeCommand *command)
{
    return createShape(command->getLeftTopPoint(),
                       command->getRightBotPoint(),
                       command->getRotation(),
                       command->getColor(),
                       command->getPenStyle());
}

TriangleCreator::TriangleCreator()
{

}
