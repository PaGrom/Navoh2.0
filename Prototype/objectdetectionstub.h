#ifndef OWN_OBJECTDETEKTION
#define OWN_OBJECTDETECTION

#include <cv.h>
#include <iostream>
#include "trectangle.h"

#endif

class ObjectDetectionStub{
	
  public: 
  //modify to use your code
  vector<TRectangle> findRectangles(IplImage* img);
  //modify to use your code
  vector<IplImage*> getImagesToCompare(vector<TRectangle> rects);
};