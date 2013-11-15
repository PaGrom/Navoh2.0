#include "objectdetectionstub.h"
#include <cstdio>
  //test function to use

vector<KeyPoint> ObjectDetectionStub::key;
Mat ObjectDetectionStub::desc1;
int ObjectDetectionStub::detectRect=0;
int ObjectDetectionStub::showWhat=0;
bool ObjectDetectionStub::checkAngles = true;

int ObjectDetectionStub::findRectangles(Mat* img,vector<TRectangle> *rect){

  int i;
  
  
  Mat grey;
  cvtColor(*img, grey, CV_BGR2GRAY);
   
  TSafeVector lines, rectangles,merged;
  LinesFromMat(&grey,&lines);
   //mergeLines(&lines,&merged, 5, 10,10);
  calcRectangles(&lines,&rectangles);
  //DrawRect(img,&rectangles,CV_RGB(0,255,0));
   //printf("%d \n", rectangles.length());
  
  if(ObjectDetectionStub::showWhat>2)
    ObjectDetectionStub::show(img,lines,0,0,255);
  if(i<ObjectDetectionStub::detectRect)
  {
    i=ObjectDetectionStub::tuning(img,rect,lines);
  }
  else{
   desc1= FeatureMatching::detectAndDiscribeFeatures(*img,key,10);
   for(i=0; i<rectangles.length();++i){
        
        (*rect)[i] = *((TRectangle*) rectangles.get(i));
        //rect->push_back(*((TRectangle*) rectangles.get(i)));
        if(ObjectDetectionStub::showWhat>1)
          ObjectDetectionStub::show(img,((TRectangle*) rectangles.get(i)),0,255,0);
        
     }
  }
  detectRect=i;
  return i;
}


  //modify to use your code
   Mat ObjectDetectionStub::getSubImageForRectangle(Mat *img,TRectangle* rect, int &blackPixAdded){
     Mat subimg=CutImage::getSubImage(rect,img,blackPixAdded);
    return subimg;
  }
   
   void ObjectDetectionStub::show(Mat* img, TRectangle* rect, int red, int green , int blue){
     
     for(int j=1; j<5; j++){
       line(*img, Point(rect->getLine(j)->getp1()->getx(),
                        rect->getLine(j)->getp1()->gety()), 
                  Point(rect->getLine(j)->getp2()->getx(),
                        rect->getLine(j)->getp2()->gety()), 
                  CV_RGB(red,green,blue), //color of the lines
                  4, //thickness
                  8, 0 );
     }
     
   }
   
void ObjectDetectionStub::show(Mat* img,TSafeVector &lines,int red, int green, int blue){
  for(int i=0; i< lines.length(); ++i){
    TLine* tline=(TLine*) lines.get(i);
    line(*img,Point((tline->getp1())->getx(),(tline->getp1())->gety()),
          Point((tline->getp2())->getx(),(tline->getp2())->gety()),
          CV_RGB(red,green,blue),
          4,
          8,0);
    
  }
}
   
int ObjectDetectionStub::tuning(Mat* img, vector<TRectangle> *rect, TSafeVector &lines){
  
  int i;
  
  double avgdist1=0, avgdist2=0;
  
  TSafeVector rectangles;
  vector<KeyPoint> key2;
  
  Mat desc2= FeatureMatching::detectAndDiscribeFeatures(*img,key2,10);
  vector<DMatch> matches= FeatureMatching::matchFeatures(desc2,desc1);
  
  if(distanceKeypoints(key,key2,matches,avgdist1,avgdist2)<MAXDISTKEYPOINTS){
    
    ObjectDetectionStub::checkAngles = false;
    double resolution= avgdist2/avgdist1;
    
    calcRectangles(&lines,&rectangles);
    
    for(i=0; i<rectangles.length();++i){
         
         (*rect)[i] = *((TRectangle*) rectangles.get(i));
    
    }
    
    ObjectDetectionStub::checkAngles =true;
  }
  
  key=key2;
  desc1=desc2;
  
  return i;

}

int ObjectDetectionStub::distanceKeypoints(vector<KeyPoint> x, vector<KeyPoint> y,vector<DMatch> &matches,double &avgdist1, double &avgdist2){
  
  double oldMidX=0,oldMidY=0,NewMidX=0,NewMidY=0;
  
  double i, help;
  
  for(i=0; i<matches.size(); ++i){
        
    oldMidX+=(x[matches[i].queryIdx].pt).x;
    oldMidY+=(x[matches[i].queryIdx].pt).y;
      
    NewMidX+=(y[matches[i].trainIdx].pt).x;
    NewMidY+=(y[matches[i].trainIdx].pt).y;
    
    
  }
  oldMidX/=i;
  oldMidY/=i;
  
  NewMidX/=i;
  NewMidY/=i;
  
  for(i=0; i<matches.size(); ++i){
          
    help =(((x[matches[i].queryIdx].pt).x)-oldMidX)*(((x[matches[i].queryIdx].pt).x)-oldMidX); 
    help+=(((x[matches[i].queryIdx].pt).y) -oldMidY)*(((x[matches[i].queryIdx].pt).y) -oldMidY);
    help =sqrt(help);
    
    avgdist1+=help;
    
    help =(((x[matches[i].trainIdx].pt).x)-NewMidX)*(((x[matches[i].trainIdx].pt).x)-NewMidX); 
    help+=(((x[matches[i].trainIdx].pt).y) -NewMidY)*(((x[matches[i].trainIdx].pt).y) -NewMidY);
    help =sqrt(help);
        
    avgdist2+=help;
    
      
      
  }
  
  return (sqrt((NewMidX-oldMidX)*(NewMidX-oldMidX)+(NewMidY-oldMidY)*(NewMidY-oldMidY)));
}