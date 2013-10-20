CXX=g++
CXXFLAGS = `pkg-config --cflags opencv` -O0 -g3 -Wall -c
LIBS = `pkg-config --libs opencv`

EXECUTABLE = navoh
COMMON_SOURCES = gobject.cpp extractedpicture.cpp tline.cpp tpoint.cpp trectangle.cpp testmain.cpp
COMMON_OBJECTS = gobject.o extractedpicture.o tline.o tpoint.o trectangle.o testmain.o
.PHONY: all navoh

all: navoh

navoh: $(EXECUTABLE)
 
$(EXECUTABLE): $(COMMON_OBJECTS)
	$(CXX) -o $@ $(COMMON_OBJECTS) $(LIBS)

clean:
	rm -rf $(EXECUTABLE) $(COMMON_OBJECTS)
 
%.o: %.cpp
	$(CXX) -c $< $(CXXFLAGS)