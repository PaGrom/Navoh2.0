#include "histogram.h"

int main(int argc, char** argv){
	
	Mat a= imread(argv[1],1);
	
	Histogram hist;
	
	hist.calculate(a);
	
	
	
}