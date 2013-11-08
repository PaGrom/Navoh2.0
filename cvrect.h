#ifndef  _cvrect_h
#define _cvrect_h

#include <cv.h>
#include "findrect.h"
#include "tsafevector.h"

#include "lsd.h"

using namespace cv;

void LinesFromMat(Mat *image, TSafeVector *lines); //image must be in grayscale!
void DrawRect(Mat *image, TSafeVector *rectangles, CvScalar  color, int thickness); 
void DrawLines(Mat *image, TSafeVector *lines, CvScalar color, int thickness);

#endif /* _cvrect_h */
