#include<stdlib.h>

#include "GameBoard.h"
#include "TtrisGame.h"
#include "Shape.h"

using namespace std;

//Run function
void TtrisGame::run() {
	const int numOfShaps = 7;//umber of shapes in the game
	Point* p;//Will contain the body of the shapes
	Point p1;//Will contain the body of the joker & bomb
	GameBoard board;//For drawing the frame of the board
	int count = 0;//Will be used to count when to bring down shape.
	int shapeType = rand() % numOfShaps;//Will be drawn and determine the next shape
	bool crateNextShape = true;//Will be used to decide when to create the next shape
	bool moveDown;//Is the shape move down in the round of the loop
	menu(0);
	while (true)
	{
		while (true)
		{
			moveDown = false;
			if ((shapeType>=0)&&(shapeType<=4))//if shape
			{
				if (crateNextShape)//If need to create it
				{
					allShape[shapeType]->backToStart();
					allShape[shapeType]->draw();
					crateNextShape = false;
				}
				Sleep(level * 10);//Suspension (the speed of the game)
				if (count == 10)
				{
					moveDown = true;
					count = 0;
					if (!allShape[shapeType]->moveDown(this->gameArr))//Move down the shape - return false if cant move down 
					{
						p = allShape[shapeType]->getBody();
						for (int i = 0; i < 4; i++)//Update the array
						{
							gameArr[p[i].getX() - 1][p[i].getY() - 1] = allShape[shapeType]->getC();

						}
						if (disqualification())
							break;
						crateNextShape = true;
						shapeType = rand() % numOfShaps;
						score += isCompleteLine();
						ShapesDown++;
					}

				}
				char keyPressed = 0;
				//If pressed
				if (_kbhit()) {
					keyPressed = _getch();
					if (keyPressed == '9') {
						break;
					}
					else {
						if ((keyPressed >= '1') && (keyPressed <= '4'))
							menu(keyPressed);
						else
						{
							if (!moveDown) {
								if (keyPressed == 'w')
									allShape[shapeType]->rotate(this->gameArr);
								else
									allShape[shapeType]->move(keyPressed, gameArr);
							}
						}
					}
					//system("pause>null");
				}
				drawTtris();
			}
			if (shapeType == 5)//if joker
			{
				if (crateNextShape)//If need to create it
				{
					joker.backToStart();
					joker.draw();
					crateNextShape = false;
				}
				Sleep(level * 10);//Suspension (the speed of the game)
				if (count == 10)
				{
					count = 0;
					if (!joker.moveDown(this->gameArr))//Move down the joker - return false if cant move down 
					{
						p1 = joker.getBody();
						gameArr[p1.getX() - 1][p1.getY() - 1] = joker.getC();//Update the array
						score += isCompleteLine();
						crateNextShape = true;
						shapeType = rand() % numOfShaps;
					}
				}
				char keyPressed = 0;
				//If pressed
				if (_kbhit()) {
					keyPressed = _getch();
					if (keyPressed == '9') {
						break;
					}
					else {
						if ((keyPressed >= '1') && (keyPressed <= '4'))
							menu(keyPressed);
						else
						{
							if (!joker.move(keyPressed, gameArr)) {
								p1 = joker.getBody();
								gameArr[p1.getX() - 1][p1.getY() - 1] = joker.getC();//Update the array
								score += isCompleteLine();
								crateNextShape = true;
								shapeType = rand() % numOfShaps;
							}
						}
					}
				}
				drawTtris();
			}

			if (shapeType == 6)//if bomb
			{
				if (crateNextShape)//If need to create it
				{
					bomb.backToStart();
					bomb.draw();
					crateNextShape = false;
				}

				Sleep(level * 10);//Suspension (the speed of the game)
				if (count == 10)
				{
					count = 0;
					if (!bomb.moveDown(this->gameArr))//Move down the bomb - return false if cant move down 
					{
						score -= doBoom(bomb.getBody());
						crateNextShape = true;
						shapeType = rand() % numOfShaps;
					}
				}
				char keyPressed = 0;
				//If pressed
				if (_kbhit()) {
					keyPressed = _getch();
					if (keyPressed == '9') {
						break;
					}
					else {
						if ((keyPressed >= '1') && (keyPressed <= '4'))
							menu(keyPressed);
						else
						{
							if (!bomb.move(keyPressed, gameArr)) {
								score -= doBoom(bomb.getBody());
								crateNextShape = true;
								shapeType = rand() % numOfShaps;
							}
						}
					}
				}

				drawTtris();
			}
			count++;
		}
		clrscr();
		gotoxy(4, 2);
		cout << "GAME OVER!";
		gotoxy(2, 3);
		cout << "Score: " << score << "  Number of shapes: " << ShapesDown;;
		gotoxy(2, 5);
		cout << "For a new game press 1";
		gotoxy(2, 6);
		cout << "To exit Press 9";
		char keyPressed;
		while (true)
		{
			//If pressed
			if (_kbhit()) {
				keyPressed = _getch();
				break;
			}
		}
		if (keyPressed == '9')
			break;
		else
		{
			//Game restarts
			clrscr();
			shapeType = rand() % numOfShaps;
			crateNextShape = true;
			resetGame();
			count = 0;
			board.drawBoard();
			menu(0);
		}
	}

}

//A function that draws the Tetris game according to the 
//gameArr(Not including drawing spaces) and prints data
void TtrisGame::drawTtris()
{
	gotoxy(1, 0);
	cout << "Score:           ";
	gotoxy(1, 0);
	cout << "Score: " << score;
	gotoxy(1, 1);
	cout << "shapes:           ";
	gotoxy(1, 1);
	cout << "shapes: " << ShapesDown;
	
	for (int i = 0; i < 10; i++)
	{
		for (int j = 3; j < 15; j++)
		{
				gotoxy(i + 1, j + 1);
				if (gameArr[i][j] != ' ')
					cout << gameArr[i][j];
		}
	}
}

//A function that draws the Tetris game according to the 
//gameArr(Including drawing spaces) and prints data
void TtrisGame::drawTtris2()
{
	gotoxy(1, 0);
	cout << "Score: " << score;
	gotoxy(1, 1);
	cout << "shapes: " << ShapesDown;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 3; j < 15; j++)
		{
			gotoxy(i + 1, j + 1);
			cout << gameArr[i][j];
		}
	}
}

/*When a bomb explodes, the function deletes what the bomb has 
blew up and updates the array.
The function returns the number of squares blown by Multiplied by 50*/
int TtrisGame::doBoom(Point p) {
	int x = p.getX() - 1;
	int y = p.getY() - 1;	
	int blowUp = 0;

	if (gameArr[x][y] != ' ')
	{
		gameArr[x][y] = ' ';
		blowUp++;
	}
	if (x < 9)
	{
		if (gameArr[x + 1][y] != ' ')
		{
			gameArr[x + 1][y] = ' ';
			blowUp++;
		}
	}
	if (x > 0)
	{
		if (gameArr[x - 1][y] != ' ')
		{
			gameArr[x - 1][y] = ' ';
			blowUp++;
		}
	}
	if (y < 14)
	{
		if (gameArr[x][y + 1] != ' ')
		{
			gameArr[x][y + 1] = ' ';
			blowUp++;
		}
		if (x < 9)
		{
			if (gameArr[x + 1][y + 1] != ' ')
			{
				gameArr[x + 1][y + 1] = ' ';
				blowUp++;
			}
		}
		if (x > 0)
		{
			if (gameArr[x - 1][y + 1] != ' ')
			{
				gameArr[x - 1][y + 1] = ' ';
				blowUp++;
			}
		}
	}
	if (y > 0)
	{
			if (gameArr[x][y - 1] != ' ')
			{
				gameArr[x][y - 1] = ' ';
				blowUp++;
			}
			if (x < 9)
			{
				if (gameArr[x + 1][y - 1] != ' ')
				{
					gameArr[x + 1][y - 1] = ' ';
					blowUp++;
				}
			}
		if (x > 0)
		{
			if (gameArr[x - 1][y - 1] != ' ')
			{
				gameArr[x - 1][y - 1] = ' ';
				blowUp++;
			}
		}
	}
	drawTtris2();
	return blowUp*50;
}

/*The function checks whether there is a complete line If so, delete 
the full complete lines, update the array and move down lines accordingly.
The function returns its score according to the number of complete lines*/
int TtrisGame::isCompleteLine() {

	int numOfLines = 0;
	bool complete;

	for (int i = 14; i >=0; i--)
	{
		complete = true;

		for (int j = 0; j <10; j++)
		{
			if (gameArr[j][i] == ' ')
			{
				complete = false;
				//break;
			}
		}
		if (complete == true)
		{
			numOfLines++;
			for (int j = 0; j < 10; j++)
			{
					gotoxy(j + 1, i + 1);
					cout << ' ';
			}
			Sleep(50);
			for (int k = i; k > 0; k--)
			{
				for (int j = 0; j < 10; j++)
				{
					//gameArr[j][k] == ' ';
					gameArr[j][k] = gameArr[j][k-1];
				}
			}
			for (int j = 0; j < 10; j++)
			{
				gameArr[j][0] = ' ';
			}
			i++;
		}
	}
	if (numOfLines == 0)
		return 0;
	else
		drawTtris2();
	if (numOfLines == 1)
		return 100;
	if (numOfLines == 2)
		return 300;
	if (numOfLines == 3)
		return 500;
	if (numOfLines == 4)
		return 700;
}
/*he function checks whether the player is disqualified
and returns truth if so , otherwise the function returns false*/
bool TtrisGame::disqualification()
{
	for (int i = 0; i < 10; i++)
	{
		if (gameArr[i][2] != ' ')
			return true;
	}
	return false;

}

/*The function displays the menu and operates according to 
the player's selection*/
void TtrisGame::menu(char choice)
{
	if (choice == 0)
	{
		gotoxy(13, 2);
		cout << "To start the game press- 1";
		gotoxy(13, 3);
		cout << "To stop or continue Press- 2";
		gotoxy(13, 4);
		cout << "TO increas the speed of falling parts Press - 3";
		gotoxy(13, 5);
		cout << "TO slow down the speed of falling parts Press - 4";
		gotoxy(13, 6);
		cout << "TO EXIT Press - 9";
		while (true)
		{
			if (_kbhit()) {
				choice = _getch();
				if (choice == '1') {
					break;
				}
			}
		}
	}
	if (choice == '2')
	{
		while (true)
		{
			if (_kbhit()) {
				choice = _getch();
				if (choice == '2') {
					break;
				}
			}
		}
	}
	if (choice == '3')
		level--;
	if (choice == '4')
		level++;
}

/*The function is used to restart the game-
It resets all relevant variable*/
void TtrisGame::resetGame()
{
	level = 5;
	score = 0;
	ShapesDown = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			gameArr[i][j] = ' ';
		}
	}
}