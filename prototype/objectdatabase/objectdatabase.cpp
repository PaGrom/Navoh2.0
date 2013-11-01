#include "ojectdatabase.h"


static saveToDatabase(Mat img,Mat histogram, Mat featurePoints);
	static vector<Mat> loadHistograms();
	static vector<Mat> loadFeatures();
	static DataBaseObject getMatchingImage();