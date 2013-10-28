CXX=g++
CXXFLAGS = `pkg-config --cflags opencv` -O0 -g3 -Wall -c
LIBS = `pkg-config --libs opencv`

EXECUTABLE = distortion
COMMON_SOURCES = main.cpp affinedistortion.cpp trectangle.cpp tline.cpp tpoint.cpp goject.cpp
COMMON_OBJECTS = main.o affinedistortion.o trectangle.o tline.o tpoint.o gobject.o 
.PHONY: all histogramcomparetests

all: navoh

navoh: $(EXECUTABLE)
 
$(EXECUTABLE): $(COMMON_OBJECTS)
	$(CXX) -o $@ $(COMMON_OBJECTS) $(LIBS)

clean:
	rm -rf $(EXECUTABLE) $(COMMON_OBJECTS)
 
%.o: %.cpp
	$(CXX) -c $< $(CXXFLAGS)