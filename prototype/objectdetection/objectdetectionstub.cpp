#include "objectdetectionstub.h"

  //test function to use
   vector<TRectangle> ObjectDetectionStub::findRectangles(Mat img){
   Mat grey;
   cvtColor(img, grey, CV_BGR2GRAY);
   TSafeVector lines, rectangles;
   LinesFromMat(&grey,&lines);
   calcRectangles(&lines,&rectangles);
   vector<TRectangle> rect;
   DrawRect(&img,&rectangles,CV_RGB(0,255,0));
   for(int i=0; i<rectangles.length();++i){
	   rect.push_back(*((TRectangle*) rectangles.get(i)));
   }
	  return rect;
  }
  //modify to use your code
   vector<Mat> ObjectDetectionStub::getImagesToCompare(Mat img){
	  vector<Mat> Mats;
	  return Mats;
  }