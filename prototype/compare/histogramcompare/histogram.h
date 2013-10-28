
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


public:
  Histogram();
  Histogram(Mat histo);

  void calculate(Mat img);

  Mat getHistogram();

  friend bool operator==(const Histogram& left, const Histogram& right);


};

#endif
