#ifndef SHAPEMEDIATORWIDGET_H
#define SHAPEMEDIATORWIDGET_H

#include <QDebug>

#include <QWidget>
#include <QHBoxLayout>

#include "shapes/shapecreatormultiton.h"
#include "commands/shapecommand.h"
#include "shapeeditorwidget.h"
#include "shapeviewwidget.h"

/**
 *
 * Паттерн: Посредник/Mediator
 * Виджет содержащий сцену и виджет отвечающий за создание фигур.
 * Обменивается командами между виджетом созданием и сценой
 *
 * @brief The ShapeMediatorWidget class
 */
class ShapeMediatorWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ShapeMediatorWidget(QWidget *parent = nullptr);

private:
    ShapeEditorWidget *editorWidget;    //виджет, отвечающий за получение данных о создаваемой фигуре
    ShapeViewWidget *viewWidget;        //виджет отображения фигур

private slots:
    /**
     * Получив команду создания, передаем ее в ShapeViewWidget
     */
    void createNewShape(ShapeCommand *command);
};

#endif // SHAPEMEDIATORWIDGET_H
