
#ifndef HISTOGRAM
#define HISTOGRAM

#include <cv.h>
#include <highgui.h>

#include <math.h>
#include <iostream>

#define HISTSIZE 256

using namespace cv;

class Histogram {
private:

  MatND hist;
  void eraseBlackPix(int& blackPixAdded);

public:
  Histogram();
  Histogram(Mat histo);

  void calculate(Mat *img, int& blackPixAdded);
 
  Mat getHistogram();

  friend bool operator==(const Histogram& left, const Histogram& right);


};

#endif
