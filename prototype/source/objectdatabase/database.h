
#ifndef DATABASESAVELOAD
#define DATABASESAVELOAD
#include <cv.h>
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <sstream>
#include "databaseobject.h"


using namespace cv;

class Database {
private:
	Mat loadsingleHist(int id);
	Mat loadsingleFeat(int id);
	vector<DataBaseObject> objects;
	string fold;
	
public:
	Database();
	Database(string folder);
	void saveToDatabase(Mat img,Mat histogram, Mat featurePoints);
	vector<Mat> loadHistograms();
	vector<Mat> loadFeatures();
	DataBaseObject* getMatchingImage(int id);
	
};

#endif