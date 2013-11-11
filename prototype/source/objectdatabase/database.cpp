#include "database.h"

Database::Database(){};


Database::Database(string folder){
	//load all images
	int databaselength=-1;
	
	string res= folder + "/elements.txt";
	std::ifstream databaseLengthFile (res.c_str());
	if(!databaseLengthFile.is_open())
		return;
	
	std::ostringstream stream;
	string filenumber;
	string file;
	databaseLengthFile >> databaselength;
	
	objects = vector<DataBaseObject>();
	for(int i=0; i<databaselength ;++i)
	{
	filenumber="";
	stream << i;
	filenumber= stream.str();
	file=folder+filenumber+".xml";
	objects.push_back(DataBaseObject::load(file.c_str()));
	}
	fold =folder;
}

void Database::saveToDatabase(Mat img,Mat histogram, Mat featurePoints){
	//save one image to the database
	int databaselength;
	DataBaseObject obj(-1,-1,img,histogram,featurePoints);
	
	string res= fold + "/elements.txt";
	
	std::ifstream databaseLengthFile (res.c_str());
	if(!databaseLengthFile.is_open())
		return;
		
	std::ostringstream stream;
	string filenumber;
	string file;
	databaseLengthFile >> databaselength;
	
	filenumber="";
	databaselength++;
	stream << databaselength;
	filenumber= stream.str();
	file=fold+"/"+filenumber+".xml";
	databaseLengthFile.close();
	
	obj.save(file.c_str());
	
	std::ofstream outfile;
	outfile.open(res.c_str(), std::ofstream::out);
	outfile << databaselength;
	outfile.close();
	
}


vector<Mat> Database::loadHistograms(){
	vector <Mat> hist;
	for (unsigned int i=0; i<objects.size();++i){
	  hist.push_back(objects[i].gethist());
	}
	return hist;
}

vector<Mat> Database::loadFeatures(){
	vector <Mat> feat;
	for (unsigned int i=0; i<objects.size();++i){
	  feat.push_back(objects[i].getfeat());
	}
	return feat;
}

DataBaseObject* Database::getMatchingImage(int id){
	return &(objects[id]);
}