#include "extractedpicture.h"


IplImage* ExtractedPicture::cutImage(IplImage* img, TRectangle rect){
	int k=0;
	int sx[4],ex[4],sy[4],ey[4];
	int a[4]; b[4];
	bool insideHorizotaly =false;
	bool insideVerticly =false;
	bool inside=false;
	
	Mat image(img);
	
	sx[0]=((rect.getline(1))->getp1())->getx();
	sy[0]=((rect.getline(1))->getp1())->gety();
	sx[1]=((rect.getline(2))->getp1())->getx();
	sy[1]=((rect.getline(2))->getp1())->gety();
	sx[2]=((rect.getline(3))->getp1())->getx();
	sy[2]=((rect.getline(3))->getp1())->gety();
	sx[3]=((rect.getline(4))->getp1())->getx();
	sy[3]=((rect.getline(4))->getp1())->gety();
	
	ex[0]=((rect.getline(1))->getp2())->getx();
	ey[0]=((rect.getline(1))->getp2())->gety();
	ex[1]=((rect.getline(2))->getp2())->getx();
	ey[1]=((rect.getline(2))->getp2())->gety();
	ex[2]=((rect.getline(3))->getp2())->getx();
	ey[2]=((rect.getline(3))->getp2())->gety();
	ex[3]=((rect.getline(4))->getp2())->getx();
	ey[3]=((rect.getline(4))->getp2())->gety();
	
	int maxPixX=0,minPixX=-1,maxPixY=0,minPixy=-1;
	
	for(int i=0;i<4; ++i){
		if(minPixX<0)
		minPixX=ex[i];
		if(minPixY<0)
		minPixY=ey[i];
		
		if(maxPixX<ex[i])
		maxPixX=ex[i];
		if(maxPixX<sx[i])
		maxPixX=sx[i];
		if(minPixX>ex[i])
		minPixX=ex[i];
		if(minPixX>sx[i])
		minPixX=sx[i];
		
		if(maxPixY<ey[i])
		maxPixY=ey[i];
		if(maxPixY<sy[i])
		maxPixY=sy[i];
		if(minPixY>ey[i])
		minPixY=ey[i];
		if(minPixY>sy[i])
		minPixY=sy[i];		
		
		
	}
	
	
	
	Mat cuttedImage;
	cuttedImage=Mat::zeros(Size(cols, rows), CV_8UC3);
	
	for(int i=minPixX;i<maxPixX+1;++i){
		for(intj=minPixY; j<maxPixY+1;++j){
			insideHorizotaly= a[0]*i+b[0]<=j && j>= a[1]*i+b[1];
			insideVerticly = a[2]*i+b[2]>=j && j<=a[3]*i+b[3];
			inside = insideHorizontaly&&insideVerticly;
			
			if(inside)
			cuttedImage[i][j]=Image[i][j];
		
		}
	}
	
	
	
	numberOfBlacksadded=k;
	return cuttedImage;
}

ExtractedPicture::ExtractedPicture(IplImage* image, TRectangle rectangle){
	rect=rectangle;
	img=cutImage(image,rectangle);
}

IplImage* ExtractedPicture::getImage(){

  return img;
	
}

int ExtractedPicture::getNumber(){

  return numberOfBlacksadded;
	
}