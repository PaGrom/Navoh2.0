#include "compare.h"
#include <sys/time.h>
#define SIZE 100
#define TESTSIZE 100

void createTestBenchValues(Mat* imgs, int n,int size,vector<Mat> &hists, vector<Mat> &feat);


int main(int arc,char** argv){

	timeval start, end;
	double v1s,v1us,v2s,v2us, times=0,timeus=0; 
	v1s=v1us=v2s=v2us=0;
	int k,m;	
    vector<int> num;
	vector<Mat> feat2;
    Mat img;
	Mat a[3];
    a[0] = imread("./featurematching/out002.ppm");
	a[1] = imread("./featurematching/out002.ppm");
	a[2] = imread("./featurematching/res.ppm");
	
	vector<Mat> hists, feat;
	
	createTestBenchValues(a,3,SIZE,hists,feat);
	
	for(int i=0;i<TESTSIZE;++i){
	img=imread(argv[1],1);
	gettimeofday(&start, 0);
	k=Compare::compare(img,hists,feat);
	gettimeofday(&end, 0);
	times  = end.tv_sec - start.tv_sec;
	timeus = end.tv_usec - start.tv_usec;
	if(timeus<0)
	{
	times--;
	timeus += 1000000;
	}
	v1s+=times;
	v1us+=timeus;
	
	times=0;
	timeus=0;
	
	gettimeofday(&start, 0);
	num=Compare::compareHist(img,hists);
	//std::cout<<"vec "<<num.size()<<std::endl;
	feat2 = vector<Mat>(); 
	for(unsigned int j = 0; j < num.size(); ++j){
		feat2.push_back(feat[num[j]]);
	}
	m=Compare::matchFeatures(img,feat2,num);
	gettimeofday(&end, 0);
	times  = end.tv_sec - start.tv_sec;
	timeus = end.tv_usec - start.tv_usec;
	if(timeus<0)
	{
	  times--;
	  timeus += 1000000;
	}
	v2s+=times;
	v2us+=timeus;
		
	times=0;
	timeus=0;
	//printf("%d || %d \n ", k, m);
	}
	
	v1s/=TESTSIZE;
	v1us/=TESTSIZE;
	v2s/=TESTSIZE;
	v2us/=TESTSIZE;
	
	printf("method 1 takes %f:%f\n",v1s,v1us);
	printf("method 2 takes %f:%f\n",v2s,v2us);
	
	return 0;
	
}

void createTestBenchValues(Mat* imgs, int n,int size,vector<Mat> &hists, vector<Mat> &feat){
	vector<KeyPoint> key;
	Mat srcHist[n];
	Mat features[n];
	Histogram hist; 
	for(int i=0; i< n; ++i){
		hist = Histogram();
		hist.calculate(imgs[i]);
		srcHist[i]=hist.getHistogram();
	    features[i]= FeatureMatching::detectAndDiscribeFeatures(imgs[i], key);
	}
	
	for(int j=0;j<size;++j){
		hists.push_back(srcHist[j%n]);
		feat.push_back(features[j%n]);
	}
}
