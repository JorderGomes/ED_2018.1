TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    lib/pen.cpp \
    lib/cpen.cpp \
    aluno/quadrado.cpp

HEADERS += \
    lib/cpen.h \
    lib/sfLine.h \
    lib/pen.h \
    aluno/arvore.h \
    triangulo.h


CONFIG += c++11
LIBS += -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
