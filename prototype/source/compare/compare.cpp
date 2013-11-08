#include "compare.h"
#include <cstdio>
/**
 * compares in one run all histograms and for possible matches also the features.
 */
int Compare::compare(Mat *img, vector<Mat> *histograms, vector<Mat> *features,int& blackPixAdded){
	
  Histogram hist;
  hist.calculate(img,blackPixAdded);

  vector<KeyPoint> key;
  Mat des= FeatureMatching::detectAndDiscribeFeatures(*img, key);
  vector<DMatch> matches;
  unsigned int j=0,k=0;
  for (unsigned int i=0; i<histograms->size(); ++i)
  {
	
    if(hist==Histogram((*histograms)[i]))
    {  
     //printf("hists are eq\n");
     matches=FeatureMatching::matchFeatures(des,(*features)[i]);
      if(matches.size()>k)
      {
        k=matches.size();
        j=i;
      }
    }
    
  }
  if(k>MINMATCHES)
  return j;
  else
  return -1;
  
  return -1;
}

/**
 * compares only histograms and returns a list with possible matches
 */
vector<int> Compare::compareHist(Mat *img, vector<Mat> *histograms){
  
  int x=0;
  Histogram hist;
  hist.calculate(img,x);
  vector<int> pict;
  for (unsigned int i=0; i<histograms->size(); ++i)
  {
    if(hist==Histogram((*histograms)[i]))
      pict.push_back(i);
    
  }
  return pict;
}


/**
 * compares the Featurepoints returns the position of the best matching picture
 */
int Compare::matchFeatures(Mat *img, vector<Mat> *features,vector<int> *pics){
  unsigned int most=0,place;
  vector<KeyPoint> key;
  Mat des= FeatureMatching::detectAndDiscribeFeatures(*img,key);
  vector<DMatch> matches;
  for(unsigned int i=0; i<features->size();++i){
    matches= FeatureMatching::matchFeatures(des,(*features)[i]);
    if(matches.size()>most){
      most=matches.size();
      place=i;
    }  
  }
  if(most<MINMATCHES)
    return -1;
  else
  return (*pics)[place];
	
  return -1; 
}


