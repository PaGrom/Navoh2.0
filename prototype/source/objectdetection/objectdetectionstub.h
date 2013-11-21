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
	static int tuning(Mat* img, vector<TRectangle> *rect, vector<TLine*> &lines);
	static int distanceKeypoints(vector<KeyPoint> x, vector<KeyPoint> y,vector<DMatch> &matches,double &avgdist1, double &avgdist2);
	
	
public: 
  //modify to use your code
  static int findRectangles(Mat *img, vector<TRectangle> *rect);
  //modify to use your code
  static Mat getSubImageForRectangle(Mat *img, TRectangle* rect, int& blackPixAdded);
  
  static void show(Mat* img, TRectangle* rect, int red, int green , int blue);
  
  static void show(Mat* img, vector<TLine*> &lines,int red, int green, int blue);
  
  static int showWhat;
  static bool checkAngles;
};

#endif