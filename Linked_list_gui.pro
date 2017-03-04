#-------------------------------------------------
#
# Project created by QtCreator 2016-04-10T23:15:31
#
#-------------------------------------------------

QT       += core gui
QT       +=  gui
CONFIG	+= c++11
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Linked_list_gui
TEMPLATE = app


SOURCES += List_interface.cpp\
	main.cpp\
        mainwindow.cpp \
    list_view.cpp 
    

HEADERS  += mainwindow.h \
    list_view.h \
    my_list.h \
    list_base.h \
    List_interface.h
