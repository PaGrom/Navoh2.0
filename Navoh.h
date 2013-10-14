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
  void load(std::string imageName);
};

#endif