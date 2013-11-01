#ifndef DATABASEOBJECT
#define DATABASEOBJECT
#include <cv.h>

class DataBaseObject {

private:
	int length;
	int width;
	cv::Mat img;
public:
	DataBaseObject(int length,int width,Mat image);
	int getLength();
	int getWidth();
	cv::Mat getImage();
	
};

#endif