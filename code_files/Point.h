#ifndef _POINT_H_
#define _POINT_H_

#include <iostream>
#include "Gotoxy.h"
#include "Direction.h"

using namespace std;

class Point
{
	// shape Position
	int x;
	int y;
	//Change location
	int dir_x;
	int dir_y;

	//Move a point
	void moveImpl() {
		x = x + dir_x;
		y = y + dir_y;
			
	}
	
public:
	//Constructor function for point
	Point(int x1 = 1, int y1 = 1) {
		x = x1;
		y = y1;
	}

	int getX();
	int getY();
	void draw(char c) {
		gotoxy(x, y);
		cout << c << endl;
	}
	void eraser(char c = ' ') {
		gotoxy(x, y);
		cout << c << endl;
	}
	void changeDir(Direction dir);

	bool checkMove(Direction dir, char arr[10][15], bool isJokerOrBomb);
	bool checkRotate(char arr[10][15]);
	void move(Direction dir) {
		changeDir(dir);
		moveImpl();
	}
	//Move the point functions
	Point right() const {
		return Point(x + 1, y);
	}
	Point left() const {
		return Point(x - 1, y);
	}
	Point down() const {
		return Point(x, y + 1);
	}
	Point up() const {
		return Point(x, y - 1);
	}
	
	
};


#endif
