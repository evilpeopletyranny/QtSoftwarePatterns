#include "shapescenewidget.h"

ShapeSceneWidget::ShapeSceneWidget(QObject *parent)
    : QGraphicsScene{parent}
{
    //САМОЕ ВАЖНО! Задание порядка обхода элементов по сцене, его надо отключить
    //иначе с управлением мышкой проблемы
    setItemIndexMethod(QGraphicsScene::NoIndex);
}

void ShapeSceneWidget::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    auto *item = itemAt(event->scenePos(), QTransform());
    if (item != nullptr) sendEvent(item, event);

    if (event->modifiers() == Qt::ControlModifier) {
        item->setSelected(true);
    }

    if (!selectedItems().isEmpty() && event->button() == Qt::RightButton) {
        QList<MyShape *> list;
        for (auto *shape: selectedItems()) list.append(dynamic_cast<MyShape*>(shape));
        addItem(new Group(list));
    }
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
