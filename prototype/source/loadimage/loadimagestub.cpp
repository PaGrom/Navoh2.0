#include "loadimagestub.h" 



 LoadImageStub::LoadImageStub(int dev){
   nav= Navoh();
   nav.capture(0);
 }
 
 LoadImageStub::LoadImageStub(char* file){
   nav= Navoh();
   nav.captureFromVideo(file);
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