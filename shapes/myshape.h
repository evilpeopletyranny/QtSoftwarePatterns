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

    QPoint getRightBotPoint() const;

    Qt::PenStyle getPenStyle() const;

    const QColor &getColor() const;

    /**
     * Метод отрисовки фигуры.
     * Для каждой фигуры свой.
     * Использует полигон фигуры.
     */
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) = 0;

    /**
     * Для сложных фигур, которые являются примитивом (например собственно писанная группа фигур, как хочет Лепехин)
     * не достаточно метода boundingRect, посколько он выделяет лишь квадртаную область.
     * Мало того, даже для круга и треугольника площадь взаимодействия будет в виде квадрата с пустыми угалми, которые также
     * будут плоащлью взаимодествия.
     *
     * Для этого необходимо использовать метод shape() и брать boundingRect() от него.
     * А поскольку и в shape() и в paint() мы в общем случае может работать через полигон, то определим
     * метод расчета полигона для каждой фигуры.
     *
     * @return полигон фигуры
     */
    virtual QPolygon getShapePolygon() const = 0;


protected:
    QPoint leftTopPoint;        //левая-верхняя точка
    QPoint rightBotPoint;       //правая-нижняя точка

    //Передача цвета заливки
    //И типа линии при помощи композции - это паттерн МОСТ
    QColor color;               //цвет заливки
    Qt::PenStyle penStyle;      //стиль линии

    /**
     * Многострадальный boundingRect(), который возвращает площадь взаимодействия с фигурой. Без него (с пустым QRectF) фигура
     * не доступна для клика мышкой.
     *
     * Для работы с неквадратными фигурами необходимо внутри получать путь отрисовки через метод shape() и уже по нему вызывать boundingRect()
     */
    virtual QRectF boundingRect() const = 0;

    /**
     * Метод определяющий путь рисования сложных фигур.
     * Нужен для более правильного и продвинутого boundingRect()
     */
    virtual QPainterPath shape() const = 0;

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

    //Для некоторых операций: смена курсора, выделение множества фигур, выставление фигуры на передний план
    //Стандартного поведения через флаги недостаточно, поэтому переопределим методы взаимодействия мышью

    /**
     * Действия на нажатие клавишами мыши по фигуре
     */
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    /**
     * Обработка движение мыши.
     * Зажали ЛКМ и двигаем фигуру.
     */
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

    /**
     * Обработка когда отпусаются кнопки мыши.
     */
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
