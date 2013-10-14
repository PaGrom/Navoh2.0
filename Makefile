CC := g++
CFLAGS := -I/usr/local/include/opencv -L/usr/local/lib -Wl,-rpath,/usr/local/lib
OBJECTS :=
LIBRARIES := -lopencv_core -lopencv_imgproc -lopencv_highgui gobject.cpp tpoint.cpp tline.cpp trectangle.cpp tvector.cpp tsafevector.cpp findrect.cpp lsd.c -lm

test_webcam:
	$(CC) $(CFLAGS) -o test_webcam test_webcam.cpp $(LIBRARIES)
        
clean:
	rm -f *.o test_webcam

