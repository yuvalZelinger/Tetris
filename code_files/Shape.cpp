#include "Direction.h"
#include "Shape.h"

using namespace std;

//Constructor function for shape
Shape::Shape(const Point& head, char c1) {
	c = c1;
	body[0] = head;
}


/*The function gets a new body (after rotation), updates the existing body
and prints the body after rotation*/
void Shape::setBodyAfterRotate(Point * newBody)
{
	for (int i = 0; i < 4; i++)//מחיקת ריבוע לפני הזזה
		body[i].eraser();
	for (int i = 0; i < 4; i++)
	{
		body[i] = newBody[i];
	}
	for (int i = 0; i < 4; i++)
	{
		body[i].draw(c);
	}
}



//Function resets shape position (returns it to top)
void Shape::SquareBackToStart()
{
	Point head ={ 6,3 };
	body[0] = head;
	buildSquare();
	
}
void Shape::LineBackToStart()
{
	Point head = { 6,3 };
	body[0] = head;
	buildLine();

}
void Shape::ShapeLBackToStart()
{
	Point head = { 6,3 };
	body[0] = head;
	buildShapeL();

}
void Shape::ShapeTBackToStart()
{
	Point head = { 6,3 };
	body[0] = head;
	buildShapeT();

}
void Shape::ShapeZBackToStart()
{
	Point head = { 6,3 };
	body[0] = head;
	buildShapeZ();

}


//Function Draws (prints) the shape
void Shape::draw()
{
	for (int i = 0; i < 4; i++) {
		body[i].draw(c);
	}
}


/*
The function gets the user's selection and the gameArr,
And checks if she can move the shape,
if so she moves 
*/
void Shape::move(char keyPressed,char arr[10][15]) {
	bool canMove = true;
	if (keyPressed == 'd')//right
	{
		for (int i = 0; i < 4; i++) {
			if (!body[i].checkMove(Direction::RIGHT,arr,false))
				canMove = false;
		}
		if (canMove)
		{
			for (int i = 0; i < 4; i++)//מחיקת ריבוע לפני הזזה
				body[i].eraser();
			for (int i = 0; i < 4; i++)
			{
				body[i].move(Direction::RIGHT);
				body[i].draw(c);
			}
		}
	}
	if (keyPressed == 'a')//left
	{
		for (int i = 0; i < 4; i++) {
			if (!body[i].checkMove(Direction::LEFT, arr, false))
				canMove = false;
		}
		if (canMove)
		{
			for (int i = 0; i < 4; i++)//מחיקת ריבוע לפני הזזה
				body[i].eraser();
			for (int i = 0; i < 4; i++)
			{
				body[i].move(Direction::LEFT);
				body[i].draw(c);
			}
		}
	}
	if (keyPressed == 'w')//up
	{
		for (int i = 0; i < 4; i++) {
			if (!body[i].checkMove(Direction::UP, arr, false))
				canMove = false;
		}
		if (canMove)
		{
			for (int i = 0; i < 4; i++)//מחיקת ריבוע לפני הזזה
				body[i].eraser();
			for (int i = 0; i < 4; i++)
			{
				body[i].move(Direction::UP);
				body[i].draw(c);
			}
		}
	}
	if (keyPressed == 's')//down
	{
		for (int i = 0; i < 4; i++) {
			if (!body[i].checkMove(Direction::DOWN, arr, false))
				canMove = false;
		}
		if (canMove)
		{
			for (int i = 0; i < 4; i++)//מחיקת ריבוע לפני הזזה
				body[i].eraser();
			for (int i = 0; i < 4; i++)
			{
				body[i].move(Direction::DOWN);
				body[i].draw(c);
			}
		}
	}
}

/*
The function moves the shape down, If the shape moves
down it returns true, if it doesn't move return false*/
bool Shape::moveDown(char arr[10][15])
{
	bool canMove = true;
	for (int i = 0; i < 4; i++){
		if (!body[i].checkMove(Direction::DOWN, arr, false))
			canMove = false;
}
	if (canMove)
	{
		for (int i = 0; i < 4; i++)//מחיקת ריבוע לפני הזזה
			body[i].eraser();
		for (int i = 0; i < 4; i++)
		{
			body[i].move(Direction::DOWN);
			body[i].draw(c);
		}
		return true;
	}
	else
		return false;
}

//Functions that build the body of the shape according to the shape
void Shape::buildSquare()
{
	body[1] = body[0].right();
	body[2] = body[0].down();
	body[3] = body[2].right();
}

void Shape::buildLine()
{
	body[1] = body[0].down();
	body[2] = body[1].down();
	body[3] = body[2].down();
}

void Shape::buildShapeL()
{
	body[1] = body[0].down();
	body[2] = body[1].right();
	body[3] = body[2].right();
}

void Shape::buildShapeT()
{
	body[1] = body[0].down();
	body[2] = body[1].left();
	body[3] = body[1].right();
}

void Shape::buildShapeZ()
{
	body[1] = body[0].right();
	body[2] = body[1].down();
	body[3] = body[2].right();
}
//Gets Functions 

Point* Shape::getBody() {
	return this->body;
}

char Shape::getC()
{
	return this->c;
}


void Shape::backToStart() {}


void Shape::rotate(char arr[10][15]) {}

