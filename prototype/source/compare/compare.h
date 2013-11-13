
#ifndef COMPARE
#define COMPARE

#include "featurematching/featurematching.h"
#include "histogramcompare/histogram.h"

#define MINMATCHES 20

class Compare{
  
public:
  static int compare(Mat *img, vector<Mat> *histograms, vector<Mat> *features,int& blackPixAdded);
  static vector<int> compareHist(Mat *img, vector<Mat> *histograms);
  static int matchFeatures(Mat *img, vector<Mat> *features, vector<int> *pics);

};

#endif