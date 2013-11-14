#include "objectdetectionstub.h"
#include <cstdio>
  //test function to use

vector<KeyPoint> ObjectDetectionStub::key;
Mat ObjectDetectionStub::desc1;
int ObjectDetectionStub::detectRect=0;

int ObjectDetectionStub::findRectangles(Mat* img,vector<TRectangle> *rect){

  int i;
  
  
  Mat grey;
  cvtColor(*img, grey, CV_BGR2GRAY);
   
  TSafeVector lines, rectangles,merged;
  LinesFromMat(&grey,&lines);
   //mergeLines(&lines,&merged, 5, 10,10);
  calcRectangles(&lines,&rectangles);
  //DrawRect(img,&rectangles,CV_RGB(0,255,0));
   //printf("%d \n", rectangles.length());
  for(i=0; i<rectangles.length();++i){
	   
	   (*rect)[i] = *((TRectangle*) rectangles.get(i));
	   //rect->push_back(*((TRectangle*) rectangles.get(i)));
  }
  if(i<detectRect)
  {
    i=ObjectDetectionStub::tuning(img,rect);
  }
  else
	 desc1= FeatureMatching::detectAndDiscribeFeatures(*img,key,10);
  
  detectRect=i;
  return i;
}


  //modify to use your code
   Mat ObjectDetectionStub::getSubImageForRectangle(Mat *img,TRectangle* rect, int &blackPixAdded){
	   Mat subimg=CutImage::getSubImage(rect,img,blackPixAdded);
	  return subimg;
  }
   
   void ObjectDetectionStub::show(Mat* img, TRectangle* rect, int pos){
	   
	   for(int j=1; j<5; j++){
	   						line(*img, Point(rect->getLine(j)->getp1()->getx(),
	   								rect->getLine(j)->getp1()->gety()), 
	   										Point(rect->getLine(j)->getp2()->getx(),
	   												rect->getLine(j)->getp2()->gety()), 
	   							CV_RGB(255,0,0), //color of the lines
	   							4, //thickness
	   							8, 0 );
	   }
	   
   }
   
int ObjectDetectionStub::tuning(Mat* img, vector<TRectangle> *rect){
	
	vector<KeyPoint> key2;
	Mat desc2= FeatureMatching::detectAndDiscribeFeatures(*img,key2,10);
	vector<DMatch> matches= FeatureMatching::matchFeatures(desc2,desc1);
	if(distanceKeypoints(key,key2,matches)<MAXDISTKEYPOINTS){
		
	
	}
	
	key=key2;
	desc1=desc2;
	
	return 0;

}

int ObjectDetectionStub::distanceKeypoints(vector<KeyPoint> x, vector<KeyPoint> y,vector<DMatch> &matches){
	
	double dist=0;
	double oldMidX=0,oldMidY=0,NewMidX=0,NewMidY=0;
	
	double i;
	
	for(i=0; i<matches.size(); ++i){
		    
		oldMidX+=(x[matches[i].queryIdx].pt).x;
		oldMidY+=(x[matches[i].queryIdx].pt).y;
		  
		NewMidX+=(y[matches[i].trainIdx].pt).x;
		NewMidY+=(y[matches[i].trainIdx].pt).y;
		
		
	}
	oldMidX/=i;
	oldMidY/=i;
	
	NewMidX/=i;
	NewMidY/=i;
	
	return (sqrt((NewMidX-oldMidX)*(NewMidX-oldMidX)+(NewMidY-oldMidY)*(NewMidY-oldMidY)));
}