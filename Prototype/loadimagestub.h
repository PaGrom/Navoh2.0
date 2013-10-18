/*
#define OWN_LOADIMAGE
//your include(s) here
 
 */

#ifndef OWN_LOADIMAGE 
#define OWN_LOADIMAGE

#include <cv.h>
using namespace cv;

#endif

class LoadImageStub{
	
public:
  //modify this function to use your code
  static IplImage* getImageFromCamera();
  //modify this function to use your code
  static IplImage* getImageFromDisk(char* file);
  
};