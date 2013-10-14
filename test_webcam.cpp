#include <cv.h>
#include <highgui.h>

#include <stdlib.h>
#include <stdio.h>

#include "lsd.h"
#include "findrect.h"

//
void TrackbarChangeDelta(int value) {
        change_delta(value);
}

int distance=10;

void TrackbarChangeDistance(int value) {
	if(value>=0)
        distance=value;
}

int main(int argc, char* argv[])
{
		// получаем любую подключённую камеру
		CvCapture* capture = cvCreateCameraCapture(CV_CAP_ANY); //cvCaptureFromCAM( 0 );
		//CvCapture* capture = cvCaptureFromCAM( 0 );
		assert( capture );

		//cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH, 640);//1280); 
		//cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT, 480);//960); 

		// узнаем ширину и высоту кадра
		double width = cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH);
		double height = cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT);
		printf("[i] %.0f x %.0f\n", width, height );

		IplImage* frame=0, *dst=0;

		cvNamedWindow("capture", CV_WINDOW_AUTOSIZE);
		cvMoveWindow("capture",100,100);

		printf("[i] press Enter for capture image and Esc for quit!\n\n");

		int counter=0;
		char filename[512];
		
		frame = cvQueryFrame( capture );
		dst = cvCreateImage( cvGetSize(frame), IPL_DEPTH_8U, 1 );
		
		double *input;
		double *output;
		
		//input for LSD call, that contains all of the pixels of the image
		input = (double *) malloc( dst->width * dst->height * sizeof(double) );
		
		int lcnt=0, i=0, k=0;
		
		TSafeVector lines, merged, rectangles;
		
		int current_delta=5;
		
		CvFont font;
		cvInitFont( &font, CV_FONT_HERSHEY_COMPLEX,0.7, 0.7, 0, 1, CV_AA);
		char str[30];

		while(true){
			// получаем кадр
			frame = cvQueryFrame( capture );
			
			if( !frame ) {
					break;
			}
			
			cvCreateTrackbar("Delta", "capture", &current_delta, 30, TrackbarChangeDelta);
			cvCreateTrackbar("Distance", "capture", &distance, 20, TrackbarChangeDistance);

			cvCvtColor( frame, dst, CV_BGR2GRAY );
			
			i=0;
			
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
			
			k = 0;
			
			lines.deleteall();
			
			//just drawing lines found by LSD
			
			for(i=0;i<lcnt;i++)
			{
					
					cvLine(frame, cvPoint((int)output[7*i],(int)output[7*i+1]), //starting point
								cvPoint((int)output[7*i+2], (int)output[7*i+3]), //ending point
							CV_RGB(0,255,0), //color of the lines
							(int)output[7*i+4], //width
							8, 0 ); 
					
					
					//printf("%.2f ",output[i]);
					
					lines.setat(new TLine(output[7*i+0],output[7*i+1],output[7*i+2],output[7*i+3], //coordinates
											output[7*i+4], //width
											output[7*i+5]*180 //degree
											),k);
					
					k++;
			}
			
			merged.deleteall();
			
			mergeLines(&lines,&merged,10);
			
			/*
			for(i=0;i<(merged.length());i++)
			{
				cvLine(frame, cvPoint(((TLine*)(merged.get(i)))->getp1()->getx(),((TLine*)(merged.get(i)))->getp1()->gety()), //starting point
								cvPoint(((TLine*)(merged.get(i)))->getp2()->getx(),((TLine*)(merged.get(i)))->getp2()->gety()), //ending point
							CV_RGB(0,255,0), //color of the lines
							2, //thickness
							8, 0 );
			}
			*/
			
			rectangles.deleteall();
			//calcRectangles(&lines, &rectangles);
			calcRectangles(&merged, &rectangles);
			
			//drawing rectangles
			
			for(i=0;i<rectangles.length();i++)
			{
				for(k=0;k<4;k++)
				cvLine(frame, cvPoint(((GObject*)((TRectangle*)rectangles.get(i))->getLine(k)->getp1())->getx(),
										((GObject*)((TRectangle*)rectangles.get(i))->getLine(k)->getp1())->gety()), //starting point
								cvPoint(((GObject*)((TRectangle*)rectangles.get(i))->getLine(k)->getp2())->getx(),
										((GObject*)((TRectangle*)rectangles.get(i))->getLine(k)->getp2())->gety()), //ending point
							CV_RGB(255,0,0), //color of the lines
							4, //thickness
							8, 0 ); 
			}
			
			
			//printf("Rect found: %d\n",rectangles.length());
			// используя шрифт выводим на картинку текст
			sprintf(str,"Rectangles found: %d",rectangles.length());
			cvPutText(frame, str, cvPoint(50,50), &font, CV_RGB(255, 0, 0) );

			// показываем
			cvShowImage("capture", frame);
			//cvShowImage("capture", dst);
        
			char c = cvWaitKey(33);
			if (c == 27) { // нажата ESC
					break;
			}
			else if(c == 13) { // Enter
					// сохраняем кадр в файл
					sprintf(filename, "Image%d.jpg", counter);
					printf("[i] capture... %s\n", filename);
					cvSaveImage(filename, frame);
					counter++;
			}
		}
		// освобождаем ресурсы
		cvReleaseCapture( &capture );
		cvDestroyWindow("capture");
		return 0;
}
