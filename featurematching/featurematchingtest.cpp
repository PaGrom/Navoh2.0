#include "featurematching.h"
#include <cstdio>
#include <sys/time.h>



int main (int arc, char** argv){
  
	
  double avg1=0, avg2=0;
  timeval start, end, starttot, endtot;
  Mat a= imread(argv[1],1);
  Mat b= imread(argv[2],1);
  Mat c= imread(argv[1],CV_LOAD_IMAGE_GRAYSCALE);
  Mat d= imread(argv[2],CV_LOAD_IMAGE_GRAYSCALE);
  Mat des1,des2,des3,des4;
  vector<KeyPoint> key1, key2,key3,key4;
  vector<DMatch> matches;
  
  int times=0, timeus=0;
  des1=FeatureMatching::detectAndDiscribeFeatures(a,key1);
  gettimeofday(&starttot, 0);
  for(int i=0;i<100;++i){
  
  gettimeofday(&start, 0);
  
  des2=FeatureMatching::detectAndDiscribeFeatures(b,key2);
  //printf("We got %d features\n",des1.rows);
  matches= FeatureMatching::matchFeatures(des1,des2);
  gettimeofday(&end, 0);
  times  = end.tv_sec - start.tv_sec;
  timeus = end.tv_usec - start.tv_usec;
  if(timeus<0)
  {
    times--;
  	timeus += 1000000;
  }
  printf("color %ld matches in : %d : %06d sec\n",matches.size(), times, timeus);
  avg1+=timeus;
  if(i>0)
  avg1/=2;
  /*
  gettimeofday(&start, 0);
  des3=FeatureMatching::detectAndDiscribeFeatures(c,key3);
  des4=FeatureMatching::detectAndDiscribeFeatures(d,key4);
  //printf("We got %d features\n",des1.rows);
  matches= FeatureMatching::matchFeatures(des3,des4);
  gettimeofday(&end, 0);
  times  = end.tv_sec - start.tv_sec;
  timeus = end.tv_usec - start.tv_usec;
  if(timeus<0)
  {
    times--;
   	timeus += 1000000;
   	
  }
  avg2+=timeus;
  if(i>0)
  avg2/=2;
  printf("grey %ld matches in : %d : %06d sec\n",matches.size(), times, timeus);
  */
  }
  gettimeofday(&endtot, 0);
  printf("100 images took : %ld sec\n", endtot.tv_sec-starttot.tv_sec);
  //printf("We got %lu matches\n",matches.size());
  Mat matImg;
  //drawMatches(a,key1,b,key2,matches,matImg);
  //imshow("Surf",matImg);
  //waitKey(0);
  printf("color:= %f :: grey:= %f\n",avg1,avg2);
  
  
}