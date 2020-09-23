#ifndef _SHAPE_H_
#define _SHAPE_H_

#include "Direction.h"
#include "Point.h"



class Shape {
	Point body[4];//array of points Will contain the location of the Shape
	char c;//How the Bomb looks

public:
	Shape(const Point& head, char c1);
	void buildSquare();
	void buildLine();
	void buildShapeL();
	void buildShapeT();
	void buildShapeZ();
	void setBodyAfterRotate(Point * newBody);
	void move(char keyPressed, char arr[10][15]);
	bool moveDown(char arr[10][15]);
	void draw();
	virtual void backToStart();
	void SquareBackToStart();
	void LineBackToStart();
	void ShapeLBackToStart();
	void ShapeTBackToStart();
	void ShapeZBackToStart();
	virtual void rotate(char arr[10][15]);
	char getC();
	Point * getBody();
};


#endif