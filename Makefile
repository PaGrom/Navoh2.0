CC=g++
CFLAGS=-c -Wall `pkg-config --cflags opencv`
LDFLAGS=
SOURCES=navoh.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=navoh

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o $(EXECUTABLE)