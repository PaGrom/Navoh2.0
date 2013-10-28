CXX= g++
CXXFLAGS = `pkg-config --cflags opencv` -O0 -g3 -Wall -c
LIBS = `pkg-config --libs opencv` lsd.c

EXECUTABLE = test_mat
COMMON_SOURCES = test_mat.cpp gobject.cpp tpoint.cpp tline.cpp trectangle.cpp tvector.cpp tsafevector.cpp findrect.cpp cvrect.cpp
COMMON_OBJECTS = test_mat.o gobject.o tpoint.o tline.o trectangle.o tvector.o tsafevector.o findrect.o cvrect.o

.PHONY: all test_mat

all: test_mat

test_mat: 
		$(EXECUTABLE)
 
$(EXECUTABLE): $(COMMON_OBJECTS)
		$(CXX) -o $@ $(COMMON_OBJECTS) $(LIBS)

clean:
		rm -rf $(EXECUTABLE) $(COMMON_OBJECTS)
 
%.o: %.cpp
		$(CXX) -c $< $(CXXFLAGS)
