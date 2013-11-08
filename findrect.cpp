#include <iostream> 

#include "findrect.h"

const float PI = 3.141592653589;

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

void mergeLines(TSafeVector *original, TSafeVector *merged, double dorient, double dmaxX, double dmaxY)
{
	
		double xG, yG; //coordinates of the centroid - (xG , yG )
		int ax, ay, bx, by, cx, cy, dx, dy; //coordinates of endpoints
		double li, lj; //lengths of lines
		double oi, oj; //orientations of lines
		double oc; //orientation of centroid
		
		double axG, ayG, bxG, byG, cxG, cyG, dxG, dyG; //coordinates of the endpoints a , b, c and d in the frame (XG , YG )
		
		double lr; //length of merged line;
		
		double m1x, m1y, m2x, m2y; //endpoints of merged line
	
		double x, y;
		
		double ac, bd, ad, bc;
		
		TSafeVector temp;
	
		for(int i=0; i<(original->length()); i++)
		{
				temp.setat(original->get(i),i);
		}

		int count=0;
				
		for(int i=0; i<(temp.length()); i++)
		{
				
			if(temp.get(i)!=NULL)
			{
				
				ax=((TLine*)(temp.get(i)))->getp1()->getx();
				ay=((TLine*)(temp.get(i)))->getp1()->gety();
		
				bx=((TLine*)(temp.get(i)))->getp2()->getx();
				by=((TLine*)(temp.get(i)))->getp2()->gety();
				
				oi=((TLine*)(temp.get(i)))->get_angle();
				
				li=((TLine*)(temp.get(i)))->get_length();
				
				TLine * candidate = new TLine(ax,ay,bx,by);
				
				lr=candidate->get_length();
				
				for(int j=0; j<temp.length(); j++)
				{
						
						ax=candidate->getp1()->getx();
						ay=candidate->getp1()->gety();
						
						bx=candidate->getp2()->getx();
						by=candidate->getp2()->gety();
						
						oi=candidate->get_angle();
						
						if((temp.get(j)!=NULL)&&(j!=i))
						//if(j!=i)
						{
						
								cx=((TLine*)(temp.get(j)))->getp1()->getx();
								cy=((TLine*)(temp.get(j)))->getp1()->gety();
		
								dx=((TLine*)(temp.get(j)))->getp2()->getx();
								dy=((TLine*)(temp.get(j)))->getp2()->gety();
								
								oj=((TLine*)(temp.get(j)))->get_angle();
								
								lj=((TLine*)(temp.get(j)))->get_length();
						
								//Check the maximum allowed directional difference (dorient) of the two segments
								if((abs(oi-oj)<dorient)||(abs(180-abs(oi)-abs(oj))<dorient))
								{
									
									if(abs(oi-oj)<90)
									{
											oc=(li*oi+lj*oj)/(li+lj);
											//printf("1 %.5f ",oc);
									}
									else
									{
											oc=(li*oi+lj*(oj-180*(oj/abs(oj))))/(li+lj);
											//printf("2 %.5f ",oc);
									}
									
									//Define a frame (XG , YG ) centered on the
									//centroid (xG , yG ) and having the XG axis
									//parallel to the direction θr of the merged line.

									xG=(li*(ax+bx)+lj*(cx+dx))/(2*(li+lj));
									yG=(li*(ay+by)+lj*(cy+dy))/(2*(li+lj));
									
									//Determine the coordinates of the endpoints a, b, c and d of both segments in the frame
									//(XG , YG ). The coordinate transformation is a
									//translation followed by a rotation:

									axG=(ay-yG)*sin(oc*PI/180)+(ax-xG)*cos(oc*PI/180);
									ayG=(ay-yG)*cos(oc*PI/180)-(ax-xG)*sin(oc*PI/180);
									
									bxG=(by-yG)*sin(oc*PI/180)+(bx-xG)*cos(oc*PI/180);
									byG=(by-yG)*cos(oc*PI/180)-(bx-xG)*sin(oc*PI/180);
									
									cxG=(cy-yG)*sin(oc*PI/180)+(cx-xG)*cos(oc*PI/180);
									cyG=(cy-yG)*cos(oc*PI/180)-(cx-xG)*sin(oc*PI/180);
									
									dxG=(dy-yG)*sin(oc*PI/180)+(dx-xG)*cos(oc*PI/180);
									dyG=(dy-yG)*cos(oc*PI/180)-(dx-xG)*sin(oc*PI/180);
									
									//The maximum distance on the YG axis, between the most distant endpoints
									//must fit in the distance dmaxY allowed for merging
									if((abs(ayG-cyG)<dmaxY)&&(abs(ayG-dyG)<dmaxY)&&(abs(byG-dyG)<dmaxY)&&(abs(byG-cyG)<dmaxY))
									{
									
											ac=abs(axG-cxG);
											ad=abs(axG-dxG);
									
											bd=abs(bxG-dxG);
											bc=abs(bxG-cxG);
									
											if((ac>=ad)&&(ac>=bd)&&(ac>=bc))
											{
													m1x=axG;
													m1y=ayG;
											
													m2x=cxG;
													m2y=cyG;
											}
											else
											{
													if((ad>=ac)&&(ad>=bd)&&(ad>=bc))
													{
															m1x=axG;
															m1y=ayG;
											
															m2x=dxG;
															m2y=dyG;
													}
													else
													{
															if((bd>=ac)&&(bd>=ad)&&(bd>=bc))
															{
																	m1x=bxG;
																	m1y=byG;
											
																	m2x=dxG;
																	m2y=dyG;
															}
															else
															{
																	if((bc>=ac)&&(bc>=ad)&&(bc>=bd))
																	{
																			m1x=bxG;
																			m1y=byG;
											
																			m2x=cxG;
																			m2y=cyG;
																	}
																	else
																	{
																			printf("Something is rotten in the state of Denmark...\n");
																	}
															}
													}
											}
											
											//The maximum distance on the XG axis, between the endpoints
											//must fit in the distance dmaxX allowed for merging
											if((abs(m1x-m2x)-(abs(axG-bxG)+abs(cxG-dxG)))<dmaxX)
											{
													//Return to the original (X,Y) frame, reverse previous rotation
													
													x=(0-yG)*sin(oc*PI/180)+(0-xG)*cos(oc*PI/180);
													y=(0-yG)*cos(oc*PI/180)-(0-xG)*sin(oc*PI/180);
									
													m1y=(0-y)*cos((-oc)*PI/180)-(m1x-x)*sin((-oc)*PI/180);
													m1x=(0-y)*sin((-oc)*PI/180)+(m1x-x)*cos((-oc)*PI/180);
									
													m2y=(0-y)*cos((-oc)*PI/180)-(m2x-x)*sin((-oc)*PI/180);
													m2x=(0-y)*sin((-oc)*PI/180)+(m2x-x)*cos((-oc)*PI/180);
									
													candidate->getp1()->setx(m1x);
													candidate->getp1()->sety(m1y);
						
													candidate->getp2()->setx(m2x);
													candidate->getp2()->sety(m2y);
									
													//printf("line %d совпадает с line %d\n",i,j);
													//printf("%.5f %.5f \n",xG,yG);
													//printf("%.5f %.5f %.5f %.5f \n",m1x,m1y,m2x,m2y);
									
													temp.setat(NULL,j);
													//temp.deleteat(j);
													
											}//dmaxX
											
									}//dmaxY
										
								}// dorient
								
						}//if NULL j!=i
								
				}//end of second cycle
				
				merged->setat(candidate,count++);
				
			}
		}
		temp.deleteall();
		
}

void getCorners(TRectangle* rectangle, TPoint* p1, TPoint* p2, TPoint* p3, TPoint* p4)
{
		double k1,k2,b1,b2, x, y;
		
		//p1
		k1=rectangle->getLine(1)->get_k();
		b1=rectangle->getLine(1)->get_b();
		
		k2=rectangle->getLine(2)->get_k();
		b2=rectangle->getLine(2)->get_b();
		
		if(k1!=k2)
		{
				x=(b2-b1)/(k1-k2);
				y=k1*x+b1;
				
				p1->setx((int)(x+0.5));
				p1->sety((int)(y+0.5));
				
		}
		
		//p2
		k1=rectangle->getLine(2)->get_k();
		b1=rectangle->getLine(2)->get_b();
		
		k2=rectangle->getLine(3)->get_k();
		b2=rectangle->getLine(3)->get_b();
		
		if(k1!=k2)
		{
				x=(b2-b1)/(k1-k2);
				y=k1*x+b1;
				
				p2->setx((int)(x+0.5));
				p2->sety((int)(y+0.5));
		}
		
		//p3
		k1=rectangle->getLine(3)->get_k();
		b1=rectangle->getLine(3)->get_b();
		
		k2=rectangle->getLine(4)->get_k();
		b2=rectangle->getLine(4)->get_b();
		
		if(k1!=k2)
		{
				x=(b2-b1)/(k1-k2);
				y=k1*x+b1;
				
				p3->setx((int)(x+0.5));
				p3->sety((int)(y+0.5));
		}
		
		//p4
		k1=rectangle->getLine(1)->get_k();
		b1=rectangle->getLine(1)->get_b();
		
		k2=rectangle->getLine(4)->get_k();
		b2=rectangle->getLine(4)->get_b();
		
		if(k1!=k2)
		{
				x=(b2-b1)/(k1-k2);
				y=k1*x+b1;
				
				p4->setx((int)(x+0.5));
				p4->sety((int)(y+0.5));
				
		}
		
		
}

int isKonvex(TRectangle *rectangle)
{
		double a1,a2,a3,a4;
		
		a1=abs(rectangle->getLine(1)->get_angle()-rectangle->getLine(2)->get_angle());
		a2=abs(rectangle->getLine(2)->get_angle()-rectangle->getLine(3)->get_angle());
		a3=abs(rectangle->getLine(3)->get_angle()-rectangle->getLine(4)->get_angle());
		a4=abs(rectangle->getLine(4)->get_angle()-rectangle->getLine(1)->get_angle());
		
		if((a1>=180)&&(a2>=180)&&(a3>=180)&&(a4>=180))
			return 1;
		else
			return 0;
}

