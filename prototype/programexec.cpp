#include "loadimage/loadimagestub.h"
#include "objectdetection/objectdetectionstub.h"
#include "compare/comparestub.h"
#include "affinedistortion/affinedistortionstub.h"
#include "objectdatabase/databasestub.h"

int main (int argc, char** argv){
	bool loop=true;
	LoadImageStub load(0);
	int imgMatch=-1;
	do{
		Mat img=load.getImageFromCamera();
		vector<TRectangle> rect= ObjectDetectionStub::findRectangles(img);
		vector<Mat> imgs  = ObjectDetectionStub::getImagesToCompare(img);//dummy
		vector<Mat> hists = DatabaseStub::loadHistograms();//dummy
		vector<Mat> featur= DatabaseStub::loadFeatures();//dummy
		for(unsigned int i=0; i<imgs.size();++i){
		imgMatch          = CompareStub::compare(img/*s[i]*/,hists,featur);
		}
	    imshow("Working til here",img);
		
		printf("The match was : %d.",imgMatch);
		printf("There are %lu rectangles \n", rect.size());
		waitKey(10);
		if(waitKey(30)>0)
		break;
	}while(loop);
	load.releaseCameraCapture();
}