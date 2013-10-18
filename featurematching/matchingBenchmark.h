#include <cv.h>
#include <highgui.h>
#include <stdio.h>
#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/nonfree/features2d.hpp"
#include <sys/time.h>

using namespace cv;

void detektAndCompare(IplImage *im, IplImage *im2);

void detektAndCompare2(IplImage *im, IplImage *im2);