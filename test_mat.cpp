#include <cv.h>
#include <highgui.h>

#include <stdlib.h>
#include <stdio.h>

#include "cvrect.h"

using namespace cv;

TSafeVector lines, merged, rectangles;

TPoint p1,p2,p3,p4;

int main(int argc, char* argv[])
{
		
		VideoCapture cap(0); // open the default camera
		if(!cap.isOpened())  // check if we succeeded
				return -1;
				
				
		char* filename = argv[1];
		//printf("%s\n",filename);
		
		Mat gray;
		namedWindow("capture",1);
		
		//for(;;)
		//{
				Mat frame;
				//cap >> frame; // get a new frame from camera
				
				printf("Here\n");
				frame = imread("rect.png",1);
				
				cvtColor(frame, gray, CV_BGR2GRAY);
				
				LinesFromMat(&gray, &lines);
				DrawLines(&frame,&lines,CV_RGB(0,255,0),4);
				mergeLines(&lines,&merged,30,100,100);

				calcRectangles(&merged,&rectangles);
				DrawRect(&frame,&rectangles,CV_RGB(255,0,0),1);
				
				getCorners(((TRectangle*)rectangles.get(0)), &p1, &p2, &p3, &p4);
				
				line(frame, Point(p1.getx(),p1.gety()),
							Point(p2.getx(),p2.gety()),
							CV_RGB(0,0,255), //color of the lines
							2,
							8, 0 ); 
							
				line(frame, Point(p2.getx(),p2.gety()),
							Point(p3.getx(),p3.gety()),
							CV_RGB(0,255,255), //color of the lines
							2,
							8, 0 ); 
							
				line(frame, Point(p3.getx(),p3.gety()),
							Point(p4.getx(),p4.gety()),
							CV_RGB(255,0,255), //color of the lines
							2,
							8, 0 ); 
							
				line(frame, Point(p4.getx(),p4.gety()),
							Point(p1.getx(),p1.gety()),
							CV_RGB(255,255,255), //color of the lines
							2,
							8, 0 ); 
				
				printf("%d\n",rectangles.length());
				
				imshow("capture", frame);
				
				lines.deleteall();
				merged.deleteall();
				rectangles.deleteall();
				
				waitKey();
				
				//if(waitKey(30) >= 0) 
				//		break;
		//}
		// the camera will be deinitialized automatically in VideoCapture destructor
		return 0;
}
