#include <cv.h>
#include <highgui.h>

#include <stdlib.h>
#include <stdio.h>

#include "cvrect.h"

using namespace cv;

TSafeVector lines, rectangles;

int main(int argc, char* argv[])
{
		VideoCapture cap(0); // open the default camera
		if(!cap.isOpened())  // check if we succeeded
				return -1;
		
		Mat gray;
		namedWindow("capture",1);
		for(;;)
		{
				Mat frame;
				cap >> frame; // get a new frame from camera
				cvtColor(frame, gray, CV_BGR2GRAY);
				
				LinesFromMat(&gray, &lines);
				DrawLines(&frame,&lines,CV_RGB(0,255,0));
				calcRectangles(&lines,&rectangles);
				DrawRect(&frame,&rectangles,CV_RGB(255,0,0));
				
				imshow("capture", frame);
				
				lines.deleteall();
				rectangles.deleteall();
		
				if(waitKey(30) >= 0) 
						break;
		}
		// the camera will be deinitialized automatically in VideoCapture destructor
		return 0;
}
