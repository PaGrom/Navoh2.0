#include <cv.h>
#include <highgui.h>

#include <math.h>
#include <iostream>

#define HISTSIZE 256

using namespace cv;

class Histogram {
private:

 Mat hist;


public:
  Histogram();
  Histogram(CvHistogram* histo);

  void calculate(Mat img);

  Mat getHistogram();

  friend bool operator==(const Histogram& left, const Histogram& right);


};
