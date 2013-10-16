#include "histogram.h"

Histogram::Histogram(){
  int hist_size[]={181,256};
  float rangeh[]= {0,180};
  float rangeS[]= {0,255};
  float* ranges[]= {rangeh,rangeS};
  hist= cvCreateHist(2,hist_size,CV_HIST_ARRAY,ranges,1);
}

void Histogram::calculate(IplImage *img){
  
  IplImage* hsv = cvCreateImage(cvGetSize(img), IPL_DEPTH_8U,3);
  cvCvtColor(img,hsv, CV_BGR2HSV);
  IplImage* h   = cvCreateImage(cvGetSize(hsv),8,1);
  IplImage* s = cvCreateImage(cvGetSize(hsv),8,1);
  IplImage* v  = cvCreateImage(cvGetSize(hsv),8,1);
  cvCvtPixToPlane (hsv,h,s,v,0);
  IplImage* planes[]= {h, s};
  // size of planes given to hist as first parameter in cvCreateHist
  cvCalcHist(planes,hist,0,0);
  cvNormalizeHist(hist,1.0);
  
}
  
  
CvHistogram* Histogram::getHistogram(){

  return hist;
}

bool operator==(const Histogram& left, const Histogram& right) {
  
  
  return (cvCompareHist(left.hist,right.hist,CV_COMP_BHATTACHARYYA)<0.6);
}
