CXX=g++
CXXFLAGS = `pkg-config --cflags opencv` -O0 -g3 -Wall -c
LIBS = `pkg-config --libs opencv` libs/lsd.c libs/gobject.cpp libs/tline.cpp libs/tpoint.cpp libs/trectangle.cpp libs/tvector.cpp libs/tsafevector.cpp

OBJ_DIR =debug
SRC_DIR =source

vpath %.cpp $(SRC_DIR)
vpath %.o $(OBJ_DIR)
vpath % $(OBJ_DIR)


OBJECTDATA_SRC = $(addprefix objectdatabase/, databasestub.cpp)
OBJECTDETECSRC = $(addprefix objectdetection/, cvrect.cpp findrect.cpp objectdetectionstub.cpp)
AFFINEDIST_SRC = $(addprefix affinedistortion/, affinedistortionstub.cpp)
COMPARE_SOURCE = $(addprefix compare/, compare.cpp comparestub.cpp $(addprefix featurematching/, featurematching.cpp) $(addprefix histogramcompare/, histogram.cpp))
LOADIMG_SOURCE = $(addprefix loadimage/, loadimagestub.cpp Navoh.cpp)
COMMON_SOURCES =  programexec.cpp $(LOADING_SOURCE) $(COMPARE_SOURCE) $(AFFINEDIST_SRC) $(OBJECTDETECSRC) $(OBJECTDATA_SRC)

OBJECTDATA_OBJ = $(addprefix objectdetection/, cvrect.o findrect.o objectdetectionstub.o)
OBJECTDETECOBJ = $(addprefix objectdatabase/, databasestub.o)
AFFINEDIST_OBJ = $(addprefix affinedistortion/, affinedistortionstub.o)
COMPARE_OBJECT = $(addprefix compare/, compare.o comparestub.o $(addprefix featurematching/, featurematching.o) $(addprefix histogramcompare/, histogram.o)) 
LOADING_OBJECT = $(addprefix loadimage/, loadimagestub.o Navoh.o)
COMMON_OBJECTS = programexec.o $(LOADING_OBJECT)  $(COMPARE_OBJECT) $(AFFINEDIST_OBJ) $(OBJECTDETECOBJ) $(OBJECTDATA_OBJ)

EXECUTABLE = $(OBJ_DIR)/navoh2.0



.PHONY: all histogramcomparetests

all: navoh

navoh: $(EXECUTABLE)
 
$(EXECUTABLE): $(COMMON_OBJECTS)
	$(CXX) -o $@ $(addprefix debug/, $(COMMON_OBJECTS)) $(LIBS)

clean:
	rm -rf $(EXECUTABLE) $(addprefix debug/, $(COMMON_OBJECTS))
	
 
%.o: %.cpp
	$(CXX) -c $< $(CXXFLAGS) -o debug/$@