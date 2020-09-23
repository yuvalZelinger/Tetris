#include "Direction.h"
#include "Shape.h"
#include "Square.h"

//constructor
Square::Square(const Point& head, char c1): Shape(head, c1){
	buildSquare();	
}

//Function resets shape position (returns it to top)
void Square::backToStart()
{
	SquareBackToStart();
}