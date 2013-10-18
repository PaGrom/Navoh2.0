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
  static Mat loadFeatures(char* image);
  //modify to use your code
  static CvHistogram* loadHistogram(char* image);
	
};