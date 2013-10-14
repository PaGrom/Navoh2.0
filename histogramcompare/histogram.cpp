#include "histogram.h"

void Histogram::calculate(Mat img){

	vector<Mat> rgb_plane;
	split(img,rgb_plane);
	float range[]={0,256};
	const float* histRange = {range};
	int size = HISTSIZE;

	calcHist(&rgb_plane[2],1,0,Mat(),hist[2],1,&size,&histRange,true, false);
	calcHist(&rgb_plane[1],1,0,Mat(),hist[1],1,&size,&histRange,true, false);
	calcHist(&rgb_plane[0],1,0,Mat(),hist[0],1,&size,&histRange,true, false);

}

Mat* Histogram::getHistograms(){

	return hist;
}

bool operator==(const Histogram& left, const Histogram& right) {
bool check=  false;


return check;
}
