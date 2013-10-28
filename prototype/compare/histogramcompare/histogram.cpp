#include "histogram.h"

Histogram::Histogram(){

}

Histogram::Histogram(Mat histo){
  hist=histo;
}

void Histogram::calculate(Mat img){
	  
  int hist_size[]={181,256};
  float rangeh[]= {0,180};
  float rangeS[]= {0,255};
  const float* ranges[]= {rangeh,rangeS};
  int chanels[]={0,1};
  Mat hsv;
  cvtColor(img,hsv, CV_BGR2HSV);
  calcHist(&hsv,1,chanels,Mat(),hist,2,hist_size,ranges,true, false);
  normalize( hist, hist, 0, 1, NORM_MINMAX, -1, Mat() );
  //printf("Type %d, should be %d \n", hist.type(), CV_32F);
}
  
  
Mat Histogram::getHistogram(){

  return hist;
}

bool operator==(const Histogram& left, const Histogram& right) {
  
	//printf("Type %d and %d, should be %d \n", left.hist.type(),right.hist.type(), CV_32F);
  double x =compareHist(left.hist,right.hist,CV_COMP_BHATTACHARYYA);
  return (x<0.6);
}
