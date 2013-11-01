#include "loadimage/loadimagestub.h"
#include "objectdetection/objectdetectionstub.h"
#include "compare/comparestub.h"
#include "affinedistortion/affinedistortionstub.h"
#include "objectdatabase/databasestub.h"

int main (int argc, char** argv){
	bool loop=false;
	LoadImageStub load;
	int imgMatch;
	do{
		Mat img=load.getImageFromCamera();
		vector<Mat> imgs  = ObjectDetectionStub::getImagesToCompare(img);
		vector<Mat> hists = DatabaseStub::loadHistograms();
		vector<Mat> featur= DatabaseStub::loadFeatures();
		imgMatch          = CompareStub::compare(img,hists,featur);
	    imshow("Working til here",img);
		load.releaseCameraCapture();
		printf("The match was : %d\n",imgMatch);
		waitKey(0);
	}while(loop);
}