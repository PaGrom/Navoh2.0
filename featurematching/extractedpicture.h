
#ifndef EXTRACTEDPICTURE
#define EXTRACTEDPICTURE

#include <cv.h>
#include "trectangel.h"

class ExtractedPicture{
	
  private:
  
  IplImage* img;
  Trectangle rect;
  int numberOfBlacksadded;
  
  IplImage* cutImage(IplImage* img, TRectangle rect);
  
  public 
  
  ExtractedPicture(IplImage* image, TRectangle rectangle);
  IplImage* getImage();
  int getNumber();
  
};

#endif