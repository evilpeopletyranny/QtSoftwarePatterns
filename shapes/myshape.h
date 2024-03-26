#ifndef SHAPE_H
#define SHAPE_H

#include <QDebug>
#include <QObject>
#include <QGraphicsItem>
#include <QCursor>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>
#include <QColor>
#include <QRectF>

class EventHandler;

/**
 * Базовый абстрактный класс фигур.
 * Содержит паттерн Мост: цвет и тип фигуры
 *
 * Просто Shape конфликтует с типом QFrame::Shape
 */
class MyShape : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    /**
     * Любая фигура строиться по двум точкам, которые описывают
     * прямоугольник, куда вписывается фигура
     *
     * @param leftTopPoint - левая верхняя точка
     * @param rightBotPoint - правая нижняя точка
     * @param rotation - угол поворота фигуры
     * @param brushStyle - тип заливки
     * @param penStyle - тип линии
     */
    explicit MyShape(QPoint leftTopPoint,
                   QPoint rightBotPoint,
                   qreal rotation = 0,
                   QColor color = QColor(255, 255, 255),
                   Qt::PenStyle penStyle = Qt::SolidLine);


    virtual ~MyShape(){};

    /**
     * Изменение размеры фигуры.
     * Изменение фигуры происходит за счет изменение прямоугольника, в который она вписывается.
     *
     * @param pixelCount насколько пикселей *2 будет меняться размер.
     *          Двигается при этом верхняя левая точка и правая нижняя, поэтому происходит изменение
     *          как бы в два раза.
     */
    void resize(int pixelCount);

    /**
     * Поворот фигуры.
     *
     * @param degree угол поворота, который прибавляется к текущему.
     */
    void rotate(int degree);

    QPoint getLeftTopPoint() const;
    void setLeftTopPoint(QPoint newLeftTopPoint);

    QPoint getRightBotPoint() const;
    void setRightBotPoint(QPoint newRightBotPoint);


    Qt::PenStyle getPenStyle() const;
    void setPenStyle(Qt::PenStyle newPenStyle);

    const QColor &getColor() const;
    void setColor(const QColor &newColor);

    /**
     * Метод отрисовки фигуры.
     * Для каждой фигуры свой.
     */
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) = 0;


protected:
    QPoint leftTopPoint;        //левая-верхняя точка
    QPoint rightBotPoint;       //правая-нижняя точка

    //Передача цвета заливки
    //И типа линии при помощи композции - это паттерн МОСТ
    QColor color;               //цвет заливки
    Qt::PenStyle penStyle;      //стиль линии

    /**
     * Метод, выделяющий место по фигуру на сцене.
     * Возвращаемый QRectF это та область, в которой можно будет взаимодействовать фигура.
     * QRectF не равен размеру фигуры.
     *
     * Например: при пустом QRectF вы не сможете никак кликнуть на фигуру, потому что у нее нет
     * области для взаимодействия.
     */
    QRectF boundingRect() const;


    /**
     * Реакция на движение колесика мыши, когда курсор на фигуре. (Зависит от boundingRect кста).
     * @param event событие движения колесика мыши
     */
    void wheelEvent(QGraphicsSceneWheelEvent *event);



private:
    /**
     * Chain of Resposibility для обработки движдения колесика с разными
     * модификаторами.
     * Просто чтобы было. В дальнейшем можно увеличить кол-во обработчиков.
     */
    static EventHandler *eventChain;
    static EventHandler *initChain();

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

/**
 * Перечисление типов фигур.
 *
 * @brief The ShapeEnum enum
 */
enum class ShapeType: int
{
    Rectangle = 0,
    Triangle = 1,
    Circle = 2
};
Q_DECLARE_METATYPE(ShapeType);

#endif // SHAPE_H
