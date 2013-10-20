#include <cv.h>
#include <highgui.h>

#include <stdlib.h>
#include <stdio.h>

#include "lsd.h"
#include "findrect.h"

int dorient=10;
int dmaxX=10;
int dmaxY=10;

void TrackbarChangeOrient(int value) {
	if(value>=0)
        dorient=value;
}

void TrackbarChangeDmaxX(int value) {
	if(value>=0)
        dmaxX=value;
}

void TrackbarChangeDmaxY(int value) {
	if(value>=0)
        dmaxY=value;
}

int main(int argc, char* argv[])
{
		IplImage* image=0, *dst=0;
		
		double *input;
		double *output;

		// name of the image is the first parameter
		char* filename = argv[1];
		
		//cvNamedWindow( "original image");
		
		int lcnt=0;
		
		int i=0;
		
		TSafeVector lines, merged;
		
		int k=0;
		
		cvNamedWindow("lines found by lsd");
		
		cvCreateTrackbar("Delta orient", "lines found by lsd", &dorient, 30, TrackbarChangeOrient);
		cvCreateTrackbar("dmaxX", "lines found by lsd", &dmaxX, 100, TrackbarChangeDmaxX);
		cvCreateTrackbar("dmaxY", "lines found by lsd", &dmaxY, 100, TrackbarChangeDmaxY);
		
		CvFont font;
		cvInitFont( &font, CV_FONT_HERSHEY_COMPLEX,0.7, 0.7, 0, 1, CV_AA);
		char str[30];
		
		while(1)
		{
				lines.deleteall();
				merged.deleteall();
		
				// loads image
				image = cvLoadImage(filename,1);
		
				//printf("[i] image: %s\n", filename);
		
				if(!image)
				{
					printf("Error: can`t load %s\n",filename);
					return -1;
				}
		
				//cvNamedWindow( "original image");
				//cvShowImage( "original image", image );
        
				//cvSobel(image, image, 1, 0, 1);
        
				//making the grayscale image 
				dst = cvCreateImage( cvGetSize(image), IPL_DEPTH_8U, 1 ); 
				cvCvtColor( image, dst, CV_BGR2GRAY );
		
				//cvSobel(dst, dst, 1, 0, 3);
		
				//cvNamedWindow( "sobel filter 3x3 and grayscale");
				//cvShowImage( "sobel filter 3x3 and grayscale", dst );
				//cvShowImage( "grayscale", dst );
		
				i=0;
		
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
		
				lcnt=0;
		
				//LSD call
				output = lsd(&lcnt,input,dst->width,dst->height);
		
				k=0;
		
				//just drawing lines found by LSD
				for(i=0;i<lcnt;i++)
				{
			
						cvLine(image, cvPoint((int)output[7*i],(int)output[7*i+1]), //starting point
								cvPoint((int)output[7*i+2], (int)output[7*i+3]), //ending point
							CV_RGB(0,255,0), //color of the lines
							(int)output[7*i+4], //thickness
							8, 0 ); 
						
						lines.setat(new TLine(output[7*i+0],output[7*i+1],output[7*i+2],output[7*i+3] //coordinates
											),k);
						k++;
				}
		
				mergeLines(&lines,&merged,dorient,dmaxX,dmaxY);
			
			
				for(i=0;i<(merged.length());i++)
				{
						cvLine(image, cvPoint(((TLine*)(merged.get(i)))->getp1()->getx(),((TLine*)(merged.get(i)))->getp1()->gety()), //starting point
								cvPoint(((TLine*)(merged.get(i)))->getp2()->getx(),((TLine*)(merged.get(i)))->getp2()->gety()), //ending point
							CV_RGB(255,0,0), //color of the lines
							2, //thickness
							8, 0 );
				}
				
				// используя шрифт выводим на картинку текст
				sprintf(str,"%d / %d\n",lines.length(),merged.length());
				cvPutText(image, str, cvPoint(50,50), &font, CV_RGB(255, 0, 0) );
				
				//printf("%d / %d\n",lines.length(),merged.length());
		
				cvShowImage( "lines found by lsd", image );
				
				char c = cvWaitKey(33);
				if (c == 27) { // нажата ESC
						break;
				}
				
		}
		
		//cvMoveWindow("sobel filter 3x3 and grayscale",100,100);
		//cvMoveWindow("grayscale",100,100);
		cvMoveWindow("lines found by lsd",300,200);

		cvReleaseImage(&image);
		cvReleaseImage(&dst);

		cvDestroyAllWindows();
		return 0;
}

