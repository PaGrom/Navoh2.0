#include "Navoh.h"

Navoh::Navoh() {

}

Navoh::~Navoh() {

}

void Navoh::load(std::string imageName) {
  image = cvLoadImage(imageName.c_str(), 1);
  if (!image)
    throw openImageException();
}

void Navoh::loadImageFromCam(int devNumber) {
  CvCapture* capture = cvCaptureFromCAM(devNumber);
  image = cvQueryFrame(capture);
}

void Navoh::displayImage() {
  cvNamedWindow("Navoh");
  cvShowImage("Image", image);
  cvWaitKey();
}
