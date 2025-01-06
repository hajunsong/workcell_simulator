QT += core gui widgets

CONFIG += c++11

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    qclicklabel.cpp

HEADERS += \
    mainwindow.h \
    qclicklabel.h

FORMS += \
	mainwindow.ui

RESOURCES += \
	resources.qrc

LIBS += -L$$PWD/pugixml/lib/ -lpugixml

INCLUDEPATH += $$PWD/pugixml/include
DEPENDPATH += $$PWD/pugixml/include


