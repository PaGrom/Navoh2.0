#ifndef OWN_OBJECTDETEKTION
#define OWN_OBJECTDETECTION

#include <cv.h>
#include <iostream>
#include "objectlibs/trectangle.h"

using namespace cv;

#endif

class ObjectDetectionStub{
	
  public: 
  //modify to use your code
  static vector<TRectangle> findRectangles(Mat img);
  //modify to use your code
  static vector<Mat> getImagesToCompare(Mat img);
};