#include "cvrect.h"

void LinesFromMat(Mat *image, TSafeVector *lines) //image must be in grayscale!
{
	
		double *output;
		//input for LSD call, that contains all of the pixels of the image
		double *input = (double *) malloc( image->cols * image->rows * sizeof(double) );
		int i=0;
	
		for(int y = 0; y < image->rows; y++)
				for(int x = 0; x < image->cols; x++)
				{
						input[i]=(double)image->data[image->step[0]*y + image->step[1]*x];
						i++;
				}
				
		int lcnt=0;
		
		//LSD call
		output = lsd(&lcnt,input,image->cols,image->rows);
		
		int k=0;
		
		for(i=0;i<lcnt;i++)
		{	
				double x1=output[7*i+0],x2=output[7*i+2],y1=output[7*i+1],y2=output[7*i+3];
				if(!(abs(x1-x2)+abs(y1-y2))<2*20)
				{
				lines->setat(new TLine(x1,y1,x2,y2),k);
				k++;
				}
		}
		
		free(input);
		free(output);
	
}

void DrawRect(Mat *image, TSafeVector *rectangles, CvScalar color)
{
		for(int i=0;i<rectangles->length();i++)
		{
				for(int j=1; j<5; j++)
						line(*image, Point(((TRectangle*)rectangles->get(i))->getLine(j)->getp1()->getx(),
												((TRectangle*)rectangles->get(i))->getLine(j)->getp1()->gety()), 
										Point(((TRectangle*)rectangles->get(i))->getLine(j)->getp2()->getx(),
												((TRectangle*)rectangles->get(i))->getLine(j)->getp2()->gety()), 
							color, //color of the lines
							4, //thickness
							8, 0 ); 
		}
}

void DrawLines(Mat *image, TSafeVector *lines, CvScalar color)
{
		for(int i=0;i<(lines->length());i++)
		{
				line(*image, Point(((TLine*)(lines->get(i)))->getp1()->getx(),((TLine*)(lines->get(i)))->getp1()->gety()), //starting point
								Point(((TLine*)(lines->get(i)))->getp2()->getx(),((TLine*)(lines->get(i)))->getp2()->gety()), //ending point
							color, //color of the lines
							2, //thickness
							8, 0 );
		}
}
