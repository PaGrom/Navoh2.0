#include "matchingBenchmark.h"


int main(){
	timeval start, end;
	IplImage *img1, *img2;
	img1=cvLoadImage("newtest.JPG");
	img2=cvLoadImage("newtest2.JPG");

	double time1s=0, time2s=0, time1us=0,time2us=0;
	int k =5;
	for(int i=0;i<k;++i){
	gettimeofday(&start, 0);
	detektAndCompare(img1,img2);
	gettimeofday(&end, 0);
	time1s  += end.tv_sec - start.tv_sec;
	time1us += end.tv_usec - start.tv_usec;
	if(time1us<0)
	{
		time1s--;
		time1us += 1000000;
	}
	
	gettimeofday(&start, 0);
	detektAndCompare2(img1,img2);
	gettimeofday(&end, 0);
	time2s  += end.tv_sec - start.tv_sec;
	time2us += end.tv_usec - start.tv_usec;
	if(time2us<0)
		{
			time2s--;
			time2us += 1000000;
		}
	
	
	if(i>0){
	time1s /= 2;
	time2s /= 2;
	time1us /= 2;
	time2us /= 2;
	}
	}
	std::cout<<" averadge Time Surf = "<< time1s<<":" <<time1us<<std::endl;
	std::cout<<" averadge Time Brief = "<< time2s<<":" <<time2us<<std::endl;
	
	waitKey(0);
	
	
	
	
}