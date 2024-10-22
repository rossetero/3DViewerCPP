QT       += core gui opengl widgets openglwidgets

include(qgifimage/gifimage/qtgifimage.pri)

CONFIG += c++17


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../controller/controller.cc \
    ../model/operations.cc \
    ../model/parser.cc \
    myopenglwidget.cc \
    main.cc \
    mainwindow.cc

HEADERS += \
    ../controller/controller.h \
    ../model/model.h \
    ../model/operations.h \
    myopenglwidget.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
