//
//#define OWN_DATABASE
//

#ifndef OWN_DATABASE
#define OWN_DATABASE

#include <cv.h>
#include <highgui.h>
#include "database.h"
using namespace cv;



class DatabaseStub{
private:
  
  //Database data;
  vector<Mat> feats;
  vector<Mat> hists;
  
  
public:
  
  DatabaseStub();
  //modify to use your code
  vector<Mat>* loadFeatures();
  //modify to use your code
  vector<Mat>* loadHistograms();
  
  void saveImage(string file,Mat img);
  
};

#endif