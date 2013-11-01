#include "Navoh.h"

Navoh::Navoh() {

}

Navoh::~Navoh() {

}

void Navoh::loadImageFromFile(std::string imageName) {
  image = cvLoadImage(imageName.c_str(), 1);
  if (!image) {
    throw openImageException();
    return;
  }
}

void Navoh::loadImageFromCam(int devNumber) {

  CvCapture* capture = NULL;
  capture = cvCaptureFromCAM(devNumber);
  if (!capture) {
    throw captureCameraException();
    return;
  }
  image = cvQueryFrame(capture);
    //cvReleaseCapture(&capture);
  img=image;
  cap=capture;
}

void Navoh::displayImage() {
  cvNamedWindow("Navoh");
  cvShowImage("Image", image);
  cvWaitKey(0);
}

void Navoh::release(){
	cvReleaseCapture(&cap);
}

cv::Mat Navoh::getImg(){
  return img;
}