#include "histogram.h"

Histogram::Histogram(){
  int hist_size[]={256,256,256};
  float range1[]= {0,255};
  float range2[]= {0,255};
  float range3[]= {0,255};
  float* ranges[]= {range1,range2,range3};
  hist= cvCreateHist(3,hist_size,CV_HIST_ARRAY,ranges,1);
}

void Histogram::calculate(IplImage **img){

cvCalcHist(img,hist,0,0);

}

CvHistogram* Histogram::getHistogram(){

  return hist;
}

bool operator==(const Histogram& left, const Histogram& right) {
  return (cvCompareHist(left.hist,right.hist,CV_COMP_BHATTACHARYYA)<0.1);
}
