#ifndef _BOMB_H_
#define _BOMB_H_


#include "Point.h"
#include "Direction.h"



class Bomb {
private:
	Point body;//Will contain the location of the bomb
	char c;//How the Bomb looks
	//char dirKeys[4]; // the keys for the four possible directions
public:
	Bomb(const Point& plc, char c1);
	bool move(char keyPressed, char arr[10][15]);
	void backToStart();
	void draw();
	bool moveDown(char arr[10][15]);
	Point getBody();
	char getC();

};

#endif