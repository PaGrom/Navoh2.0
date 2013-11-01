#include "loadimage/loadimagestub.h"
#include "objectdetection/objectdetectionstub.h"
#include "compare/comparestub.h"
#include "affinedistortion/affinedistortionstub.h"
#include "objectdatabase/databasestub.h"

int main (int argc, char** argv){
	bool loop=true;
	LoadImageStub load(0);
	Mat *img;
	vector<TRectangle> *rect;
	vector<Mat> *imgs;
	vector<Mat> *hists;
	vector<Mat> *featur;
	int imgMatch=-1;
	do{
		img=load.getImageFromCamera();
		rect= ObjectDetectionStub::findRectangles(img);
		imgs= ObjectDetectionStub::getImagesToCompare(img);//dummy
		hists= DatabaseStub::loadHistograms();//dummy
		featur= DatabaseStub::loadFeatures();//dummy
		for(unsigned int i=0; i<imgs->size();++i){
		imgMatch          = CompareStub::compare(img/*s[i]*/,hists,featur);
		}
	    imshow("Working til here",*img);
		
		printf("The match was : %d.",imgMatch);
		printf("There are %lu rectangles \n", rect->size());
		waitKey(10);
		if(waitKey(30)>0)
		break;
	}while(loop);
	load.releaseCameraCapture();
}