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
  for(int i=1; i<databaselength ;++i)
  {
  filenumber="";
  stream.str("");
  stream.clear();
  stream << i;
  filenumber= stream.str();
  file=folder+"/data/"+filenumber+".xml";
  std::cout<<file<<std::endl;
  objects.push_back(DataBaseObject::load(file.c_str()));
  }
  fold =folder;
}

void Database::saveToDatabase(Mat img,Mat histogram, Mat featurePoints){
  //save one image to the database
  int databaselength;
  
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
  
    
  
  string imgpath= fold+"/pic/"+filenumber+".ppm";
  cv::imwrite(imgpath,img);
  
  file=fold+"/data/"+filenumber+".xml";
  databaseLengthFile.close();
  
  DataBaseObject obj(-1,-1,imgpath,histogram,featurePoints);
  
  obj.save(file.c_str());
  
    
  
  std::ofstream outfile;
  outfile.open(res.c_str(), std::ofstream::out);
  outfile << databaselength;
  outfile.close();
  
}


void Database::loadHistograms(vector<Mat> &hist){
  
  for (unsigned int i=0; i<objects.size();++i){
    hist.push_back(objects[i].gethist());
  }
}

void Database::loadFeatures(vector<Mat> &feat){
  
  for (unsigned int i=0; i<objects.size();++i){
    feat.push_back(objects[i].getfeat());
  }
  
}

DataBaseObject* Database::getMatchingImage(int id){
  return &(objects[id]);
}