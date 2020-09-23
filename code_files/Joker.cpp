#include "Joker.h"

using namespace std;

//Constructor function for joker
Joker::Joker( const Point& plc, char c1) {
	c = c1;
	body= plc;
}

/*
The function gets the user's selection and the gameArr,
And checks if she can move the Joker,
if so she moves and returns true. if not it return a false
*/
bool Joker::move(char keyPressed, char arr[10][15]) {
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
				body.draw(c);
				return true;
			}
		}
	if (keyPressed == 's')//down
	{
		return false;
	}
	return true;
}

//Function resets Joker position(returns it up)
void Joker::backToStart()
{
	body= { 6,3 };
}


//Function Draws (prints) the Joker
void Joker::draw()
{
	body.draw(c);
}

/*
The function moves the Joker down, If the shape moves
down it returns true, if it doesn't move return false*/
bool Joker::moveDown(char arr[10][15])
{
		bool canMove = true;
			if (!body.checkMove(Direction::DOWN, arr, true))
				canMove = false;

		if (canMove)
		{
				body.eraser();
				body.move(Direction::DOWN);
				body.draw(c);
			return true;
		}
		else
			return false;
}

//Gets Functions

Point Joker::getBody()
{
	return this->body;
}

char Joker::getC()
{
	return this->c;
}