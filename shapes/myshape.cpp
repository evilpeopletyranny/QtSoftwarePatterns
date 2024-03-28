#include "shapes/myshape.h"
#include "shapes/chain/wheeleventhandler.h"
#include "shapes/chain/wheelshifteventhandler.h"

//Создание цепочки обратки событий колеса мыши
EventHandler *MyShape::eventChain = initChain();

//За счет цепочки, теперь если нам необходимо добавить новый обработчик,
//то мы определяем его класс и просто добавляем в цепочку.
//Дальше цепочка появиться и в других местах
EventHandler *MyShape::initChain()
{
    EventHandler *handler = new WheelEventHandler(Qt::NoModifier);
    handler->setNext(new WheelShiftEventHandler(Qt::ShiftModifier));
    return handler;
}

void MyShape::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //Фигура, на которой мы зажали мышь вытаскивается на передний план
    setZValue(1);
}

void MyShape::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    //При зажатии и движении меняем курсор на руку и двигаем фигуру
    if (event->buttons() & Qt::LeftButton) setCursor(QCursor(Qt::ClosedHandCursor));
    setPos(event->scenePos());
}

void MyShape::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    //При отпускании кнопки мыши возвращаем курсор стрелочку
    this->setCursor(QCursor(Qt::ArrowCursor));
    setZValue(0);
}

MyShape::MyShape(QPoint leftTopPoint,
             QPoint rightBotPoint,
             qreal rotation,
             QColor color,
             Qt::PenStyle penStyle)
{
    this->leftTopPoint = leftTopPoint;
    this->rightBotPoint = rightBotPoint;
    this->color = color;
    this->penStyle = penStyle;

    setRotation(rotation);

/*
    Поскольку мы переопределяем стандартное поведение фигур - флаги то и не нужны.
    Здесь они лежать чтобы просто не потерять
*/

//    setFlags(QGraphicsItem::ItemIsSelectable|
//             QGraphicsItem::ItemIsMovable|
//             QGraphicsItem::ItemSendsGeometryChanges|
//             QGraphicsItem::ItemIsFocusable);
}

QPoint MyShape::getLeftTopPoint() const
{
    return leftTopPoint;
}

QPoint MyShape::getRightBotPoint() const
{
    return rightBotPoint;
}

void MyShape::wheelEvent(QGraphicsSceneWheelEvent *event)
{
    //Вызов цепочки обработчиков движения колеса мыши
    MyShape::eventChain->handle(event, this);
    update();
    scene()->update();
}

void MyShape::resize(int pixelCount)
{
    leftTopPoint = QPoint(leftTopPoint.x() - pixelCount, leftTopPoint.y() - pixelCount);
    rightBotPoint = QPoint(rightBotPoint.x() + pixelCount, rightBotPoint.y() + pixelCount);
}

void MyShape::rotate(int degree)
{
    setRotation(rotation() + degree);
}

Qt::PenStyle MyShape::getPenStyle() const
{
    return penStyle;
}

const QColor &MyShape::getColor() const
{
    return color;
}
