
#ifndef EXTRACTEDPICTURE
#define EXTRACTEDPICTURE

#include <cv.h>
#include "trectangle.h"

using namespace cv;

class ExtractedPicture{
	
  private:
  
  IplImage* img;
  TRectangle rect;
  int numberOfBlacksadded;
  
  IplImage* cutImage(IplImage* img, TRectangle rect);
  
  public:
  
  ExtractedPicture(IplImage* image, TRectangle rectangle);
  IplImage* getImage();
  int getNumber();
  
};

#endif