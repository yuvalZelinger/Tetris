#include "Direction.h"
#include "Shape.h"
#include "ShapeT.h"
#include "Point.h"

//constructor
ShapeT::ShapeT(const Point& head, char c1) : Shape(head, c1), shapeFace(UP) {
	buildShapeT();
}


/*The function gets the gameArr and checks if she can rotate the shape,
if so she rotates*/
void ShapeT::rotate(char arr[10][15])
{
	Point tempBody[4], *ShapeBody;
	ShapeBody = getBody();
	bool canRotate = true;


	switch (shapeFace)
	{
	case UP:
		tempBody[1] = ShapeBody[1];
		tempBody[0] = tempBody[1].right();
		tempBody[2] = tempBody[1].up();
		tempBody[3] = tempBody[1].down();

		for (int i = 0; i < 4; i++)
		{
			if (!tempBody[i].checkRotate(arr))
				canRotate = false;
		}
		if (canRotate) {
			shapeFace = RIGHT;
			setBodyAfterRotate(tempBody);
		}
		break;

	case RIGHT:
		tempBody[1] = ShapeBody[1];
		tempBody[0] = tempBody[1].down();
		tempBody[2] = tempBody[1].right();
		tempBody[3] = tempBody[1].left();

		for (int i = 0; i < 4; i++)
		{
			if (!tempBody[i].checkRotate(arr))
				canRotate = false;
		}
		if (canRotate) {
			shapeFace = DOWN;
			setBodyAfterRotate(tempBody);
		}
		break;
	case DOWN:
		tempBody[1] = ShapeBody[1];
		tempBody[0] = tempBody[1].left();
		tempBody[2] = tempBody[1].down();
		tempBody[3] = tempBody[1].up();

		for (int i = 0; i < 4; i++)
		{
			if (!tempBody[i].checkRotate(arr))
				canRotate = false;
		}
		if (canRotate) {
			shapeFace = LEFT;
			setBodyAfterRotate(tempBody);
		}
		break;
	case LEFT:
		tempBody[1] = ShapeBody[1];
		tempBody[2] = tempBody[1].up();
		tempBody[0] = tempBody[1].left();
		tempBody[3] = tempBody[1].right();

		for (int i = 0; i < 4; i++)
		{
			if (!tempBody[i].checkRotate(arr))
				canRotate = false;
		}
		if (canRotate) {
			shapeFace = UP;
			setBodyAfterRotate(tempBody);
		}
		break;
	}
}

//Function resets shape position (returns it to top)
void ShapeT::backToStart()
{
	ShapeTBackToStart();
}