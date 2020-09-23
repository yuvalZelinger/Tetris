#ifndef _TTRIS_GAME_H_
#define _TTRIS_GAME_H_

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Shape.h"
#include "Joker.h"
#include "bomb.h"
#include "Square.h"
#include "Line.h"
#include "ShapeL.h"
#include "ShapeT.h"
#include "ShapeZ.h"

using namespace std;

enum KEYS { ESC = 27 };

class TtrisGame {
private:
	
	enum { size = 5 }; // a constant
	
	//Create shapes
	Square square = { { 6, 1 }, '#' };
	Line line = { { 6, 1 }, '$' };
	ShapeL shapeL = { { 6, 1 }, '%' };
	ShapeT shapeT = { { 6, 1 }, 'x' };
	ShapeZ shapeZ = { { 6, 1 }, '&' };
	Shape *allShape[size] = { &square ,&line,&shapeL,&shapeT,&shapeZ };

	Joker joker = { { 6, 1 }, '+'  };//joker of the game
	Bomb bomb = { { 6, 1 }, '@'  };//bomd of the game
	int level = 5;//Will be used to determine the level of the game (speed of falling shapes)
	int score=0;//Will contain the result of the game
	int ShapesDown=0;//Will contain the number of shape that came down
	char gameArr[10][15];//An array to maintain the positions of shapes after they have been stopped

public:
	TtrisGame()
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 15; j++)
			{
				gameArr[i][j] = ' ';
			}
		}
	}
	void drawTtris();
	int isCompleteLine();
	int doBoom(Point p);
	void run();
	void drawTtris2();
	void menu(char choice);
	bool disqualification();
	void resetGame();
};

#endif


