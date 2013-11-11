CXX=g++
CXXFLAGS = `pkg-config --cflags opencv` -O0 -g3 -Wall -c
LIBS = `pkg-config --libs opencv`

EXECUTABLE = ../debug/databasetool
COMMON_SOURCES =  compare/featurematching/featurematching.cpp  toolmain.cpp compare/histogramcompare/histogram.cpp objectdatabase/database.cpp objectdatabase/databaseobject.cpp
COMMON_OBJECTS =  compare/featurematching/featurematching.o toolmain.o compare/histogramcompare/histogram.o objectdatabase/database.o objectdatabase/databaseobject.o
OBJECTS        =  featurematching.o toolmain.o histogram.o database.o databaseobject.o
.PHONY: all histogramcomparetests

all: navoh

navoh: $(EXECUTABLE)
 
$(EXECUTABLE): $(COMMON_OBJECTS)
	$(CXX) -o $@ $(OBJECTS) $(LIBS)

clean:
	rm -rf  $(OBJECTS)
 
%.o: %.cpp
	$(CXX) -c $< $(CXXFLAGS)