/**************************************************************
*	Author: Keyul Patel
* Date Created:			10/12/15
* Last Modification Date:	10/20/15
* Lab Number:			CST 211 Lab 1
* Filename:				MineSweeper.h
*
*
*			Overview: A game of minesweeper
*
*			Input: The difficulty of the game
*
*			Output: none
****************************************************************/


#include "Board.h"

enum difficulty{ b, i, e };

class MineSweeper
{
public:
	
	MineSweeper(difficulty in); // Constructor
	
	bool turn(); // Turn function to see if game is running

	void flipMark(char in, Point loc); // Flag or turn a space as necessary

private:
	Board *game; // The game board

	difficulty m_dif; // The game difficulty

	void play(); // Actually playing of the game
};