
#include "rectchecks.h"
/**
 * checks whether the lines of the rectangle can form a visible rectangle meaning that 
 * the angles of 3 sides are not to identicle
 */
bool RectChecks::checkAnglesOfRect(TRectangle *rect){

  bool para1=false, para2=false, para3=false,para4=false;	

  para1= (abs((rect->getLine(1))->get_angle())-abs((rect->getLine(2))->get_angle()) <10); 
  para1= para1 && (abs((rect->getLine(1))->get_angle())-abs((rect->getLine(3))->get_angle()) <10);
  para1= para1 && (abs((rect->getLine(2))->get_angle())-abs((rect->getLine(3))->get_angle()) <10);

  para2= (abs((rect->getLine(1))->get_angle())-abs((rect->getLine(2))->get_angle()) <10); 
  para2= para1 && (abs((rect->getLine(1))->get_angle())-abs((rect->getLine(4))->get_angle()) <10);
  para2= para1 && (abs((rect->getLine(2))->get_angle())-abs((rect->getLine(4))->get_angle()) <10);

  para3= (abs((rect->getLine(4))->get_angle())-abs((rect->getLine(2))->get_angle()) <10); 
  para3= para1 && (abs((rect->getLine(4))->get_angle())-abs((rect->getLine(3))->get_angle()) <10);
  para3= para1 && (abs((rect->getLine(2))->get_angle())-abs((rect->getLine(3))->get_angle()) <10);

  para4= (abs((rect->getLine(4))->get_angle())-abs((rect->getLine(1))->get_angle()) <10); 
  para4= para1 && (abs((rect->getLine(4))->get_angle())-abs((rect->getLine(3))->get_angle()) <10);
  para4= para1 && (abs((rect->getLine(1))->get_angle())-abs((rect->getLine(3))->get_angle()) <10);
  
  return (!((para1 || para2) || (para3 || para4)));
}