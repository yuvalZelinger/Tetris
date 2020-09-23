#include "Bomb.h"

using namespace std;

//Constructor function for bomb
Bomb::Bomb(const Point& plc, char c1) {
	c = c1;
	body = plc;
}


/*
The function gets the user's selection and the gameArr,
And checks if she can move the bomb,
if so she moves and returns true. if not it return a false
*/
bool Bomb::move(char keyPressed, char arr[10][15]) {
	bool canMove = true;
	if (keyPressed == 'd')//right
	{
		if (!body.checkMove(Direction::RIGHT, arr, true)) {
			canMove = false;

		}
		if (canMove)
		{
			body.eraser();
			body.move(Direction::RIGHT);
			if (arr[body.getX()-1][body.getY()-1] != ' ')
				return false;
			body.draw(c);
			return true;
		}
	}
	if (keyPressed == 'a')//left
	{
		if (!body.checkMove(Direction::LEFT, arr, true)) {
			canMove = false;
		}
		if (canMove)
		{
			body.eraser();
			body.move(Direction::LEFT);
			if (arr[body.getX() - 1][body.getY() - 1] != ' ')
				return false;
			body.draw(c);
			return true;
		}
	}
	if (keyPressed == 's')//down
	{
		if (!body.checkMove(Direction::DOWN, arr, true)) {
			canMove = false;
		}
		if (canMove)
		{
			body.eraser();
			body.move(Direction::DOWN);
			if (arr[body.getX() - 1][body.getY() - 1] != ' ')
				return false;
			body.draw(c);
			return true;
		}
	}
	return true;
}

////Function resets Bomb position(returns it up)
void Bomb::backToStart()
{
		body = { 6,3 };
}

//Function Draws (prints) the Bomb
void Bomb::draw()
{
	body.draw(c);
}

/*
The function moves the Bomb down, If the shape moves
down it returns true, if it doesn't move return false*/
bool Bomb::moveDown(char arr[10][15])
{
	bool canMove = true;
	if (!body.checkMove(Direction::DOWN, arr, true))
		canMove = false;

	if (canMove)
	{
		body.eraser();
		body.move(Direction::DOWN);
		if (arr[body.getX() - 1][body.getY() - 1] != ' ')
			return false;
		body.draw(c);
		return true;
	}
	else
		return false;
}

//Gets Functions

Point Bomb::getBody()
{
	return this->body;
}

char Bomb::getC()
{
	return this->c;
}