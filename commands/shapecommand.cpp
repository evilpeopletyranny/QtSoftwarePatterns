#include "shapecommand.h"

ShapeCommand::ShapeCommand(ShapeType shapeType,
                           QPoint leftTopPoint,
                           QPoint rightBotPoint,
                           qreal rotation,
                           QColor color,
                           Qt::PenStyle penStyle)
{
    this->shapeType = shapeType;
    this->leftTopPoint = leftTopPoint;
    this->rightBotPoint = rightBotPoint;
    this->rotation = rotation,
    this->color = color;
    this->penStyle = penStyle;
}

ShapeType ShapeCommand::getShapeType() const
{
    return shapeType;
}


QPoint ShapeCommand::getLeftTopPoint() const
{
    return leftTopPoint;
}


QPoint ShapeCommand::getRightBotPoint() const
{
    return rightBotPoint;
}


Qt::PenStyle ShapeCommand::getPenStyle() const
{
    return penStyle;
}

qreal ShapeCommand::getRotation() const
{
    return rotation;
}

const QColor &ShapeCommand::getColor() const
{
    return color;
}
