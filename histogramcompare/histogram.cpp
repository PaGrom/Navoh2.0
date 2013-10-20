#include "histogram.h"

Histogram::Histogram(){

}

/*Histogram::Histogram(Mat histo){
  hist=histo;
}*/

void Histogram::calculate(Mat img){
	  
  int hist_size[]={181,256};
  float rangeh[]= {0,180};
  float rangeS[]= {0,255};
  const float* ranges[]= {rangeh,rangeS};
  int chanels[]={0,1};
  MatND hist;
  Mat hsv;
  cvtColor(img,hsv, CV_BGR2HSV);
  
  
  
  calcHist(&hsv,1,chanels,Mat(),hist,2,hist_size,ranges,true, false);
  //cvNormalizeHist(hist,1.0);
  
}
  
  
Mat Histogram::getHistogram(){

  return hist;
}

bool operator==(const Histogram& left, const Histogram& right) {
  
  
  return (compareHist(left.hist,right.hist,CV_COMP_BHATTACHARYYA)<0.6);
}
