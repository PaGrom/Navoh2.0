#include "extractedpicture.h"

int main(){
	
	TRectangle rect(TLine(TPoint(100,100),TPoint(200,200)),
			TLine(TPoint(100,100),TPoint(100,400)),
			TLine(TPoint(100,400),TPoint(300,400)),
			TLine(TPoint(300,400),TPoint(200,200)));
	Mat img= cvLoadImage("res.ppm");
	
	ExtractedPicture pic(img,rect);
	
	imshow("pic", pic.getImage());
}