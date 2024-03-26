#include "windowmanager.h"

WindowManager *WindowManager::instance = nullptr;

WindowManager::WindowManager(QObject *parent)
    : QObject{parent}
{
    colorDialog = initColorDialog();
}

WindowManager::~WindowManager()
{
    delete colorDialog;
}

QColorDialog *WindowManager::getColorDialog() const
{
    return colorDialog;
}

WindowManager *WindowManager::getInstance()
{
    if (instance == nullptr) instance = new WindowManager();
    return instance;
}

QColorDialog *WindowManager::initColorDialog()
{
    QColorDialog *dialog = new QColorDialog();
    return dialog;
}
