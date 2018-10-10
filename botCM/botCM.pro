TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

SUBDIRS += \
    botCM.pro

DISTFILES += \
    botCM.pro.user \
    jsoncpp/src/CMakeLists.txt

HEADERS +=
