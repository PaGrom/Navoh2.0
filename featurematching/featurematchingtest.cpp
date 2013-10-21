#include "featurematching.h"
#include <cstdio>
int main (int arc, char** argv){

  Mat a= imread(argv[1],1);
  Mat b= imread(argv[2],1);
  
  Mat des1,des2;
  vector<KeyPoint> key1, key2;
  des1=FeatureMatching::detectAndDiscribeFeatures(a,key1);
  des2=FeatureMatching::detectAndDiscribeFeatures(b,key2);
  printf("We got %d features\n",des1.rows);
  vector<DMatch> matches;
  matches= FeatureMatching::matchFeatures(des1,des2);
  
  printf("We got %lu matches\n",matches.size());
  Mat matImg;
  drawMatches(a,key1,b,key2,matches,matImg);
  imshow("Surf",matImg);
  waitKey(0);
}