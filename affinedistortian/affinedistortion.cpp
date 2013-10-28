#include "affinedistortion.h"

vector<int> intersect(TLine *line1, TLine *line2);
vector<Point2f> getShouldPoints();

Mat AffineDistortion::affineDist(Mat img, TRectangle rect){
  
  Size size(640,480);
  Mat dest(size,CV_8UC3);
    
  TLine *top    = rect.getLine(1);
  TLine *bottom = rect.getLine(2);
  TLine *left   = rect.getLine(3);
  TLine *right  = rect.getLine(4);
  
  getCorners(top,left,bottom,right);
  vector<Point2f> pointsShould,pointsAre;
  pointsAre=getCorners(top,left,bottom,right);
  pointsShould=getShouldPoints();
  Mat trans = getPerspectiveTransform(pointsShould,pointsAre);
  warpPerspective(img,dest,trans,size);
  return dest;
}

/**
 * calculates the corners of the rectangle in the Point2f format
 */
vector<Point2f> AffineDistortion::getCorners(TLine *top,TLine *left,TLine *bottom,TLine *right)
{
  
  int x1,x2,x3,x4;
  int y1,y2,y3,y4;
  vector<int> point;
  vector<Point2f> sortedCorners;
  point=intersect(bottom, right);
  if(point.size()==2)
  {
    x1=point[0];
    y1=point[1];
    sortedCorners.push_back(Point2f(x1,y1));
  }
  
  point=intersect(bottom, left);
  if(point.size()==2)
  {
    x2=point[0];
    y2=point[1];
    sortedCorners.push_back(Point2f(x2,y2));
  }
  
  point=intersect(top, right);
  if(point.size()==2)
  {
    x3=point[0];
    y3=point[1];
    sortedCorners.push_back(Point2f(x3,y3));
  }
  
  point=intersect(top, left);
  if(point.size()==2)
  {
    x4=point[0];
    y4=point[1];
    sortedCorners.push_back(Point2f(x4,y4));
  }
  
  

  return sortedCorners;
}



/**
 * computes the intersection of two lines
 */
vector<int> intersect(TLine *line1, TLine *line2){
  double a1=0, a2=0;
  double b1=0,b2=0;
  int x1,x2,y1,y2;
  vector<int> point;
  if((line1->getp1())->getx()==(line1->getp2())->getx())
  {
	x1=(line2->getp1())->getx();
	x2=(line2->getp2())->getx();
	y1=(line2->getp1())->gety();
	y2=(line2->getp2())->gety();
	a2=(y1-y2)/(x1-x2);
    b2=(y1-a2*x1);
    
    point.push_back((int)(a2*((line1->getp1())->getx())));
    point.push_back((line1->getp1())->getx());
  }
  else if((line2->getp1())->getx()==(line2->getp2())->getx())
  {
	x1=(line1->getp1())->getx();
	x2=(line1->getp2())->getx();
	y1=(line1->getp1())->gety();
	y2=(line1->getp2())->gety();
	a2=((double)(y1-y2))/((double)(x1-x2));
    b2=(y1-a2*x1);
    
    point.push_back((int) (a2*((line2->getp1())->getx())+b2));
    point.push_back((line2->getp1())->getx());
  }
  else
  {
    x1=(line1->getp1())->getx();
  	x2=(line1->getp2())->getx();
  	y1=(line1->getp1())->gety();
  	y2=(line1->getp2())->gety();
  	a1=((double)(y1-y2))/((double)(x1-x2));
    b1=(y1-a2*x1);
    
    x1=(line2->getp1())->getx();
   	x2=(line2->getp2())->getx();
   	y1=(line2->getp1())->gety();
   	y2=(line2->getp2())->gety();
  	a2=((double)(y1-y2))/((double)(x1-x2));
    b2=(y1-a2*x1);
    x1=(b2-b1)/(a1-a2);
    if(a1!=a2)
    {
    point.push_back((int)(a2*x1+b2));
    point.push_back(x1);
    }
  }
  
	return point;
}

vector<Point2f> getShouldPoints(){
	
  vector<Point2f> points;
  points.push_back(Point2f(640,0));
  points.push_back(Point2f(0,0));	
  points.push_back(Point2f(640,480));
  points.push_back(Point2f(0,480));
  return points;
}