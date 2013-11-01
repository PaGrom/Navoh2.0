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
  cv::VideoCapture cap;
  cv::Mat img;
public:
  Navoh();
  ~Navoh();
  void capture(int devNumber);
  void loadImageFromFile(std::string imageName);
  void loadImageFromCam();
  void displayImage();
  void release();
  cv::Mat getImg();
};

#endif