#ifndef DATABASEOBJECT
#define DATABASEOBJECT
#include <cv.h>
 

class DataBaseObject {

private:
	int length;
	int width;
	cv::Mat img;
	cv::Mat hist;
	cv::Mat feat;
public:
	DataBaseObject(int length,int width,cv::Mat image,cv::Mat histograms, cv::Mat features);
	int getLength();
	int getWidth();
	cv::Mat getImage();
	cv::Mat gethist();
	cv::Mat getfeat();
	void save(const char* file);
	static DataBaseObject load(const char* file);
	
};

#endif