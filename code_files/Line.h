#ifndef _LINE_H_
#define _LINE_H_


#include "Point.h"
#include "Shape.h"
#include "Direction.h"



class Line:public Shape {
private:
	Direction shapeFace;//The direction the shape is facing
public:
	Line(const Point& head, char c1);
	virtual void rotate(char arr[10][15])override;
	virtual void backToStart()override;

};

#endif