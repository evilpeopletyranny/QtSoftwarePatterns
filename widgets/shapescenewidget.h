#ifndef SHAPESCENEWIDGET_H
#define SHAPESCENEWIDGET_H

#include <QDebug>

#include <QGraphicsScene>
#include <QGraphicsSceneEvent>
#include <QGraphicsItem>

#include "shapes/group/group.h"

class ShapeSceneWidget : public QGraphicsScene
{
public:
    explicit ShapeSceneWidget(QObject *parent = nullptr);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // SHAPESCENEWIDGET_H
