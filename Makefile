CXX=g++
CXXFLAGS = `pkg-config --cflags opencv` -O0 -g3 -Wall -c
LIBS = `pkg-config --libs opencv`

EXECUTABLE = Compare
COMMON_SOURCES =  featurematching/featurematching.cpp compare.cpp main.cpp histogramcompare/histogram.cpp
COMMON_OBJECTS =  featurematching/featurematching.o compare.o main.o histogramcompare/histogram.o
OBJECTS        =  featurematching.o main.o compare.o histogram.o 
.PHONY: all histogramcomparetests

all: navoh

navoh: $(EXECUTABLE)
 
$(EXECUTABLE): $(COMMON_OBJECTS)
	$(CXX) -o $@ $(OBJECTS) $(LIBS)

clean:
	rm -rf $(EXECUTABLE) $(OBJECTS)
 
%.o: %.cpp
	$(CXX) -c $< $(CXXFLAGS)