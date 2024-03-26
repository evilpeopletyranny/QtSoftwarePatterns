#include "shapeviewwidget.h"

ShapeViewWidget::ShapeViewWidget(QWidget *parent) :
    QGraphicsView(parent)
{
    setScene(new ShapeSceneWidget(this));
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    setRenderHint(QPainter::Antialiasing);
    setCacheMode(QGraphicsView::CacheBackground);
    setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
}

void ShapeViewWidget::addShape(MyShape *shape)
{
    scene()->addItem(shape);
    scene()->update();
}
