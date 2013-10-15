CXX=g++
CXXFLAGS = `pkg-config --cflags opencv` -O0 -g3 -Wall -c
LIBS = `pkg-config --libs opencv`

EXECUTABLE = navoh
COMMON_SOURCES = testmain.cpp histogram.cpp
COMMON_OBJECTS = testmain.o histogram.o
.PHONY: all navoh

all: navoh

navoh: $(EXECUTABLE)
 
$(EXECUTABLE): $(COMMON_OBJECTS)
	$(CXX) -o $@ $(COMMON_OBJECTS) $(LIBS)

clean:
	rm -rf $(EXECUTABLE) $(COMMON_OBJECTS)
 
%.o: %.cpp
	$(CXX) -c $< $(CXXFLAGS)