#include "shapescenewidget.h"

ShapeSceneWidget::ShapeSceneWidget(QObject *parent)
    : QGraphicsScene{parent}
{
    //САМОЕ ВАЖНО! Задание порядка обхода элементов по сцене, его надо отключить
    //иначе с управлением мышкой проблемы
    setItemIndexMethod(QGraphicsScene::NoIndex);

    //Групповой элемент не дефолтный
    auto *group = new Group(QList<MyShape*>(
                                {new Circle(QPoint(200, 200), QPoint(-200, -200)),
                                 new Triangle(QPoint(150, 150), QPoint(-50, -50)),
                                 new Rectangle(QPoint(100, 100), QPoint(0, 0))
                                }));

    addItem(group);
}

void ShapeSceneWidget::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    auto *item = itemAt(event->scenePos(), QTransform());
    if (item != nullptr) sendEvent(item, event);
}

void ShapeSceneWidget::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    auto *item = itemAt(event->scenePos(), QTransform());
    if (item != nullptr && event->buttons() == Qt::LeftButton) sendEvent(item, event);
}

void ShapeSceneWidget::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    auto *item = itemAt(event->scenePos(), QTransform());
    if (item != nullptr) sendEvent(item, event);
}
