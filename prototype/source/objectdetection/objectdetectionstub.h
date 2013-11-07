#ifndef OWN_OBJECTDETEKTION
#define OWN_OBJECTDETECTION

#include <cv.h>
#include <iostream>
#include "objectlibs/trectangle.h"
#include "cvrect.h"
#include "findrect.h"
#include "cutrect.h"

using namespace cv;

#endif

class ObjectDetectionStub{
  

  public: 
  //modify to use your code
  static int findRectangles(Mat *img, vector<TRectangle> *rect);
  //modify to use your code
  static Mat getSubImageForRectangle(Mat *img, TRectangle* rect);
  
  static void show(Mat* img, TRectangle* rect, int pos);
};