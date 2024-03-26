#include "shapes/myshape.h"
#include "shapes/chain/wheeleventhandler.h"
#include "shapes/chain/wheelshifteventhandler.h"

EventHandler *MyShape::eventChain = initChain();

EventHandler *MyShape::initChain()
{
    EventHandler *handler = new WheelEventHandler(Qt::NoModifier);
    handler->setNext(new WheelShiftEventHandler(Qt::ShiftModifier));
    return handler;
}

void MyShape::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

}

void MyShape::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    setPos(event->scenePos());
    if (event->buttons() & Qt::LeftButton) setCursor(QCursor(Qt::ClosedHandCursor));
}

void MyShape::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
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

    //Флаги на выделение, движение, изменение фигуры
    //Важно, за счет этого они двигуются и реагируют на действия
    setFlags(QGraphicsItem::ItemIsSelectable|
             QGraphicsItem::ItemIsMovable|
             QGraphicsItem::ItemSendsGeometryChanges|
             QGraphicsItem::ItemIsFocusable);
}

QPoint MyShape::getLeftTopPoint() const
{
    return leftTopPoint;
}

void MyShape::setLeftTopPoint(QPoint newLeftTopPoint)
{
    leftTopPoint = newLeftTopPoint;
}

QPoint MyShape::getRightBotPoint() const
{
    return rightBotPoint;
}

void MyShape::setRightBotPoint(QPoint newRightBotPoint)
{
    rightBotPoint = newRightBotPoint;
}

QRectF MyShape::boundingRect() const
{
    return QRectF(leftTopPoint, rightBotPoint);
}

void MyShape::wheelEvent(QGraphicsSceneWheelEvent *event)
{
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

void MyShape::setPenStyle(Qt::PenStyle newPenStyle)
{
    penStyle = newPenStyle;
}

const QColor &MyShape::getColor() const
{
    return color;
}

void MyShape::setColor(const QColor &newColor)
{
    color = newColor;
}
