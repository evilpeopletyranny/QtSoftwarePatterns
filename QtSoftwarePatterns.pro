QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000 # disables all the APIs deprecated before Qt 6.0.0

# You can make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# Please consult the documentation of the deprecated API in order to know
# how to port your code away from it.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += form.h \
           mainwindow.h \
           commands/shapecommand.h \
           dialogs/windowmanager.h \
           shapes/myshape.h \
           shapes/shapecreator.h \
           shapes/shapecreatormultiton.h \
           widgets/shapebutton.h \
           widgets/shapeeditorwidget.h \
           widgets/shapemediatorwidget.h \
           widgets/shapescenewidget.h \
           widgets/shapeviewwidget.h \
           shapes/chain/eventhandler.h \
           shapes/chain/wheeleventhandler.h \
           shapes/chain/wheelshifteventhandler.h \
           shapes/circles/circle.h \
           shapes/circles/circlecreator.h \
           shapes/groups/group.h \
           shapes/rectangles/rectangle.h \
           shapes/rectangles/rectanglecreator.h \
           shapes/triangles/triangle.h \
           shapes/triangles/trianglecreator.h
FORMS += form.ui
SOURCES += form.cpp \
           main.cpp \
           mainwindow.cpp \
           commands/shapecommand.cpp \
           dialogs/windowmanager.cpp \
           shapes/myshape.cpp \
           shapes/shapecreator.cpp \
           shapes/shapecreatormultiton.cpp \
           widgets/shapebutton.cpp \
           widgets/shapeeditorwidget.cpp \
           widgets/shapemediatorwidget.cpp \
           widgets/shapescenewidget.cpp \
           widgets/shapeviewwidget.cpp \
           shapes/chain/eventhandler.cpp \
           shapes/chain/wheeleventhandler.cpp \
           shapes/chain/wheelshifteventhandler.cpp \
           shapes/circles/circle.cpp \
           shapes/circles/circlecreator.cpp \
           shapes/groups/group.cpp \
           shapes/rectangles/rectangle.cpp \
           shapes/rectangles/rectanglecreator.cpp \
           shapes/triangles/triangle.cpp \
           shapes/triangles/trianglecreator.cpp


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
