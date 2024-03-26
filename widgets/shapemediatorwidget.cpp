#include "shapemediatorwidget.h"

ShapeMediatorWidget::ShapeMediatorWidget(QWidget *parent)
    : QWidget{parent}
{    
    editorWidget = new ShapeEditorWidget(this);
    viewWidget = new ShapeViewWidget(this);

    connect(editorWidget, &ShapeEditorWidget::emitCreateShapeCommand, this, &ShapeMediatorWidget::createNewShape);

    setLayout(new QHBoxLayout(this));
    layout()->addWidget(editorWidget);
    layout()->addWidget(viewWidget);
}

void ShapeMediatorWidget::createNewShape(ShapeCommand *command)
{
    viewWidget->addShape(ShapeCreatorMultiton::getInstance(command->getShapeType())->createShape(command));
}
