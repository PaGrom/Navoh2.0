#ifndef _NAVOH_h
#define _NAVOH_h

#include <string>
#include <iostream>
#include <cv.h>
#include <highgui.h>
#include "exception.h"

class Navoh {
private:
  IplImage* image;
public:
  Navoh();
  ~Navoh();
  void loadImageFromFile(std::string imageName);
  void loadImageFromCam(int devNumber);
  void displayImage();
};

#endif