CC              := g++
CFLAGS          := -I/usr/local/include/opencv -L/usr/local/lib -Wl,-rpath,/usr/local/lib
OBJECTS         := 
LIBRARIES       := -lopencv_core -lopencv_imgproc -lopencv_highgui lsd.c -lm

test: 
	$(CC) $(CFLAGS) -o test test.cpp $(LIBRARIES)
	
test_rect: 
	$(CC) $(CFLAGS) -o test_rect test_rect.cpp $(LIBRARIES)
        
clean:
	rm -f *.o test test_rect
