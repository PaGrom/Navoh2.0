
#include <cv.h>
#include <highgui.h>
#include "compare/featurematching/featurematching.h"
#include "compare/histogramcompare/histogram.h"
#include "objectdatabase/database.h"

using namespace cv;

int main(int argc, char** argv){
	
  for(int i=1; i<argc;++i){
	  Mat img= imread(argv[i]); 
	  
	  int k =0;
	  Histogram histo;
	  histo.calculate(&img,k);
	  Mat hist =histo.getHistogram();
	  
	  vector<KeyPoint> key;
	  Mat feat= FeatureMatching::detectAndDiscribeFeatures(img,key);
	  
	  Database data("testdatabase");
	  data.saveToDatabase(img,hist,feat);
  }
	
	
}