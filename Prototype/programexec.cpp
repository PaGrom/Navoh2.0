#include "loadimage/loadimagestub.h"
#include "objectdetection/objectdetectionstub.h"
#include "compare/comparestub.h"
#include "affinedistortion/affinedistortionstub.h"
#include "objectdatabase/databasestub.h"

int main (int argc, char** argv){
	bool loop=false;
	do{
		Mat img=LoadImageStub::getImageFromCamera();
		ObjectDetectionStub::getImagesToCompare(img);
		char* a;
		//DatabaseStub::loadHistogram(a);
		CompareStub::compare(img,vector<Histogram>(),vector<Mat>());
	
	}while(loop);
}