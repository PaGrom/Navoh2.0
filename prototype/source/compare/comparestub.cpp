#include "comparestub.h"

/**
 * Comparism in one step with preloaded features
 * @see compare.h
 */
int CompareStub::compare(Mat *img, vector<Mat> *hists, vector<Mat> *features,int& blackPixAdded){
  if(!hists->empty()&&!features->empty()&&!img->rows==0&&!img->cols==0){
	  return Compare::compare(img,hists,features,blackPixAdded);
  }
  else
    return -1;
}
/**
 * comparism of histograms returning a list of imagepositions which fullfill the criterion
 * 
 * @see compare.h
 */
vector<int> CompareStub::comparehist(Mat *img, vector<Mat> *hists)
{
  if(!hists->empty())
  return Compare::compareHist(img,hists);
  else
  return vector<int>();
}
/**
 * matching of feature points matches the featue points of the images returns the 
 * image number with the highest amount of good matches which has more matches than the threshold.
 * the image number is handed to the function by imagelist.
 * 
 * @see compare.h
 */
int CompareStub::matchFeaturePoints(Mat *img, vector<Mat> *featurePoints, vector<int> *imageList)
{
  if(!featurePoints->empty()&&!imageList->empty())
  return Compare::matchFeatures(img,featurePoints,imageList);
  else
  return -1;
}