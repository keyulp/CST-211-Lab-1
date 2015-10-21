/**************************************************************
*	Author: Keyul Patel
* Date Created:			10/12/15
* Last Modification Date:	10/20/15
* Lab Number:			CST 211 Lab 1
* Filename:				MineSweeper.cpp
*
*
*			Overview: A game of minesweeper
*
*			Input: The difficulty of the game
*
*			Output: none
****************************************************************/


#include"MineSweeper.h"

MineSweeper::MineSweeper(difficulty in) : m_dif(in)
{
	if (in == b)
	{
		Point place(10, 10);
		game = new Board(place, 10);
	}
	else if (in == i)
	{
		Point place(16, 16);
		game = new Board(place, 40);
	}
	else
	{
		Point place(16, 32);
		game = new Board(place, 100);
	}
}


bool MineSweeper::turn()
{
	system("cls");
	game->displayBoard();
	
	if (!(game->winCheck() || game->loseCheck()))
	{
		play();
		return true;
	}

	else if (game->winCheck())
	{
		cout << endl << endl << "You Win!" << endl << endl;
		system("pause");
		system("cls");
		return false;
	}
	else
	{
		cout << endl << endl << "You Lose!" << endl << endl;
		system("pause");
		system("cls");
		return false;
	}
}

void MineSweeper::flipMark(char in, Point loc)
{
	if (in == 'f')
	{
		game->flagSpace(loc);
	}
	else
	{
		game->turnSpace(loc);
	}
}

void MineSweeper::play()
{
	char in = 0;
	Point loc(10, 10);
	int messUps = 0;
	do
	{
		if (messUps)
		{
			cout << "Invalid choice" << endl << endl;
			system("pause");
		}
		system("cls");
		game->displayBoard();
		cout << "Flag or turn(f/t):" << endl;
		cin >> in;
		messUps++;
	} while (!(in == 'f' || in == 't'));

	messUps = 0;
	do
	{
		if (messUps)
		{
			cout << "Invalid choice" << endl << endl;
			system("pause");
		}
		system("cls");
		game->displayBoard();

		if (in == 'f')
		{
			cout << "Flag";
		}
		else
		{
			cout << "Turn";
		}
		cout << " spot (x,y):" << endl;
		cin >> loc;
		if (cin.fail())
		{
			throw(new Exception("Type input error"));
		}
		messUps++;
	} while (!game->inBounds(loc));

	flipMark(in, loc);
}