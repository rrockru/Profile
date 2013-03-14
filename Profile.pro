PRECOMPILED_HEADER = src/stdafx.h

CONFIG += debug

QT += widgets sql

win32 {
    RC_FILE  = misc/win32/resource.rc
}

HEADERS = \
    src/mainwindow.h \
    src/logindlg.h

SOURCES = \
    src/main.cpp \
    src/mainwindow.cpp \
    src/logindlg.cpp

OTHER_FILES += \
    misc/win32/resource.rc \
    misc/icons/logo.jpg \
    misc/icons/logo.ico
