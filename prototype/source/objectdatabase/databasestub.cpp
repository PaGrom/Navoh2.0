#include "databasestub.h" 
#include "../compare/histogramcompare/histogram.h"
#include "../compare/featurematching/featurematching.h"

void stubload(vector<Mat>& histograms,vector<Mat>& featurepoints);


DatabaseStub::DatabaseStub(){
   string folder="testdatabase";
   std::cout<<"line :"<<__LINE__<<std::endl;
   data=Database(folder);
   std::cout<<"line :"<<__LINE__<<std::endl;
   data.loadHistograms(hists);
   std::cout<<"line :"<<__LINE__<<std::endl;
   data.loadFeatures(feats);
  }
//modify to use your code
   vector<Mat>* DatabaseStub::loadFeatures(){
    return &feats;
  }
  //modify to use your code
   vector<Mat>* DatabaseStub::loadHistograms(){
    return &hists;
  }
   
  void DatabaseStub::saveImage(string file,Mat img){
   
  if(!(img.rows==0 || img.cols==0))
      imwrite(file,img);
  }
  
  void stubload(vector<Mat>& histograms,vector<Mat>& featurepoints){
    Mat img= imread("testimg/00.ppm",1);
    int x=0;
    Histogram histogram;
    histogram.calculate(&img,x);
    histograms.push_back(histogram.getHistogram());
    vector<KeyPoint> key;
    featurepoints.push_back(FeatureMatching::detectAndDiscribeFeatures(img,key));
    
    
  }