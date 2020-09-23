#include "Direction.h"
#include "Shape.h"
#include "Line.h"
#include "Point.h"

//constructor
Line::Line(const Point& head, char c1) : Shape(head, c1), shapeFace(UP)  {
	buildLine();
}

/*The function gets the gameArr and checks if she can rotate the shape,
if so she rotates*/
void Line::rotate(char arr[10][15])
{
	Point tempBody[4], *lineBody;
	lineBody = getBody();


	bool canRotate = true;
	switch (shapeFace)
	{
	case UP:
		tempBody[0] = lineBody[1].left();
		tempBody[1] = lineBody[1];
		tempBody[2] = lineBody[1].right();
		tempBody[3] = tempBody[2].right();

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
		tempBody[0] = lineBody[1].up();
		tempBody[1] = lineBody[1];
		tempBody[2] = lineBody[1].down();
		tempBody[3] = tempBody[2].down();
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
void Line::backToStart()
{
	LineBackToStart();
}