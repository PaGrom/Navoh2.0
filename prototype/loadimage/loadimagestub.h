/*
#define OWN_LOADIMAGE
//your include(s) here
 
 */

#ifndef OWN_LOADIMAGE 
#define OWN_LOADIMAGE

#include <cv.h>
#include"Navoh.h"
using namespace cv;

#endif

class LoadImageStub{
private:
  Navoh nav;
public:
  LoadImageStub(int dev);
  //modify this function to use your code
  Mat getImageFromCamera();
  //modify this function to use your code
  Mat getImageFromDisk(char* file);
  
  void releaseCameraCapture();
};