#ifndef SHAPEBUTTON_H
#define SHAPEBUTTON_H

#include <QPushButton>
#include <QWidget>

#include "shapes/myshape.h"

/**
 * Кнопка создания фигуры.
 * Хранит в себе тип фигуры.
 * При нажатии посылает сигнал с командой - ShapeCommand
 */
class ShapeButton : public QPushButton
{
    Q_OBJECT
public:
    explicit ShapeButton(ShapeType shapeType, QString text, QWidget *parent = nullptr);

signals:
    /**
     * Сигнал о создании фигуры.
     * @param shapeType тип фигуры
     */
    void createShapeSingal(ShapeType shapeType);

private:
    ShapeType shapeType;    //храним тип фигуры

private slots:
    /**
     * Слот с которым связывается клик по кнопке.
     */
    void emitCreateShapeSignal(bool checked = false);
};

#endif // SHAPEBUTTON_H
