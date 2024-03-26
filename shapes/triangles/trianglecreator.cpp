#include "trianglecreator.h"

TriangleCreator *TriangleCreator::instance = nullptr;

TriangleCreator *TriangleCreator::getInstance()
{
    if (instance == nullptr) instance = new TriangleCreator();
    return instance;
}

MyShape *TriangleCreator::createShape(QPoint leftTopPoint, QPoint rightBotPoint, qreal rotation, QColor color, Qt::PenStyle penStyle)
{
    return new Triangle(leftTopPoint, rightBotPoint, rotation, color, penStyle);
}

MyShape *TriangleCreator::createShape(ShapeCommand *command)
{
    return new Triangle(command->getLeftTopPoint(),
                        command->getRightBotPoint(),
                        command->getRotation(),
                        command->getColor(),
                        command->getPenStyle());
}

TriangleCreator::TriangleCreator()
{

}
