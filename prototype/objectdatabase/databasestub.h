//
//#define OWN_DATABASE
//

#ifndef OWN_DATABASE
#define OWN_DATABASE

#include <cv.h>
using namespace cv;

#endif

class DatabaseStub {
	
public:
  //modify to use your code
  static vector<Mat>* loadFeatures();
  //modify to use your code
  static vector<Mat>* loadHistograms();
	
};