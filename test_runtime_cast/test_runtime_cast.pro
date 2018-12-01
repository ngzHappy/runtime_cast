
QT += gui
QT += core

CONFIG += console 

SOURCES += $$PWD/main.cpp

CONFIG(debug,debug|release){
    TARGET =   test_runtime_cast_debug
}else{
    TARGET =   test_runtime_cast
}

TEMPLATE = app

CONFIG += c++14
















