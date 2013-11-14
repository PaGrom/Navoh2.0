#ifndef OWN_OBJECTDETEKTION
#define OWN_OBJECTDETECTION

#include <cv.h>
#include <iostream>
#include "objectlibs/trectangle.h"
#include "cvrect.h"
#include "findrect.h"
#include "cutrect.h"
#include "../compare/featurematching/featurematching.h"
#include <math.h>

using namespace cv;

#define MAXDISTKEYPOINTS 10


class ObjectDetectionStub{
private:
  
	static Mat desc1;
	static vector<KeyPoint> key;
	static int detectRect;
	static int tuning(Mat* img, vector<TRectangle> *rect);
	static int distanceKeypoints(vector<KeyPoint> x, vector<KeyPoint> y,vector<DMatch> &matches);
	
	
public: 
  //modify to use your code
  static int findRectangles(Mat *img, vector<TRectangle> *rect);
  //modify to use your code
  static Mat getSubImageForRectangle(Mat *img, TRectangle* rect, int& blackPixAdded);
  
  static void show(Mat* img, TRectangle* rect, int pos);
};

#endif