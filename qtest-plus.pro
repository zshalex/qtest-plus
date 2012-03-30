#-------------------------------------------------
#
# Project created by QtCreator 2012-03-28T09:43:00
#
#-------------------------------------------------

QT += core testlib

TARGET = qtest-plus
TEMPLATE = lib

DESTDIR = lib
OBJECTS_DIR = build
MOC_DIR = build

VERSION = 0.1.0

INCLUDEPATH += include

DEFINES += QTESTPLUS_LIBRARY

SOURCES += \
    src/testsuite.cpp \
    src/testcase.cpp

HEADERS += include/qtest-plus_global.h \
    include/testsuite.h \
    include/testcase.h
