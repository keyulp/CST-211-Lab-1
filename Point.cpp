/**************************************************************
*	Author: Keyul Patel
* Date Created:			10/12/15
* Last Modification Date:	10/20/15
* Lab Number:			CST 211 Lab 1
* Filename:				Point.cpp
*
*
*			Overview: A point object consisting of two values
*
*			Input: Two ints
*
*			Output: none
****************************************************************/


#include"Point.h"

Point::Point(int x, int y) : m_x(x), m_y(y)
{

}

bool Point::operator==(const Point &rhs)
{
	if (m_x == rhs.x() && m_y == rhs.y())
	{
		return true;
	}
	return false;
}
bool Point::operator!=(const Point &rhs)
{
	return !(*this == rhs);
}

int Point::x()
{
	return m_x;
}
int Point::x() const
{
	return m_x;
}
int Point::y()
{
	return m_y;
}
int Point::y() const
{
	return m_y;
}

ostream &operator<<(ostream &os, const Point &rhs)
{
	return os << rhs.x() << "," << rhs.y();
}

istream &operator>>(istream &is, Point &rhs)
{
	char d;
	int x;
	int y;
	is >> x >> d >> y;
	rhs.m_x = x;
	rhs.m_y = y;
	return is;
}