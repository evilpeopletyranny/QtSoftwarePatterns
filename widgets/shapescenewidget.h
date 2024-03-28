#ifndef SHAPESCENEWIDGET_H
#define SHAPESCENEWIDGET_H

#include <QDebug>

#include <QGraphicsScene>
#include <QGraphicsSceneEvent>
#include <QGraphicsItem>

#include <QGraphicsItemGroup>

#include "shapes/myshape.h"

#include "shapes/rectangles/rectangle.h"
#include "shapes/triangles/triangle.h"
#include "shapes/circles/circle.h"

#include "shapes/groups/group.h"

class ShapeSceneWidget : public QGraphicsScene
{
public:
    explicit ShapeSceneWidget(QObject *parent = nullptr);

protected:
/*
    Для создания группы фигур мы хотим выделять несколько фигур, а потом использовать выделенные.
    Делать это мы можем только в классе сцены.

    Для этого надо будет переопределять стандартное поведение сцены и мышки.
    Пока что там просто заглушки.

    ВАЖНО! Переопределяя поведение сцены, события мышки перестают доходить до фигур по умолчанию.
    Теперь нам надо собственно ручно прокидывать событие со сцены к фигуре:

    auto *item = itemAt(event->scenePos(), QTransform());   //получение фигуры под курсором
    if (item != nullptr) sendEvent(item, event);            //передача события фигуре
*/
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // SHAPESCENEWIDGET_H
