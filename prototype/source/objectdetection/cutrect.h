#ifndef CUTRECT
#define CUTRECT

#include <cv.h>
#include "objectlibs/trectangle.h"

using namespace std;

class CutImage{
private:
	static int blackOutside(TRectangle *rect,cv::Mat *img);
	
public:
	static cv::Mat getSubImage(TRectangle *rect, cv::Mat* img, int& blackPixAdded); 
	
	
	
};
#endif
