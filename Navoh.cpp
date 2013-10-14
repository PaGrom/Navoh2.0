#include "Navoh.h"

Navoh::Navoh() {

}

Navoh::~Navoh() {

}

void Navoh::load(std::string imageName) {
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
  cvReleaseCapture(&capture);
}

void Navoh::displayImage() {
  cvNamedWindow("Navoh");
  cvShowImage("Image", image);
  cvWaitKey();
}
