TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    cast_utilities.cpp \
    crud.cpp \
    jsoncpp/src/json_reader.cpp \
    jsoncpp/src/json_value.cpp \
    jsoncpp/src/json_valueiterator.inl \
    jsoncpp/src/json_writer.cpp

SUBDIRS += \
    botCM.pro

DISTFILES += \
    botCM.pro.user \
    jsoncpp/src/CMakeLists.txt

HEADERS += \
    cast_utilities.h \
    crud.h \
    jsoncpp/json/allocator.h \
    jsoncpp/json/assertions.h \
    jsoncpp/json/autolink.h \
    jsoncpp/json/config.h \
    jsoncpp/json/features.h \
    jsoncpp/json/forwards.h \
    jsoncpp/json/json.h \
    jsoncpp/json/reader.h \
    jsoncpp/json/value.h \
    jsoncpp/json/version.h \
    jsoncpp/json/writer.h \
    jsoncpp/src/json_tool.h \
    jsoncpp/src/version.h.in
