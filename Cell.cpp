/**************************************************************
*	Author: Keyul Patel
* Date Created:			10/12/15
* Last Modification Date:	10/20/15
* Lab Number:			CST 211 Assignment 2
* Filename:				Cell.cpp
*
*
*			Overview: A cell object that contains a bomb
*						can be flagged, and flipped
*
*			Input: If it has a bomb
*
*			Output: none
****************************************************************/


#include "Cell.h"

Cell::Cell(bool bomb): m_bomb(bomb), m_turned(false), m_flagged(false), m_bombsNear(0)
{

}

bool Cell::bomb()
{
	return m_bomb;
}
bool Cell::bomb() const
{
	return m_bomb;
}
void Cell::placeBomb()
{
	m_bomb = true;
}

bool Cell::turned()
{
	return m_turned;
}

bool Cell::turned() const
{
	return m_turned;
}

void Cell::turn()
{
	m_turned = !m_turned;
}

bool Cell::flagged()
{
	return m_flagged;
}

bool Cell::flagged() const
{
	return m_flagged;
}

void Cell::flag()
{
	m_flagged = !m_flagged;
}

int Cell::bombsNear()
{
	return m_bombsNear;
}

int Cell::bombsNear() const
{
	return m_bombsNear;
}

void Cell::addNearBomb()
{
	m_bombsNear++;
}

ostream &operator<<(ostream &os, const Cell &Cell)
{
	if (Cell.flagged() && !Cell.turned())
	{
		os << "!";
	}
	else if (!Cell.flagged() && !Cell.turned())
	{
		os << "?";
	}
	else if (!Cell.bomb())
	{
		os << Cell.bombsNear();
	}
	else
	{
		os << "X";
	}


	return os;
}