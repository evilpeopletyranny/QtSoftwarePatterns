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

void ShapeCommand::setShapeType(ShapeType newShapeType)
{
    shapeType = newShapeType;
}

QPoint ShapeCommand::getLeftTopPoint() const
{
    return leftTopPoint;
}

void ShapeCommand::setLeftTopPoint(QPoint newLeftTopPoint)
{
    leftTopPoint = newLeftTopPoint;
}

QPoint ShapeCommand::getRightBotPoint() const
{
    return rightBotPoint;
}

void ShapeCommand::setRightBotPoint(QPoint newRightBotPoint)
{
    rightBotPoint = newRightBotPoint;
}

Qt::PenStyle ShapeCommand::getPenStyle() const
{
    return penStyle;
}

void ShapeCommand::setPenStyle(Qt::PenStyle newPenStyle)
{
    penStyle = newPenStyle;
}

qreal ShapeCommand::getRotation() const
{
    return rotation;
}

void ShapeCommand::setRotation(qreal newRotation)
{
    rotation = newRotation;
}

const QColor &ShapeCommand::getColor() const
{
    return color;
}

void ShapeCommand::setColor(const QColor &newColor)
{
    color = newColor;
}
