#include "databaseobject.h"
#include <iostream>

using namespace std;

  DataBaseObject::DataBaseObject(int len,int wid,string image,cv::Mat histograms, cv::Mat features){

  length = len;	  
  width  = wid;
  img    = image;
  hist   = histograms;
  feat   = features;
  
  }
  
  
  int DataBaseObject::getLength(){
	  
    return length;
  }
  
  
  int DataBaseObject::getWidth(){
    return width;
  }
  
  
  cv::Mat DataBaseObject::getImage(){
    return cv::imread(img.c_str());
  }
  
  cv::Mat DataBaseObject::gethist(){
    return hist;
  }
  
  cv::Mat DataBaseObject::getfeat(){
    return feat;
  }
  
  void DataBaseObject::save(const char* file){
    
	cv::FileStorage fs;
    fs.open(file,cv::FileStorage::WRITE);
    if (!(fs.isOpened())){
    	std::cout<<"fail"<<std::endl;
    	return;
    }
    fs << "LENGTH" <<length;
    fs << "HIGHT" << width;
    fs << "IMAGE" << img;
    fs << "HIST" << hist;
    fs << "FEAT" << feat;
     
	fs.release();  
  }

  DataBaseObject DataBaseObject::load(const char* file){
    
	cv::FileStorage fs;
	fs.open(file,cv::FileStorage::READ);
	
	if (!fs.isOpened()) {std::cout << "unable to open file storage!" << std::endl;}
	
	int length;
	int width;
	string img;
	cv::Mat hist;
	cv::Mat feat;
	
	fs["LENGTH"] >> length;  
	fs["HIGHT"] >> width;
	fs["IMAGE"] >> img;
	fs["HIST"] >> hist;
	fs["FEAT"] >> feat;
	
	fs.release();
	
	return DataBaseObject(length,width,img,hist,feat);
	  
  }
  