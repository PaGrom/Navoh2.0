#include <iostream> 

#include "findrect.h"

void getDXY(TLine *l, float *dx, float *dy, int *x1, int *x2, int *y1, int *y2)
{
	if(l->getp2()->getx() > l->getp1()->getx()) 
	{ 
		*x1 = l->getp1()->getx(); 
		*x2 = l->getp2()->getx(); 
		*y1 = l->getp1()->gety(); 
		*y2 = l->getp2()->gety(); 
	}
	else 
	{ 
		*x1 = l->getp2()->getx(); 
		*x2 = l->getp1()->getx(); 
		*y1 = l->getp2()->gety(); 
		*y2 = l->getp1()->gety(); 
	}
	*dx = x2-x1;
	*dy = y2-y1; 
}

int isCrossed(TLine &l1, TLine &l2)
{
	float k1,k2,b1,b2,xx1,yy1,dx1,dx2,dy1,dy2;
	int x11,x12,x21,x22,y11,y12,y21,y22;
	getDXY(&l1, &dx1, &dy1, &x11, &x12, &y11, &y12);
	getDXY(&l2, &dx2, &dy2, &x21, &x22, &y21, &y22);

	if((dx1==0) && (dx2==0))
		return 0; // äâå âåðòèêàëüíûå ëèíèè
	else{
		if(dx1==0) // ïåðâàÿ ëèíèÿ - âåðòèêàëüíàÿ
		{
			xx1 = x11;
			k2 = dy2/dx2;
			b2 = y21-k2*x21;
			yy1 = xx1*k2+b2;
		}
		else if(dx2==0) // âòîðàÿ ëèíèÿ - âåðòèêàëüíàÿ
		{
			xx1 = x21;
			k1 = dy1/dx1;
			b1 = y11-k1*x11;
			yy1 = xx1*k1+b1;
		}
		else
		{
			k1 = dy1/dx1;
			k2 = dy2/dx2;
			if(k1!=k2)
			{
				b1 = y11-k1*x11;
				b2 = y21-k2*x21;
				xx1 = (b2-b1)/(k1-k2);
				yy1 = xx1*k1+b1;
			}
			else 
				return 0; // ïàðàëëåëüíûå ëèíèè
		}
	}

	if( ((xx1 == x11) && (yy1 == y11)) || ((xx1 == x12) && (yy1 == y12)) || ((xx1 == x21) && (yy1 == y21)) || ((xx1 == x22) && (yy1 == y22)))
		return 0; // ïåðåñå÷åíèå íà ìåñòå ñîåäíèåíèÿ
	else
		if((xx1>=x11) && (xx1<=x12) && (xx1>=x21) && (xx1<=x22)) 
			return 1; 
		else 
			return 0;
}

int isParallel(TLine &l1, TLine &l2)
{
	float dx1 = (*l1.getp2()).getx()-(*l1.getp1()).getx();
	float dy1 = (*l1.getp2()).gety()-(*l1.getp1()).gety();
	float dx2 = (*l2.getp2()).getx()-(*l2.getp1()).getx();
	float dy2 = (*l2.getp2()).gety()-(*l2.getp1()).gety();
	
	if((dx1==0) || (dx2==0))
		if(dx1==dx2) 
			return 1; 
		else	
			return 0;
	else
	{
		float k1 = dy1/dx1;
		float k2 = dy2/dx2;
		if(k1==k2)
			return 1; 
		else 
			return 0;
	}
}

void findConLine(TSafeVector *all, int li, TPoint *p1, int *resl, int cnt, TSafeVector *res,int n, int cur_i, int maxl)
{
	if(n<maxl+1){
		for(int i=cur_i; i<(all->length()); i++)
		{
			if((i!=li) && ( (*(((TLine*)(all->get(i)))->getp1()) == *p1 ) || (*(((TLine*)(all->get(i)))->getp2()) == *p1)))
			{
				resl[cnt] = i;
				if(*(((TLine*)(all->get(i)))->getp1())==*p1)
					findConLine(all, i, ((TLine*)(all->get(i)))->getp2(), resl, cnt+1, res, n+1,cur_i,maxl);
				else
					findConLine(all, i, ((TLine*)(all->get(i)))->getp1(), resl, cnt+1, res, n+1,cur_i,maxl);
			}
		}
	}
	else{
		if((li==resl[0]) && (*(((TLine*)(all->get(resl[0])))->getp2())==*p1))
		{
			if(maxl==4)
			{
				if(	   !(	isCrossed(*(TLine*)(all->get(resl[0])), *(TLine*)(all->get(resl[2]))) || isCrossed(*(TLine*)(all->get(resl[1])), *(TLine*)(all->get(resl[3])))) 
					&& !(	isParallel(*(TLine*)(all->get(resl[0])), *(TLine*)(all->get(resl[1]))) || 
							isParallel(*(TLine*)(all->get(resl[1])), *(TLine*)(all->get(resl[2]))) || 
							isParallel(*(TLine*)(all->get(resl[2])), *(TLine*)(all->get(resl[3]))) || 
							isParallel(*(TLine*)(all->get(resl[3])), *(TLine*)(all->get(resl[0]))) ))
				{
					// íàéäåí ÷åòûðåõóãîëüíèê
					res->setat(new TRectangle(*(TLine*)(all->get(resl[0])),*(TLine*)(all->get(resl[1])),*(TLine*)(all->get(resl[2])),*(TLine*)(all->get(resl[3]))),res->length());
				}
			}
			else
			{
				if(	   !(isParallel(*(TLine*)(all->get(resl[0])), *(TLine*)(all->get(resl[1]))) || 
						isParallel(*(TLine*)(all->get(resl[1])), *(TLine*)(all->get(resl[2]))) || 
						isParallel(*(TLine*)(all->get(resl[2])), *(TLine*)(all->get(resl[0]))) ))
				{
					// íàéäåí òðåõóãîëüíèê
					//res->setat(new Triangle(*(TLine*)(all->get(resl[0])),*(TLine*)(all->get(resl[1])),*(TLine*)(all->get(resl[2]))),res->length());
				}
			}
		}
	}
}

void calcRectangles(TSafeVector *linesq, TSafeVector *recsq)
{
	for(int i=0; i<(linesq->length()); i++)
	{
		int resl[5];
		resl[0] = i;
		int rescnt = 1;
		findConLine(linesq, i, ((TLine*)(linesq->get(i)))->getp2(), resl, rescnt, recsq, 1, i,4);
	}
	
}

void showRectangles(TSafeVector *recsq)
{
	for(int i=0; i<(recsq->length()); i++)
	{
		printf("Rectangle %d: ",i+1);
		((TRectangle*)(recsq->get(i)))->show();
		printf("\n");
	}
}
