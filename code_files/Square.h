#ifndef _SQUARE_H_
#define _SQUARE_H_


#include "Point.h"
#include "Shape.h"



class Square :public Shape {
private:

public:
	Square(const Point& head, char c1);
	virtual void backToStart()override;

};

#endif
