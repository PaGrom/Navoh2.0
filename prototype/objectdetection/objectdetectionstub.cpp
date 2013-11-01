#include "objectdetectionstub.h"

  //test function to use
   vector<TRectangle> ObjectDetectionStub::findRectangles(Mat img){
   TSafeVector lines, rectangles;
   LinesFromMat(&img,&lines);
   calcRectangles(&lines,&rectangles);
   vector<TRectangle> rect;
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