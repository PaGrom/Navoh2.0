#include "Navoh.h"

Navoh::Navoh() {

}

Navoh::~Navoh() {

}

void Navoh::loadImageFromFile(std::string imageName) {
  img = cvLoadImage(imageName.c_str(), 1);
  if (!image) {
    throw openImageException();
    return;
  }
  cap.set(CV_CAP_PROP_FRAME_WIDTH, 320);
  cap.set(CV_CAP_PROP_FRAME_HEIGHT, 240);
}
void Navoh::capture(int devNumber){
	  cap = cv::VideoCapture(devNumber);
	  if (!cap.isOpened()) {
	    throw captureCameraException();
	    return;
	  }
	  cap.set(CV_CAP_PROP_FRAME_WIDTH, 320);
	  cap.set(CV_CAP_PROP_FRAME_HEIGHT, 240);
}
void Navoh::captureFromVideo(std::string file){
	  cap = cv::VideoCapture(file);
	  if (!cap.isOpened()) {
	    throw captureCameraException();
	    return;
	  }
	  cap.set(CV_CAP_PROP_FRAME_WIDTH, 320);
	  cap.set(CV_CAP_PROP_FRAME_HEIGHT, 240);
}

void Navoh::loadImageFromCam() {
  
    //cvReleaseCapture(&capture);
  cap >> img;
}

void Navoh::displayImage() {
  cvNamedWindow("Navoh");
  cvShowImage("Image", image);
  cvWaitKey(0);
}

void Navoh::release(){
	//cvReleaseCapture(&cap);
}

cv::Mat* Navoh::getImg(){
  return &img;
}