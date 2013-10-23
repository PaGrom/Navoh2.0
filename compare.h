#include "featurematching/featurematching.h"
#include "histogramcompare/histogram.h"

#define MINMATCHES 60

class Compare{
  
public:
  static int compare(Mat img, vector<Mat> histograms, vector<Mat> features);
  static vector<int> compareHist(Mat img, vector<Mat> histograms);
  static int matchFeatures(Mat img, vector<Mat> features, vector<int> pics);

};