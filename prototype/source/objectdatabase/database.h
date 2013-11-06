
#ifndef DATABASESAVELOAD
#define DATABASESAVELOAD
#include <cv.h>
#include "databaseobject.h"

using namespace cv;

class Database {
private:
	Mat loadsingleHist(int id);
	Mat loadsingleFeat(int id);
	vector<DataBaseObject> objects;
	
public:
	Database();
	Database(string folder);
	static void saveToDatabase(Mat img,Mat histogram, Mat featurePoints);
	static vector<Mat> loadHistograms();
	static vector<Mat> loadFeatures();
	static DataBaseObject getMatchingImage(int id);
	
};

#endif