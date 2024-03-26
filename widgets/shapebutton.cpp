#include "shapebutton.h"

ShapeButton::ShapeButton(ShapeType shapeType, QString text, QWidget *parent) :
    QPushButton(text, parent)
{
    this->shapeType = shapeType;
    setFixedHeight(128);
    setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

    //Связываем клик на кнопку с слотом этой же кнопки
    connect(this, &QPushButton::clicked, this, &ShapeButton::emitCreateShapeSignal);
}

void ShapeButton::emitCreateShapeSignal(bool checked)
{
    //Посылаем сигнал о создании фигуры, указав тип фигуры.
    emit createShapeSingal(shapeType);
}
