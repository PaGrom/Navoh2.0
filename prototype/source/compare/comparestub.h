
#ifndef COMPARESTUB
#define COMPARESTUB

#include <cv.h> 
#include <cstdio>
#include "histogramcompare/histogram.h"
#include "compare.h"



class CompareStub {
	
public:
  //modify this function to use your code
	
  // one step comparison with complete vectors
  static int compare(Mat *img, vector<Mat> *hists, vector<Mat> *features,int& blackPixAdded);
  // histogram comparison returning a vector with image numbers which match a condition
  static vector<int> comparehist(Mat *img, vector<Mat> *hists);
  
  /*
   * matches the images feature points with those given to him by the featurePoints 
   * vector returns the image number with the most good matches
  */
  static int matchFeaturePoints(Mat *img, vector<Mat> *featurePoints, vector<int> *imageList);
};

#endif