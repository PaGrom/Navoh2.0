
#ifndef FEATUREMATCHING
#define FEATUREMATCHING

#include <cv.h>
#include <highgui.h>
#include <stdio.h>
#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/nonfree/features2d.hpp"

using namespace cv;

#define MAXDIST 50
#define MAXFEATUREPOINTS 200

class FeatureMatching{
	
public:
	
	 static Mat detectAndDiscribeFeatures(Mat img,vector<KeyPoint> &key);
	 static vector<DMatch> matchFeatures(Mat img1,Mat img2);

};

#endif