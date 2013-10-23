#include "histogram.h"

int main(int argc, char** argv){
	
	Mat a= imread(argv[1],1);
	
	Histogram hist,histo;
	
	hist.calculate(a);
	Mat b= imread(argv[2],1);
	histo.calculate(b);
	if(hist==histo){
		printf("yes");
		
		
	}
	
	
	
	
}