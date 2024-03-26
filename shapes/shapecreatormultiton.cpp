#include "shapecreatormultiton.h"

QMap<ShapeType, ShapeCreator*> ShapeCreatorMultiton::instances{
    {ShapeType::Rectangle, RectangleCreator::getInstance()},
    {ShapeType::Circle, CircleCreator::getInstance()},
    {ShapeType::Triangle, TriangleCreator::getInstance()}
};

ShapeCreator *ShapeCreatorMultiton::getInstance(ShapeType type)
{
    return instances.value(type);
}
