#ifndef line_h
#define line_h

#include "gobject.h"
#include "tpoint.h"

class TLine: public GObject
{
	TPoint p1;
	TPoint p2;
protected:
	float degree;
	float width;
public:
	void setp1(int ix, int iy);
	void setp2(int ix, int iy);
	TPoint * getp1();
	TPoint * getp2();
	TLine(void);
	TLine(int ix1, int iy1, int ix2, int iy2);
	TLine(int ix1, int iy1, int ix2, int iy2, float new_degree, float new_width);
	virtual ~TLine(void);
	void show();
	void shift(int dx,int dy);
	float get_degree();
	float get_width();
	void set_degree(float value);
	void set_width(float value);

	friend bool operator==(const TLine& left, const TLine& right);
};

#endif
