#include "featurematching.h"

Mat FeatureMatching::detectAndDiscribeFeatures(Mat &img, vector<KeyPoint> &key){

  Mat desc;
  vector<KeyPoint> feat;
  ORB orb(MAXFEATUREPOINTS,
          1.2f,
          8,
          31,
          0,
          2,
          ORB::HARRIS_SCORE,
          31);
  orb(img,Mat(),key,desc,false);
  return desc;
}

vector<DMatch> FeatureMatching::matchFeatures(Mat &img1,Mat &img2){

  vector<DMatch> matches;
  vector<DMatch>goodmatches;
  BFMatcher matcher(NORM_HAMMING);
  matcher.match(img1,img2,matches);
  for (int i=0;i<img1.rows && i<img2.rows; ++i)
  {
    if(matches[i].distance<=MAXDIST)
    goodmatches.push_back(matches[i]);
  }
  return goodmatches;
}