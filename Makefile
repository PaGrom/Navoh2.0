CC              := g++
CFLAGS          := -I/usr/local/include/opencv -L/usr/local/lib -Wl,-rpath,/usr/local/lib
OBJECTS         := 
LIBRARIES       := -lopencv_core -lopencv_imgproc -lopencv_highgui lsd.c -lm

.PHONY: all clean

all: test

test: 
	$(CC) $(CFLAGS) -o test test.cpp $(LIBRARIES)
        
clean:
	rm -f *.o test
