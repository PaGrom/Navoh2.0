#include databaseobject.h

  DataBaseObject::DataBaseObject(int length,int width,Mat image,Mat histograms, Mat features){

  this.length = length;	  
  this.width  = width;
  this.img    = image;
  this.hist   = histograms;
  this.feat   = features;
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
  
  void DataBaseObject::save(char* file){
    
	cv::FileStorage fs;
    fs.open(file,cv::FileStorage::WRITE);
    
    fs << "LENGTH" <<length;
    fs << "HIGHT" << width;
    fs << "IMAGE" << img;
    fs << "HIST" << hist;
    fs << "FEAT" << feat;
     
	fs.release();  
  }

  DataBaseObject DataBaseObject::load(char* file){
    
	cv::FileStorage fs;
	fs.open(file,cv::FileStorage::READ);
	  
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
	
	return DataBaseObject(length,width,img,hist,feat);
	  
  }
  