#ifndef SHAPEVIEWWIDGET_H
#define SHAPEVIEWWIDGET_H

#include <QGraphicsView>
#include <QGraphicsScene>

#include "shapescenewidget.h"
#include "shapes/myshape.h"
#include "shapes/rectangles/rectangle.h"
#include "shapes/triangles/triangle.h"
#include "shapes/circles/circle.h"

class ShapeViewWidget : public QGraphicsView
{
public:
    ShapeViewWidget(QWidget *parent = nullptr);
    void addShape(MyShape *shape);
};

#endif // SHAPEVIEWWIDGET_H
