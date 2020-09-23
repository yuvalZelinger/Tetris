#include "Point.h"

// function to update the point's moving variables
void Point::changeDir(Direction dir) {
	switch (dir) {
	case Direction::LEFT:
			dir_x = -1;
			dir_y = 0;
		break;
	case Direction::RIGHT:
			dir_x = 1;
			dir_y = 0;
		break;
	case Direction::UP:
			dir_x = 0;
			dir_y = -1;
		break;
	case Direction::DOWN:
			dir_x = 0;
			dir_y = 1;
		break;
	}
}


/*
The function gets Direction to move, the gameArr,
And checks if she can move the point,(Different for bomb and joker and shapes)
if so she moves and returns true. if not it return a false
*/
bool Point::checkMove(Direction dir, char arr[10][15],bool isJokerOrBomb) {
	//cout << "checkMove--"<< x <<"--\n";
	if (isJokerOrBomb)
	{
		switch (dir) {
		case Direction::LEFT:
			if (x != 1) 
				return true;
			break;
		case Direction::RIGHT:
			if (x != 10)
				return true;
			break;
		case Direction::DOWN:
			if (y != 15)
				return true;
			break;
		}
	}
	else
	{
		switch (dir) {
		case Direction::LEFT:
			if (x > 1)
			{
				if (arr[x - 2][y - 1] == ' ')
					return true;
			}
			break;
		case Direction::RIGHT:
			if (x < 10) 
			{
				if (arr[x][y - 1] == ' ')
					return true;
			}
			break;
		case Direction::UP:
			if (y != 1) 
			{
				if (arr[x - 1][y - 2] == ' ')
					return true;
			}
			break;
		case Direction::DOWN:
			if (y != 15)
			{
			if (arr[x - 1][y] == ' ')
					return true;
			}
			break;
		}
	}
	return false;
}

//A function that checks for the points of the rotating shape if possible or not
bool Point::checkRotate(char arr[10][15])
{
	if ((x != 0) && (x != 11) && (y != 0) && (y != 16) && (arr[x-1][y-1] == ' '))
		return true;
	else
		return false;
}


//Gets Functions

int Point::getX() {
	return this->x;
}

int Point::getY() {
	return this->y;
}