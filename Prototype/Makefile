CXX=g++
CXXFLAGS = `pkg-config --cflags opencv` -O0 -g3 -Wall -c
LIBS = `pkg-config --libs opencv`

EXECUTABLE = navoh2.0
AFFINEDISTORTION= affinedistortion/affinedistortionstub.cpp
OBJECTDETECTION = objectdetection/objectdetectionstub.cpp objectdetection/objectlibs/gobject.cpp objectdetection/objectlibs/tline.cpp objectdetection/objectlibs/tpoint.cpp objectdetection/objectlibs/trectangle.cpp 
OBJECTDATABASE  = objectdatabase/databasestub.cpp
COMPARE_SOURCES = compare/comparestub.cpp
LOAD_SOURCES    = loadimage/loadimagestub.cpp
AFFINEDISTORTIONO = affinedistortion/affinedistortionstub.o
OBJECTDETECTIONO = objectdetection/objectdetectionstub.o objectdetection/objectlibs/gobject.o objectdetection/objectlibs/tline.o objectdetection/objectlibs/tpoint.o objectdetection/objectlibs/trectangle.o
OBJECTDATABASEO  = objectdatabase/databasestub.o
COMPARE_OBJECTS = compare/comparestub.o
LOAD_OBJECTS    = loadimage/loadimagestub.o

COMMON_SOURCES = programexec.cpp $(LOAD_SOURCES) $(COMPARE_SOURCES) $(OBJECTDATABASE) $(OBJECTDETECTION) $(AFFINEDISTORTION)
COMMON_OBJECTS = programexec.o $(LOAD_OBJECTS) $(COMPARE_OBJECTS) $(OBJECTDATABASEO) $(OBJECTDETECTIONO) $(AFFINEDISTORTIONO)
OBJECTS   = programexec.o loadimagestub.o comparestub.o objectdetectionstub.o affinedistortionstub.o gobject.o tline.o tpoint.o trectangle.o


.PHONY: all histogramcomparetests

all: navoh

navoh: $(EXECUTABLE)
 
$(EXECUTABLE): $(COMMON_OBJECTS)
	$(CXX) -o $@ $(OBJECTS) $(LIBS)

clean:
	rm -rf $(EXECUTABLE) $(COMMON_OBJECTS)
 
%.o: %.cpp
	$(CXX) -c $< $(CXXFLAGS)