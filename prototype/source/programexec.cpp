#include "loadimage/loadimagestub.h"
#include "objectdetection/objectdetectionstub.h"
#include "compare/comparestub.h"
#include "affinedistortion/affinedistortionstub.h"
#include "objectdatabase/databasestub.h"
#include <iostream>

int main (int argc, char** argv){
	bool loop=true;
	LoadImageStub load(0);
	
	if(argc>1)
	  load=LoadImageStub(argv[1]);
	
	DatabaseStub data;
	Mat *img;
	
	vector<TRectangle> rect(10000);
	Mat subImage;
	
	vector<Mat> *hists;
	vector<Mat> *featur;
	
	int vectorsize;
	int numberOfImages;
	int imgMatch=-1;
	
	hists= data.loadHistograms();//dummy
	featur= data.loadFeatures();//dummy	
	
	do{
		img=load.getImageFromCamera();
		vectorsize=ObjectDetectionStub::findRectangles(img,&rect);
		//dummy
		
		for(unsigned int i=0; i<vectorsize;++i){
			subImage = ObjectDetectionStub::getSubImageForRectangle(img,&rect[i]);
			imgMatch = CompareStub::compare(&subImage,hists,featur);
			
			if(imgMatch>-1)
				ObjectDetectionStub::show(img,&rect[i], vectorsize);
		}
	    imshow("Working til here",*img);
		
		printf("The rectangles : %d\n.",vectorsize);
		//printf("There are %lu rectangles \n", rect->size());
		waitKey(1);
		//sleep(1);
		
		if(waitKey(30)>0)
		break;
	}while(loop);
	load.releaseCameraCapture();
}