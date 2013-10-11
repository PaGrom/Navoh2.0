#include <cv.h>
#include <highgui.h>

#include <stdlib.h>
#include <stdio.h>

#include "lsd.h"

int main(int argc, char* argv[])
{
		IplImage* image=0, *dst=0;
		
		double *input;
		double *output;

		// name of the image is the first parameter
		char* filename = argv[1];
		// loads image
		image = cvLoadImage(filename,1);
		
		printf("[i] image: %s\n", filename);
		
		if(!image)
		{
			printf("Error: can`t load %s\n",filename);
			return -1;
		}
		
		cvNamedWindow( "original image");
		cvShowImage( "original image", image );
        
		//cvSobel(image, image, 1, 0, 1);
        
        //making the grayscale image 
		dst = cvCreateImage( cvGetSize(image), IPL_DEPTH_8U, 1 ); 
		cvCvtColor( image, dst, CV_BGR2GRAY );
		
		//cvSobel(dst, dst, 1, 0, 3);
		
		//cvNamedWindow( "sobel filter 3x3 and grayscale");
		//cvShowImage( "sobel filter 3x3 and grayscale", dst );
		cvShowImage( "grayscale", dst );
		
		int i=0;
		
		//input for LSD call, that contains all of the pixels of the image
		input = (double *) malloc( dst->width * dst->height * sizeof(double) );
		
		//moving around all of the pixels
		for( int y=0; y<dst->height; y++ ) {
				uchar* ptr = (uchar*) (dst->imageData + y * dst->widthStep);
				for( int x=0; x<dst->width; x++ ) {
						//printf("%u ",ptr[x]);
						input[i]=(double)ptr[x];
						//printf("%.2f ",input[i]);
						i++;
				}
				//printf("\n");
		}
		
		int lcnt=0;
		
		//LSD call
		output = lsd(&lcnt,input,dst->width,dst->height);
		
		//just drawing lines found by LSD
		for(i=0;i<lcnt;i++)
		{
			cvLine(image, cvPoint((int)output[7*i],(int)output[7*i+1]), //starting point
							cvPoint((int)output[7*i+2], (int)output[7*i+3]), //ending point
						CV_RGB(0,255,0), //color of the lines
						(int)output[7*i+4], //thickness
						8, 0 ); 
			//printf("%.2f ",output[i]);
		}
		
		cvNamedWindow( "lines found by lsd");
		cvShowImage( "lines found by lsd", image );
		
		//cvMoveWindow("sobel filter 3x3 and grayscale",100,100);
		cvMoveWindow("grayscale",100,100);
		cvMoveWindow("lines found by lsd",300,200);

		//waits for pressing any button
		cvWaitKey(0);

		cvReleaseImage(&image);
		cvReleaseImage(&dst);

		cvDestroyAllWindows();
		return 0;
}
