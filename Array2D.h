/**************************************************************
*	Author: Keyul Patel
* Date Created:			10/10/15
* Last Modification Date:	10/11/15
* Lab Number:			CST 211 Assignment 2
* Filename:				Array2D.h
*
*
*			Overview: A tempmlated 2D array
*
*			Input: A number of rows and columns
*
*			Output: none
****************************************************************/


#include "exception.h"
#include "Row.h"

using  namespace  std;


#ifndef Array2D_h
#define Array2D_h



template <class T>
class Array2D
{
public:
	Array2D(); // Default Constructor
	Array2D(int row, int col);  // Constructor for the 2D array
	Array2D(const Array2D &copy); //Copy Constructor
	~Array2D(); //Destructor

	Array2D &operator=(const Array2D &rhs); //= Operator Overload
	Row<T> operator[](int index); //[] Operator Overload
	Row<T> operator[](int index) const; //[] Operator Overload for const

	int getRow() const; //Returns the number of rows
	void setRow(int rows); //Changes the number of rows
	int getColumn() const; //Returns the number of colums
	void setColumn(int columns); //Changes the number of columns

	T &Select(int row, int column) const; //Used to select an element in the 2D array object

private:

	T **m_array; // Pointer to an array of the data type that will be allocated
	int m_rows;  // Number of rows 
	int m_cols; // Number of columns 

	void create_array(T **&new_array, int rows, int cols); //Used to allocate data for new arrays
	void array_transfer(T **new_array, int rows, int cols, bool conserve); //Used to conserve and transfer data between 2D arrays
};

#include "Array2D.inc"

#endif