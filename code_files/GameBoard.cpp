#include "GameBoard.h"
#include "Gotoxy.h"
#include <iostream>
#include "Shape.h"

using namespace std;

GameBoard::GameBoard() {
	gotoxy(0, 2);
	cout << "************\n";
	for (int i = 0; i < 13; i++)
		cout << "*          *\n";
	cout << "************\n";
}
//The function draws the frame of the board
void GameBoard::drawBoard()
{
	gotoxy(0, 2);
	cout << "************\n";
	for (int i = 0; i < 13; i++)
		cout << "*          *\n";
	cout << "************\n";
}

