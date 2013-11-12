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
	
	char path[100];
	int blackPixAdded=0;
	int vectorsize;
	int numberOfImages;
	int imgMatch=-1;
	int k=0;
	
	hists= data.loadHistograms();//dummy
	featur= data.loadFeatures();//dummy	
	
	do{
		img=load.getImageFromCamera();
		vectorsize=ObjectDetectionStub::findRectangles(img,&rect);
		//dummy
		/*if(k%100==0){
			 sprintf(path,"testimg/%d.ppm",k);
			data.saveImage(path,*img);
		}*/
		
		for(unsigned int i=0; i<vectorsize;++i){
			subImage = ObjectDetectionStub::getSubImageForRectangle(img,&rect[i],blackPixAdded);
			imgMatch = CompareStub::compare(&subImage,hists,featur,blackPixAdded);
			if(i%100==0){
			  sprintf(path,"testimg/%d%d.ppm",i,k);
			  data.saveImage(path,subImage);
			}
			if(imgMatch>-1){
						printf("found match\n");
						imshow("Matching image",subImage);
						waitKey(100);
			}
			
		}
	    imshow("Stream",*img);
		
		printf("The rectangles : %d\n.",vectorsize);
		//printf("There are %lu rectangles \n", rect->size());
		if(imgMatch>0){
			printf("found match\n");
			waitKey(0);
		
		}
			
		waitKey(1);
		//sleep(1);
		
		if(waitKey(30)>0)
		break;
		k++;
		imgMatch=-1;
	}while(loop);
	load.releaseCameraCapture();
}