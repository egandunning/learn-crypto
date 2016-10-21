SOURCES += hashtest.cpp
HEADERS += hashtest.h

TARGET = hashtest

unix {
	LIBS += -L/usr/local/lib -lcryptopp
}
