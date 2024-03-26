#include "rectanglecreator.h"

RectangleCreator *RectangleCreator::instance = nullptr;

RectangleCreator::RectangleCreator()
{

}

RectangleCreator::~RectangleCreator()
{

}

RectangleCreator *RectangleCreator::getInstance()
{
    if (instance == nullptr) instance = new RectangleCreator();
    return instance;
}

MyShape *RectangleCreator::createShape(QPoint leftTopPoint, QPoint rightBotPoint, qreal rotation, QColor color, Qt::PenStyle penStyle)
{
    return new Rectangle(leftTopPoint, rightBotPoint, rotation, color, penStyle);
}

MyShape *RectangleCreator::createShape(ShapeCommand *command)
{
    return new Rectangle(command->getLeftTopPoint(),
                         command->getRightBotPoint(),
                         command->getRotation(),
                         command->getColor(),
                         command->getPenStyle());
}
