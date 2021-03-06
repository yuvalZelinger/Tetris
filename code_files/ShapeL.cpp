#include "Direction.h"
#include "Shape.h"
#include "ShapeL.h"
#include "Point.h"

//constructor
ShapeL::ShapeL(const Point& head, char c1) : Shape(head, c1), shapeFace(UP) {
	buildShapeL();
}

/*The function gets the gameArr and checks if she can rotate the shape,
if so she rotates*/
void ShapeL::rotate(char arr[10][15])
{
	Point tempBody[4], *ShapeBody;
	ShapeBody = getBody();
	bool canRotate = true;

	switch (shapeFace)
	{
	case UP:
		tempBody[2] = ShapeBody[2];
		tempBody[1] = tempBody[2].up();
		tempBody[0] = tempBody[1].right();
		tempBody[3] = tempBody[2].down();

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
		tempBody[2] = ShapeBody[2];
		tempBody[1] = tempBody[2].right();
		tempBody[0] = tempBody[1].down();
		tempBody[3] = tempBody[2].left();

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
		tempBody[2] = ShapeBody[2];
		tempBody[1] = tempBody[2].down();
		tempBody[0] = tempBody[1].left();
		tempBody[3] = tempBody[2].up();

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
		tempBody[2] = ShapeBody[2];
		tempBody[1] = tempBody[2].left();
		tempBody[0] = tempBody[1].up();
		tempBody[3] = tempBody[2].right();

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
void ShapeL::backToStart()
{
	ShapeLBackToStart();
}