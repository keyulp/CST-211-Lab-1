/**************************************************************
*	Author: Keyul Patel
* Date Created:			10/12/15
* Last Modification Date:	10/20/15
* Lab Number:			CST 211 Lab 1
* Filename:				Cell.h
*
*
*			Overview: A cell object that contains a bomb
*						can be flagged, and flipped
*
*			Input: If it has a bomb
*
*			Output: none
****************************************************************/


#include <iostream>
using namespace std;

class Cell
{
	friend ostream &operator<<(ostream &os, const Cell &Cell); // Cell output

public:
		Cell(bool bomb = false); // Constructor

		bool bomb(); // Returns if there is a bomb
		bool bomb() const; // Returns if there is a bomb for const
		void placeBomb(); // Makes a bomb

		bool turned(); // Returns if turned
		bool turned() const; // Returns if turned for const
		void turn(); // Turns the space

		bool flagged(); // Returns if flagged
		bool flagged() const; // Returns if flagged for const
		void flag(); // Flags or unflags a cell

		int bombsNear(); // Returns number of bombs near
		int bombsNear() const; // Returns number of bombs near for const
		void addNearBomb(); // Adds a nearby bomb




private:
	bool m_bomb; // Keeps data on if the cell is a bomb
	bool m_turned; // Keeps data on if the cell is turned
	bool m_flagged; // Keeps data on if the cell is flagged

	int m_bombsNear; //  Keeps data on number of bombs near current cell


};