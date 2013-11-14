#include "loadimage/loadimagestub.h"
#include "objectdetection/objectdetectionstub.h"
#include "compare/comparestub.h"
#include "affinedistortion/affinedistortionstub.h"
#include "objectdatabase/databasestub.h"
#include <iostream>

int main (int argc, char** argv){
	
	bool oldmatch=false;
	bool roundmatch =false;
	bool loop=true;
	LoadImageStub load(0);
	
	if(argc>1)
	  load=LoadImageStub(argv[1]);
	
	if(argc>2)
		ObjectDetectionStub::showWhat= argv[2][0]-'0';
	
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
	//int oldmatch=-1;
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
			std::cout<<"                               imgmatch ="<<imgMatch<<std::endl;
			if(imgMatch > -1 && ObjectDetectionStub::showWhat>0){
				ObjectDetectionStub::show(img,&rect[i],255,0,0);
				//imshow("Matching image",subImage);
				oldmatch=true;
				roundmatch=true;
						waitKey(1);
			}
			else if(oldmatch && !roundmatch){
				resize(subImage,subImage,Size(122,173));
				imgMatch = CompareStub::compare(&subImage,hists,featur,blackPixAdded);
				if(imgMatch > -1 && ObjectDetectionStub::showWhat>0){
								ObjectDetectionStub::show(img,&rect[i],255,0,0);
								//imshow("Matching image",subImage);
								waitKey(1);
								roundmatch=true;
				}
			}
			
			
		}
		oldmatch=roundmatch;
		roundmatch=false;
	    imshow("Stream",*img);
		
		printf("The rectangles : %d\n.",vectorsize);
		//printf("There are %lu rectangles \n", rect->size());
		
			
		waitKey(1);
		//sleep(1);
		
		if(waitKey(30)>0)
		break;
		k++;
		imgMatch=-1;
	}while(loop);
	load.releaseCameraCapture();
}