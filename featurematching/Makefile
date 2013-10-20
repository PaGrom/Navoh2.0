CXX=g++
CXXFLAGS = `pkg-config --cflags opencv` -O0 -g3 -Wall -c
LIBS = `pkg-config --libs opencv`

EXECUTABLE = navoh
COMMON_SOURCES = featurematchingtest1.cpp featurematching2.cpp testBench.cpp
COMMON_OBJECTS = featurematchingtest1.o featurematching2.o testBench.o
.PHONY: all navoh

all: navoh

navoh: $(EXECUTABLE)
 
$(EXECUTABLE): $(COMMON_OBJECTS)
	$(CXX) -o $@ $(COMMON_OBJECTS) $(LIBS)

clean:
	rm -rf $(EXECUTABLE) $(COMMON_OBJECTS)
 
%.o: %.cpp
	$(CXX) -c $< $(CXXFLAGS)