#include "database.h"

Database::Database(){};


Database::Database(string folder){
	//load all images
	objects = vector<DataBaseObject>();
}

void Database::saveToDatabase(Mat img,Mat histogram, Mat featurePoints){
	//save one image to the database
}


vector<Mat> Database::loadHistograms(){
	vector <Mat> hist;
	for (int i=0; i<object.size(),++i){
	  hist.push_back(objects[i].gethist());
	}
	return hist;
}

vector<Mat> Database::loadFeatures(){
	vector <Mat> feat;
	for (int i=0; i<object.size(),++i){
	  feat.push_back(objects[i].getfeat());
	}
	return feat;
}

DataBaseObject* Database::getMatchingImage(int id){
	return &(objects[id]);
}