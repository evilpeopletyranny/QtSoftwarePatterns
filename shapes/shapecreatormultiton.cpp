#include "shapecreatormultiton.h"

QMap<ShapeType, ShapeCreator*> ShapeCreatorMultiton::instances{
    {ShapeType::Rectangle, new RectangleCreator()},
    {ShapeType::Circle, new CircleCreator()},
    {ShapeType::Triangle, new TriangleCreator()}
};

ShapeCreator *ShapeCreatorMultiton::getInstance(ShapeType type)
{
    return instances.value(type);
}
