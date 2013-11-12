#ifndef DATABASEOBJECT
#define DATABASEOBJECT
#include <cv.h>
#include <highgui.h>

using namespace std;
class DataBaseObject {

private:
	int length;
	int width;
	string img;
	cv::Mat hist;
	cv::Mat feat;
public:
	DataBaseObject(int length,int width,string image,cv::Mat histograms, cv::Mat features);
	int getLength();
	int getWidth();
	cv::Mat getImage();
	cv::Mat gethist();
	cv::Mat getfeat();
	void save(const char* file);
	static DataBaseObject load(const char* file);
	
};

#endif