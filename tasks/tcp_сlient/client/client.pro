QT += core
QT -= gui

CONFIG += c++11

TARGET = client
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../libprogbase-cpp/build/release/ -lprogbase-cpp
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../libprogbase-cpp/build/debug/ -lprogbase-cpp
else:unix: LIBS += -L$$PWD/../../../../../../libprogbase-cpp/build/ -lprogbase-cpp

INCLUDEPATH += $$PWD/../../../../../../../../usr/local/include/progbase-cpp
DEPENDPATH += $$PWD/../../../../../../../../usr/local/include/progbase-cpp

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../../libprogbase-cpp/build/release/libprogbase-cpp.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../../libprogbase-cpp/build/debug/libprogbase-cpp.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../../libprogbase-cpp/build/release/progbase-cpp.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../../libprogbase-cpp/build/debug/progbase-cpp.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../../../../../libprogbase-cpp/build/libprogbase-cpp.a

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../../../usr/local/lib/release/ -lprogbase
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../../../usr/local/lib/debug/ -lprogbase
else:unix: LIBS += -L$$PWD/../../../../../../../../usr/local/lib/ -lprogbase

INCLUDEPATH += $$PWD/../../../../../../../../usr/local/include/progbase
DEPENDPATH += $$PWD/../../../../../../../../usr/local/include/progbase

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../../../../usr/local/lib/release/libprogbase.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../../../../usr/local/lib/debug/libprogbase.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../../../../usr/local/lib/release/progbase.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../../../../usr/local/lib/debug/progbase.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../../../../../../../usr/local/lib/libprogbase.a

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../../../usr/lib/x86_64-linux-gnu/release/ -lssl
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../../../usr/lib/x86_64-linux-gnu/debug/ -lssl
else:unix: LIBS += -L$$PWD/../../../../../../../../usr/lib/x86_64-linux-gnu/ -lssl

INCLUDEPATH += $$PWD/../../../../../../../../usr/include/openssl
DEPENDPATH += $$PWD/../../../../../../../../usr/include/openssl

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../../../../usr/lib/x86_64-linux-gnu/release/libssl.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../../../../usr/lib/x86_64-linux-gnu/debug/libssl.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../../../../usr/lib/x86_64-linux-gnu/release/ssl.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../../../../usr/lib/x86_64-linux-gnu/debug/ssl.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../../../../../../../usr/lib/x86_64-linux-gnu/libssl.a
