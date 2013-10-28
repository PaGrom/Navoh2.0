#ifndef AFFINEDISTORTION
#define AFFINEDISTORTION

#include <cv.h>
#include "trectangle.h"
#include "tline.h"

using namespace cv;

class AffineDistortion {
private:
  static vector<Point2f> getCorners(TLine *top,TLine *left,TLine *bottom,TLine *right);
public:
  static Mat affineDist(Mat img,TRectangle rect);
};

#endif