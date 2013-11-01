#include "loadimagestub.h" 



 LoadImageStub::LoadImageStub(){ 
 }
 
 
//modify this function to use your code
   Mat LoadImageStub::getImageFromCamera(){
	  nav.loadImageFromCam(0);
	   return nav.getImg();
  }
  //modify this function to use your code
   Mat LoadImageStub::getImageFromDisk(char* file){
	  return Mat();
  }
   
  void LoadImageStub::releaseCameraCapture(){
	  nav.release();
  }