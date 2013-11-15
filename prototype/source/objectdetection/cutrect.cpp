#include "cutrect.h"
#include <math.h>



void getMininalMaxXYCorner(TLine* ax, TLine* bx, TLine* cx, TLine* dx, int &x,int &y, int &a, int &b);

cv::Mat CutImage::getSubImage(TRectangle *rect, cv::Mat* img, int& blackPixadded){

  int x1,x2,y1,y2;


  getMininalMaxXYCorner(rect->getLine(1),  rect->getLine(2),  rect->getLine(3),  rect->getLine(4), x1,y1,x2,y2);
  
  cv::Mat imgnew = ((*img)(cv::Range(y1,y2),cv::Range(x1,x2)));
  
  return imgnew;

}

void getMininalMaxXYCorner(TLine* ax, TLine* bx, TLine* cx, TLine* dx, int &x,int &y, int &a, int &b){
  
  
  
  int x1,x2,y1,y2;
  
  int maxX=0,minX,maxY=0,minY;

  int minix,maxix,miniy,maxiy;
  
  x1=(ax->getp1())->getx();
  y1=(ax->getp1())->gety();
  x2=(ax->getp2())->getx();
  y2=(ax->getp2())->gety();
  
  minY=y1;
  minX=x1;
  
  minix=min(x1,x2);
  maxix=max(x1,x2);
  miniy=min(y1,y2);
  maxiy=max(y1,y2);
  
  maxX=max(maxix,maxX);
  minX=min(minix,minX);
  maxY=max(maxiy,maxY);
  minY=min(miniy,minY);
  
  
  x1=(bx->getp1())->getx();
  y1=(bx->getp1())->gety();
  x2=(bx->getp2())->getx();
  y2=(bx->getp2())->gety();
  
  minix=min(x1,x2);
  maxix=max(x1,x2);
  miniy=min(y1,y2);
  maxiy=max(y1,y2);
    
  maxX=max(maxix,maxX);
  minX=min(minix,minX);
  maxY=max(maxiy,maxY);
  minY=min(miniy,minY);
  
  x1=(cx->getp1())->getx();
  y1=(cx->getp1())->gety();
  x2=(cx->getp2())->getx();
  y2=(cx->getp2())->gety();
  
  minix=min(x1,x2);
  maxix=max(x1,x2);
  miniy=min(y1,y2);
  maxiy=max(y1,y2);
    
  maxX=max(maxix,maxX);
  minX=min(minix,minX);
  maxY=max(maxiy,maxY);
  minY=min(miniy,minY);
  
  x1=(dx->getp1())->getx();
  y1=(dx->getp1())->gety();
  x2=(dx->getp2())->getx();
  y2=(dx->getp2())->gety();
  
  minix=min(x1,x2);
  maxix=max(x1,x2);
  miniy=min(y1,y2);
  maxiy=max(y1,y2);
    
  maxX=max(maxix,maxX);
  minX=min(minix,minX);
  maxY=max(maxiy,maxY);
  minY=min(miniy,minY);
  
  x=minX;
  y=minY;
  a=maxX;
  b=maxY;
}

int CutImage::blackOutside(TRectangle *rect,cv::Mat *img){
  
  
  
}


