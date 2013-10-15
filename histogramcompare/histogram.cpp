#include "histogram.h"

Histogram::Histogram(){
  int hist_size[]={256,256,256};
  float range1[]= {0,255};
  float range2[]= {0,255};
  float range3[]= {0,255};
  float* ranges[]= {range1,range2,range3};
  hist= cvCreateHist(3,hist_size,CV_HIST_ARRAY,ranges,1);
}

void Histogram::calculate(IplImage *img){
  
  IplImage* rgb = cvCreateImage(cvGetSize(img), IPL_DEPTH_8U,3);
  cvCvtColor(img,rgb,CV_BGR2HSV);
  
  IplImage* red   = cvCreateImage(cvGetSize(img),8,1);
  IplImage* green = cvCreateImage(cvGetSize(img),8,1);
  IplImage* blue  = cvCreateImage(cvGetSize(img),8,1);
  cvCvtPixToPlane (rgb,blue,green,red,0);
  IplImage* planes[]= {red, green, blue};
  // size of planes given to hist as first parameter in cvCreateHist
  cvCalcHist(planes,hist,0,0);

}

CvHistogram* Histogram::getHistogram(){

  return hist;
}

bool operator==(const Histogram& left, const Histogram& right) {
  return (cvCompareHist(left.hist,right.hist,CV_COMP_BHATTACHARYYA)<0.1);
}
