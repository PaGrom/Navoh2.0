#include "loadimagestub.h" 



 LoadImageStub::LoadImageStub(int dev){
	 nav= Navoh();
	 nav.captureFromVideo("test.mp4");
 }
 
 
//modify this function to use your code
   Mat* LoadImageStub::getImageFromCamera(){
	  nav.loadImageFromCam();
	   return nav.getImg();
  }
  //modify this function to use your code
   Mat LoadImageStub::getImageFromDisk(char* file){
	  return Mat();
  }
   
  void LoadImageStub::releaseCameraCapture(){
	  nav.release();
  }