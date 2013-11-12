#include "databaseobject.h"
#include <iostream>

using namespace std;

  DataBaseObject::DataBaseObject(int len,int wid,cv::Mat image,cv::Mat histograms, cv::Mat features){

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
    return img;
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
	cv::Mat img;
	cv::Mat hist;
	cv::Mat feat;
	
	fs["LENGTH"] >> length;  
	fs["HIGHT"] >> width;
	fs["IMAGE"] >> img;
	fs["HIST"] >> hist;
	fs["FEAT"] >> feat;
	
	fs.release();
	cout << length << " and " << width << endl;
	
	cout<<"type is :" << img.type() << " ? "<< CV_32F << "|"<<img.rows << ", " << img.cols << endl; 
		
	cout<<"type is :" << hist.type() << " ? "<< CV_32F << "|"<<hist.rows << ", " << hist.cols << endl; 
	return DataBaseObject(length,width,img,hist,feat);
	  
  }
  