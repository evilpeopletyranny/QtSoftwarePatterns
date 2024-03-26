#include "shapeeditorwidget.h"

ShapeEditorWidget::ShapeEditorWidget(QWidget *parent)
    : QWidget{parent}
{
    lineStyleBox = initLineStyleBox(this);  //инициализация выпадающего списка типа линии
    colorButton = initColorButton(this);    //инициализация кнопки выбора цвета
    linkColorDialogToButton(colorButton);   //связаывание кнопки выбора цвета и диалога выбора цвета

    setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);  //установка политики размеров
    setLayout(new QVBoxLayout());
    layout()->addWidget(lineStyleBox);
    layout()->addWidget(colorButton);

    //Добавление scrollArea с кнопками.
    layout()->addWidget(initScrollArea(
                            QList<ShapeButton*>{
                                new ShapeButton(ShapeType::Rectangle, "Квадрат"),
                                new ShapeButton(ShapeType::Circle, "Круг"),
                                new ShapeButton(ShapeType::Triangle, "Треугольник")
                            },
                            this));
}

QColorDialog *ShapeEditorWidget::linkColorDialogToButton(QPushButton *button)
{
    QColorDialog *dialog = WindowManager::getInstance()->getColorDialog();

    connect(button, &QPushButton::clicked, dialog, &QColorDialog::exec);
    connect(dialog, &QColorDialog::colorSelected, this, &ShapeEditorWidget::changeCurrentColor);

    return dialog;
}

QPushButton *ShapeEditorWidget::initColorButton(QWidget *parent)
{
    QPushButton *button = new QPushButton(parent);
    button->setAutoFillBackground(true);
    changeColorButton(button, QColor(255, 255, 255));
    return button;
}

QComboBox *ShapeEditorWidget::initLineStyleBox(QWidget *parent)
{
    //Тип линии в  Qt является Enum'ом, но не зареганм как Q_META_...
    //Поэтому нельзя напрямую засунуть этот Enum, но можно засунуть инты
    QComboBox *box = new QComboBox(parent);
    box->addItem("Solid Line", QVariant(1));
    box->addItem("Dash Line", QVariant(2));
    box->addItem("Dot Line", QVariant(3));
    box->addItem("Dash Dot Line", QVariant(4));
    box->addItem("Dash Dot Dot Line", QVariant(5));
    return box;
}

QScrollArea *ShapeEditorWidget::initScrollArea(QList<ShapeButton*> buttonList, QWidget *parent)
{
    //Создание scrollArea
    QScrollArea *area = new QScrollArea(parent);
    area->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);

    area->setLayout(new QVBoxLayout(area));
    area->layout()->setAlignment(Qt::AlignTop);     //В вертиканольном layoutе всё прижать к верхую

    //Кнопки связываем с scrooArea
    for (auto *button: buttonList) {
        button->setParent(area);
        area->layout()->addWidget(button);

        //Связываем сигнал кнопки о создании фигуры со слотом создании команды на создание фигуры :)
        connect(button, &ShapeButton::createShapeSingal, this, &ShapeEditorWidget::createShapeCommand);
    }

    return area;
}

Qt::PenStyle ShapeEditorWidget::getCurrentPenStyle()
{
    return (Qt::PenStyle) lineStyleBox->currentData().toInt();  //из списка выбора типа линии, получаем инт и приводим к enum типа линии
}

QColor ShapeEditorWidget::getCurrentColor()
{
    return colorButton->palette().color(colorButton->backgroundRole());     //получаем цвет кнопки
}

void ShapeEditorWidget::changeColorButton(QPushButton *button, QColor color)
{
    //меняем цвет кнопки на переданный
    QPalette pallete = button->palette();
    QPalette::ColorRole colorRole = button->backgroundRole();
    pallete.setColor(colorRole, color);
    button->setPalette(pallete);
}

void ShapeEditorWidget::changeCurrentColor(QColor color)
{
    changeColorButton(colorButton, color);
}

void ShapeEditorWidget::createShapeCommand(ShapeType shapeType)
{
    emit emitCreateShapeCommand(new ShapeCommand(shapeType,
                                QPoint(100, 100),
                                QPoint(-100, -100),
                                0,
                                getCurrentColor(),
                                getCurrentPenStyle()));
}
