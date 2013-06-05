PRECOMPILED_HEADER = src/stdafx.h

QT += widgets sql

win32 {
    RC_FILE  = misc/win32/resource.rc
}

HEADERS = \
    src/logindlg.h \
    src/settings.h \
    src/controls.h \
    src/stdafx.h \
    src/mainwindow.h

SOURCES = \
    src/main.cpp \
    src/logindlg.cpp \
    src/settings.cpp \
    src/controls.cpp \
    src/mainwindow.cpp

OTHER_FILES += \
    misc/win32/resource.rc \
    misc/icons/logo.jpg \
    misc/icons/logo.ico

FORMS += \
    src/mainwindow.ui
