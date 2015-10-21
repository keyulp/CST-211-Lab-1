/**************************************************************
*	Author: Keyul Patel
* Date Created:			10/12/15
* Last Modification Date:	10/20/15
* Lab Number:			CST 211 Lab 1
* Filename:				Board.h
*
*
*			Overview: A 2D Array of cells
*
*			Input: The size and number of mines
*
*			Output: none
****************************************************************/


#include <stdio.h>  
#include <stdlib.h>   
#include <time.h>     


#include "Cell.h"
#include "Array2D.h"
#include "Point.h"

class Board
{

public:

	Board(Point loc, int mines); // Constructor

	void flagSpace(Point loc); // Sets a flag at location
	void turnSpace(Point loc); // Turns the space at location

	void displayBoard(); // Displays the board

	bool loseCheck(); // Checks if the game has been lost
	bool winCheck(); // Checks if the game has been won

	bool inBounds(Point loc); // Checks if in bounds

private:
	Array2D<Cell> m_board; // Array for the board
	int m_numBombs; // Number of bombs
	int m_safeSpaces; //Number of safe spaces


	void add_nearBombs(); //Adds the nearby bombs to cells
	void add_Bombs(); // Places the bombs
	void reveal_around(Point Loc); // Turns all the spaces around loc
	
};