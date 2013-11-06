#include "cutrect.h"
#include <math.h>
void getcrossing(double& m1,double& m2,double& c1,double& c2, int &a, int& b);

void getMininalMaxXYCorner(TLine* ax, TLine* bx, TLine* cx, TLine* dx, int &x,int &y, int &a, int &b);

cv::Mat CutImage::getSubImage(TRectangle *rect, cv::Mat* img){

  int x1,x2,y1,y2;


  getMininalMaxXYCorner(rect->getLine(1),	rect->getLine(2),	rect->getLine(3),  rect->getLine(4), x1,y1,x2,y2);
  cv::Mat imgnew = ((*img)(cv::Range(x1,y1),cv::Range(x2,y2)));
  return imgnew;

}

void getMininalMaxXYCorner(TLine* ax, TLine* bx, TLine* cx, TLine* dx, int &x,int &y, int &a, int &b){
	
	double m1,m2,m3,m4;
	double b1,b2,b3,b4; 
	
	int a1,a2,a3,a4;
	int k1,k2,k3,k4;
	
	bool h1=false,h2=false,h3=false,h4=false;
	
	int x1,x2,y1,y2;
	
	x1=(ax->getp1())->getx();
	y1=(ax->getp1())->gety();
	x2=(ax->getp2())->getx();
	y2=(ax->getp2())->gety();
	
	m1=((double) (x1-x2));
	if(m1!=0){
	  m1=((double) (y1-y2)/m1);
      b1=y1-m1*x1;
	}
	else{
	  h1=true;
	  m1=x1;
	}
	
	x1=(bx->getp1())->getx();
	y1=(bx->getp1())->gety();
	x2=(bx->getp2())->getx();
	y2=(bx->getp2())->gety();
		
	m2=((double) (x1-x2));
	if(m2!=0){
	  m2=((double) (y1-y2)/m2);
	  b2=y1-m2*x1;
	}
	else{
	  h2=true;
	  m2=x1;
	}
	
	x1=(cx->getp1())->getx();
	y1=(cx->getp1())->gety();
	x2=(cx->getp2())->getx();
	y2=(cx->getp2())->gety();
	
	m3=((double) (x1-x2));
	if(m3!=0){
	  m3=((double) (y1-y2)/m3);
	  b3=y1-m3*x1;
	}
	else{
	  h3=true;
	  m3=x1;
	}
	
	
	x1=(dx->getp1())->getx();
	y1=(dx->getp1())->gety();
	x2=(dx->getp2())->getx();
	y2=(dx->getp2())->gety();
			
	m4=((double) (x1-x2));
	
	if(m4!=0){
	  m4=((double) (y1-y2)/m4);
	  b4=y1-m4*x1;
	} else
	{
	  h4=true;
	  m4=x1;
	  b4=0;
	}
	
	getcrossing(m1,m2,b1,b2,a1,k1);
	getcrossing(m2,m3,b2,b3,a2,k2);
	getcrossing(m3,m4,b3,b4,a3,k3);
	getcrossing(m4,m1,b4,b1,a4,k4);
	
	
	int help1,help2;
	
	help1=max(a1,a2);
	help2=max(a3,a4);
	
	a=max(help1,help2);
	
	help1=max(k1,k2);
	help2=max(k3,k4);
		
	b=max(help1,help2);
	
	help1=min(a1,a2);
	help2=min(a3,a4);
	
	x=min(help1,help2);
	
	help1=min(k1,k2);
	help2=min(k3,k4);
		
	y=min(help1,help2);
	
	
}

void getcrossing(double& m1,double& m2,double& c1,double& c2, int &a, int& b){
	double x= (c1-c2)/(m2-m1);
	double y= x*m1+c1;
	
	a=x;
	b=y;
	
	if((double)a<x)
	a+=1;
	if((double)b<y)
	b+=1;
}
