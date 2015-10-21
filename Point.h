/**************************************************************
*	Author: Keyul Patel
* Date Created:			10/12/15
* Last Modification Date:	10/20/15
* Lab Number:			CST 211 Lab 1
* Filename:				Point.h
*
*
*			Overview: A point object consisting of two values
*
*			Input: two ints
*
*			Output: none
****************************************************************/


#include <iostream>

using namespace std;
class Point
{
	friend ostream &operator<<(ostream &os, const Point &rhs); // Output for a point object
	friend istream &operator>>(istream &is, Point &rhs); // Input for a point object

public:
	Point(int x = 0, int y = 0); // Constructor

	bool operator==(const Point &rhs); // Returns if the points are equal
	bool operator!=(const Point &rhs); // Returns if the points aren't equal

	int x(); // Returns x value
	int x() const; //Returns x value for const
	int y(); //Returns y value;
	int y() const; // Returns y value for const


private:
	int m_x; // x value
	int m_y; // y value
};