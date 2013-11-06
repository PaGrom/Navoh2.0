#ifndef  _findrect_h
#define _findrect_h

#include <math.h>

#include "objectlibs/tpoint.h"
#include "objectlibs/tline.h"
#include "objectlibs/trectangle.h"
#include "objectlibs/tsafevector.h"

void getDXY(TLine *l, float *dx, float *dy, int *x1, int *x2, int *y1, int *y2);
int isCrossed(TLine &l1, TLine &l2);
int isParallel(TLine &l1, TLine &l2);
void findConLine(TSafeVector *all, int li, TPoint *p1, int *resl, int cnt, TSafeVector *res,int n, int cur_i, int maxl);
void calcRectangles(TSafeVector *linesq, TSafeVector *recsq);
void showRectangles(TSafeVector *recsq);

void mergeLines(TSafeVector *original, TSafeVector *merged, double dorient, double dmaxX, double dmaxY);

#endif /* _findrect_h */

