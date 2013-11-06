#ifndef CUTRECT
#define CUTRECT

#include <cv.h>
#include "objectlibs/trectangle.h"

using namespace std;

class CutImage{

public:
	cv::Mat getSubImage(TRectangle *rect, cv::Mat* img); 
	
	
	
};
#endif