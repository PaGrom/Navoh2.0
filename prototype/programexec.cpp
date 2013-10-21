#include "loadimage/loadimagestub.h"
#include "objectdetection/objectdetectionstub.h"
#include "compare/comparestub.h"
#include "affinedistortion/affinedistortionstub.h"
#include "objectdatabase/databasestub.h"

int main (int argc, char** argv){
	bool loop=false;
	do{
		Mat img=LoadImageStub::getImageFromCamera();
		vector<Mat> imgs  = ObjectDetectionStub::getImagesToCompare(img);
		vector<Mat> hists = DatabaseStub::loadHistograms();
		vector<Mat> featur= DatabaseStub::loadFeatures();
		int imgMatch      = CompareStub::compare(img,hists,featur);
	
	}while(loop);
}