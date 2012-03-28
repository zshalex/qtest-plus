#-------------------------------------------------
#
# Project created by QtCreator 2012-03-28T09:43:00
#
#-------------------------------------------------

QT       -= gui

QT += testlib

TARGET = qtest-plus
TEMPLATE = lib

DESTDIR = build
OBJECTS_DIR = build
MOC_DIR = build

VERSION = 0.0.1

DEFINES += QTESTPLUS_LIBRARY

SOURCES += \
    testsuite.cpp \
    testcase.cpp

HEADERS += qtest-plus_global.h \
    testsuite.h \
    testcase.h
