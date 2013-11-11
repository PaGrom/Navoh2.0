#ifndef line_h
#define line_h

#include "gobject.h"
#include "tpoint.h"

class TLine: public GObject
{
	TPoint p1;
	TPoint p2;
public:
	void setp1(int ix, int iy);
	void setp2(int ix, int iy);
	TPoint * getp1();
	TPoint * getp2();
	TLine(void);
	TLine(int ix1, int iy1, int ix2, int iy2);
	virtual ~TLine(void);
	void show();
	void shift(int dx,int dy);
	double get_length(); 
	double get_angle();
	
	double get_k();
	double get_b();
	
	TPoint * get_cross(TLine *line);
	
	friend bool operator==(const TLine& left, const TLine& right);
};

#endif