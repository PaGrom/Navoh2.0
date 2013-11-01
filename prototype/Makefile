CXX=g++
CXXFLAGS = `pkg-config --cflags opencv` -O0 -g3 -Wall -c
LIBS = `pkg-config --libs opencv` objectdetection/lsd.c

EXECUTABLE = navoh2.0
AFFINEDISTORTION= affinedistortion/affinedistortionstub.cpp
OBJECTDETECTION = objectdetection/objectdetectionstub.cpp objectdetection/objectlibs/gobject.cpp objectdetection/objectlibs/tline.cpp objectdetection/objectlibs/tpoint.cpp objectdetection/objectlibs/trectangle.cpp 
MOREOBJDTEECTION= objectdetection/objectlibs/tvector.cpp objectdetection/objectlibs/tsafevector.cpp objectdetection/cvrect.cpp objectdetection/findrect.cpp
OBJECTDATABASE  = objectdatabase/databasestub.cpp
COMPARE_SOURCES = compare/comparestub.cpp compare/compare.cpp compare/histogramcompare/histogram.cpp compare/featurematching/featurematching.cpp
LOAD_SOURCES    = loadimage/loadimagestub.cpp loadimage/Navoh.cpp
AFFINEDISTORTIONO = affinedistortion/affinedistortionstub.o
OBJECTDETECTIONO = objectdetection/objectdetectionstub.o objectdetection/objectlibs/gobject.o objectdetection/objectlibs/tline.o objectdetection/objectlibs/tpoint.o objectdetection/objectlibs/trectangle.o
MOREOBJDETECTIONO= objectdetection/objectlibs/tvector.o objectdetection/objectlibs/tsafevector.o objectdetection/cvrect.o objectdetection/findrect.o
OBJECTDATABASEO  = objectdatabase/databasestub.o
COMPARE_OBJECTS = compare/comparestub.o compare/compare.o compare/histogramcompare/histogram.o compare/featurematching/featurematching.o
LOAD_OBJECTS    = loadimage/loadimagestub.o loadimage/Navoh.o

COMMON_SOURCES = programexec.cpp $(LOAD_SOURCES) $(COMPARE_SOURCES) $(OBJECTDATABASE) $(OBJECTDETECTION) $(AFFINEDISTORTION) $(MOREOBJDTEECTION)
COMMON_OBJECTS = programexec.o $(LOAD_OBJECTS) $(COMPARE_OBJECTS) $(OBJECTDATABASEO) $(OBJECTDETECTIONO) $(AFFINEDISTORTIONO) $(MOREOBJDETECTIONO)
OBJECTS   = programexec.o loadimagestub.o comparestub.o objectdetectionstub.o affinedistortionstub.o gobject.o tline.o tpoint.o trectangle.o databasestub.o compare.o histogram.o featurematching.o Navoh.o findrect.o cvrect.o tvector.o tsafevector.o


.PHONY: all histogramcomparetests

all: navoh

navoh: $(EXECUTABLE)
 
$(EXECUTABLE): $(COMMON_OBJECTS)
	$(CXX) -o $@ $(OBJECTS) $(LIBS)

clean:
	rm -rf $(EXECUTABLE) $(OBJECTS)
 
%.o: %.cpp
	$(CXX) -c $< $(CXXFLAGS)