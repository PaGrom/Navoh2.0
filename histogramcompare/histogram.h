#include <cv.h>
#include <highgui.h>

#include <math.h>
#include <iostream>

#define HISTSIZE 256

using namespace cv;

class Histogram {
private:

 CvHistogram* hist;


public:
Histogram();

void calculate(IplImage** img);

CvHistogram* getHistogram();

friend bool operator==(const Histogram& left, const Histogram& right);


};
