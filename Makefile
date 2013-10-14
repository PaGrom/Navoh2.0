CXX= g++
CXXFLAGS = `pkg-config --cflags opencv` -O0 -g3 -Wall -c
LIBS = `pkg-config --libs opencv` lsd.c

EXECUTABLE = test_webcam
COMMON_SOURCES = test_webcam.cpp gobject.cpp tpoint.cpp tline.cpp trectangle.cpp tvector.cpp tsafevector.cpp findrect.cpp 
COMMON_OBJECTS = test_webcam.o gobject.o tpoint.o tline.o trectangle.o tvector.o tsafevector.o findrect.o 

.PHONY: all test_webcam

all: test_webcam

test_webcam: 
		$(EXECUTABLE)
 
$(EXECUTABLE): $(COMMON_OBJECTS)
		$(CXX) -o $@ $(COMMON_OBJECTS) $(LIBS)

clean:
		rm -rf $(EXECUTABLE) $(COMMON_OBJECTS)
 
%.o: %.cpp
		$(CXX) -c $< $(CXXFLAGS)
