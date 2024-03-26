#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include <QObject>
#include <QColorDialog>

/**
 * Класс, отвечающий за работу с диалогами/окнами.
 * Синглтон.
 * Лучше уж всё сложить в одно место, чем искать где и какой диалог создается.
 */
class WindowManager : public QObject
{
    Q_OBJECT
public:
    static WindowManager *getInstance();
    ~WindowManager();

    QColorDialog *getColorDialog() const;

public slots:
signals:

private:
    static WindowManager *instance;
    explicit WindowManager(QObject *parent = nullptr);

    QColorDialog *colorDialog;
    QColorDialog *initColorDialog();
};

#endif // WINDOWMANAGER_H
