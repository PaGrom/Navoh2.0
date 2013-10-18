#include "matchingBenchmark.h"

void detektAndCompare2(IplImage *im, IplImage *im2){
	
	timeval start, end;
		SurfFeatureDetector detek(400);
		long int times=0, timeus=0;
			std::vector<KeyPoint> key1, key2;
			gettimeofday(&start,0);
			detek.detect(im, key1);
			detek.detect(im2, key2);
			gettimeofday(&end, 0);
			times  = end.tv_sec - start.tv_sec;
			timeus = end.tv_usec - start.tv_usec;
			if(timeus<0)
			{
			    times--;
				timeus += 1000000;
			}
			printf("detection  : %ld : %06ld \n", times, timeus);

		BriefDescriptorExtractor extrct(32);
		
		Mat des1,des2;
				gettimeofday(&start,0);
				extrct.compute(im, key1,des1);
				extrct.compute(im2, key2,des2);
				gettimeofday(&end, 0);
				times  = end.tv_sec - start.tv_sec;
				timeus = end.tv_usec - start.tv_usec;
				if(timeus<0)
				{
				times--;
				timeus += 1000000;
				}
				printf("extraction : %ld : %06ld \n", times, timeus);

				BFMatcher matcher(NORM_L2);
					
						std::vector<DMatch> matches;
						gettimeofday(&start,0);
						matcher.match(des1,des2,matches);
						gettimeofday(&end, 0);
						times  = end.tv_sec - start.tv_sec;
						timeus = end.tv_usec - start.tv_usec;
						if(timeus<0)
						{
						    times--;
							timeus += 1000000;
						}
						printf("matching   : %ld : %06ld \n", times, timeus);
		
	//print good matches
		
		double dist,maxdist=0, mindist=50;
		
		for(int i=0; i<des1.rows;++i){
			
			dist = matches[i].distance;
			if(dist<mindist)
			//mindist=dist;
			if (dist>maxdist)
			maxdist=dist;
			
		}
		int total=0;
		int distmax=0;
		std::vector<DMatch>goodmatch;
		for(int i=0; i<des1.rows;++i){
		if(matches[i].distance<=3*mindist)
		{
		distmax++;
		goodmatch.push_back(matches[i]);
		}
		total++;
		}
		std::cout<<"there are "<<distmax<<" good matches out of "<<total<<" matches with BRIEF"<<std::endl;
		Mat matImg;
		drawMatches(im,key1,im2,key2,goodmatch,matImg);
		//imshow("Brief",matImg);
		//waitKey(0);
		
		
		
		
}