#include "rectanglecreator.h"

RectangleCreator::RectangleCreator()
{

}

RectangleCreator::~RectangleCreator()
{

}

MyShape *RectangleCreator::createShape(QPoint leftTopPoint, QPoint rightBotPoint, qreal rotation, QColor color, Qt::PenStyle penStyle)
{
    return new Rectangle(leftTopPoint, rightBotPoint, rotation, color, penStyle);
}

MyShape *RectangleCreator::createShape(ShapeCommand *command)
{
    return createShape(command->getLeftTopPoint(),
                       command->getRightBotPoint(),
                       command->getRotation(),
                       command->getColor(),
                       command->getPenStyle());
}
