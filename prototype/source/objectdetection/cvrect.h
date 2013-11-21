#ifndef  _cvrect_h
#define _cvrect_h

#include <cv.h>
#include "findrect.h"
#include "objectlibs/tsafevector.h"
#include <math.h>

#include "lsd.h"

using namespace cv;

void LinesFromMat(Mat *image, vector<TLine*> *lines); //image must be in grayscale!
void DrawRect(Mat *image, TSafeVector *rectangles, CvScalar  color); 
void DrawLines(Mat *image, TSafeVector *lines, CvScalar color);

#endif /* _cvrect_h */
