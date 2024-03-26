#ifndef SHAPEEDITORWIDGET_H
#define SHAPEEDITORWIDGET_H

#include <QWidget>
#include <QScrollArea>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPainter>
#include <QColorDialog>
#include <QComboBox>
#include <QDebug>
#include <QPalette>
#include <QList>

#include "shapebutton.h"
#include "dialogs/windowmanager.h"
#include "commands/shapecommand.h"


//TODO: чот много и стремно
/**
 * Виджет, содержащий scrollArea с кнопками создания фигур.
 * На сигнал от нажатия кнопок формирует команду и посылает дальше.
 */
class ShapeEditorWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ShapeEditorWidget(QWidget *parent = nullptr);

signals:
    /**
     * Сигнал, посылающую команду о создании фигуры.
     * @param command команда, содержащая данные о фигуре.
     */
    void emitCreateShapeCommand(ShapeCommand *command);

private:
    QPushButton *colorButton;       //кнопка, отвечающая за цвет фигуры
    QComboBox *lineStyleBox;        //выпадающий список с типом линии

    /**
     * Создание кнопки выбора цвета.
     */
    QPushButton *initColorButton(QWidget *parent);

    /**
     * Создание списка выбора типа линии.
     */
    QComboBox *initLineStyleBox(QWidget *parent);

    /**
     * Создание scrollArea с кнопками создания фигур.
     * @param buttonList список кнопок, которые необходимо добавить.
     */
    QScrollArea *initScrollArea(QList<ShapeButton*> buttonList, QWidget *parent);

    /**
     * Связывание диалога выбора цвета с нажатием кнопки выбора цвета.
     */
    QColorDialog *linkColorDialogToButton(QPushButton *button);

    /**
     * Смена цвета кнопки
     */
    void changeColorButton(QPushButton *button, QColor color);

    Qt::PenStyle getCurrentPenStyle();      //получение текущего типа линии
    QColor getCurrentColor();               //получение текущего цвета заливки

private slots:
    /**
     * Слот, реагирующий на выбор цвета в цветовом диалоге.
     * @param выбранный цвет.
     */
    void changeCurrentColor(QColor color);

    /**
     * Слот, реагирующий на нажатие кнокпи создания фигуры.
     * @param shapeType тип фигуры на создание.
     */
    void createShapeCommand(ShapeType shapeType);
};

#endif // SHAPEEDITORWIDGET_H
