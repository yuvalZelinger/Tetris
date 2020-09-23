#ifndef _JOKER_H_
#define _JOKER_H_


#include "Point.h"
#include "Direction.h"



class Joker {
private:
	Point body;//Will contain the location of the Joker
	char c;//How the Joker looks
	//char dirKeys[4]; // the keys for the four possible directions
public:
	Joker(const Point& plc, char c1);
	bool move(char keyPressed, char arr[10][15]);
	void backToStart();
	void draw();
	bool moveDown(char arr[10][15]);
	Point getBody();
	char getC();

};


#endif
