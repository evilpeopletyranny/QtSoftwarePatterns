#ifndef SHAPECREATORMULTITON_H
#define SHAPECREATORMULTITON_H

#include <QMap>

#include "shapes/myshape.h"
#include "shapes/shapecreator.h"
#include "shapes/rectangles/rectanglecreator.h"
#include "shapes/circles/circlecreator.h"
#include "shapes/triangles/trianglecreator.h"

/**
 * Мультитон создателей фигур.
 * Суть: иметь по одному экземплятору создателя и получать к ним доступ
 * по ключу.
 */
class ShapeCreatorMultiton
{
public:
    static ShapeCreator *getInstance(ShapeType type);   //получение создателя по ключу

private:
    static QMap<ShapeType, ShapeCreator*> instances;    //Map хранения создателей
};

#endif // SHAPECREATORMULTITON_H
