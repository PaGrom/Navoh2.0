
#ifndef DATABASESAVELOAD
#define DATABASESAVELOAD
#include <cv.h>

using namespace cv;

class Database {
private:
	Mat loadsingleHist(int id);
	Mat loadsingleFeat(int id);
	
public: 
	static saveToDatabase(Mat img,Mat histogram, Mat featurePoints);
	static vector<Mat> loadHistograms();
	static vector<Mat> loadFeatures();
	static DataBaseObject getMatchingImage();
	
};

#endif