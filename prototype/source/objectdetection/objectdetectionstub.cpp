#include "objectdetectionstub.h"
#include <cstdio>
  //test function to use
int ObjectDetectionStub::findRectangles(Mat* img,vector<TRectangle> *rect){

  int i;
   
  Mat grey;
  cvtColor(*img, grey, CV_BGR2GRAY);
   
  TSafeVector lines, rectangles,merged;
  LinesFromMat(&grey,&lines);
   //mergeLines(&lines,&merged, 5, 10,10);
  calcRectangles(&lines,&rectangles);
  DrawRect(img,&rectangles,CV_RGB(0,255,0));
   //printf("%d \n", rectangles.length());
  for(i=0; i<rectangles.length();++i){
	   
	   (*rect)[i] = *((TRectangle*) rectangles.get(i));
	   //rect->push_back(*((TRectangle*) rectangles.get(i)));
  }
  
  return i;
}


  //modify to use your code
   Mat ObjectDetectionStub::getSubImageForRectangle(Mat *img,TRectangle* rect){
	  
	  return CutImage::getSubImage(rect,img);
  }
   
   void ObjectDetectionStub::show(Mat* img, TRectangle* rect, int size){
	   
   }