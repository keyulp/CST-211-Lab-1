/**************************************************************
*	Author: Keyul Patel
* Date Created:			10/10/15
* Last Modification Date:	10/11/15
* Lab Number:			CST 211 Assignment 2
* Filename:				row.cpp
*
*
*			Overview: A thing to read the row
*
*			Input: An Array2D object and a row number
*
*			Output: none
****************************************************************/

template <class T>
Row<T>::Row(const Array2D<T> &Array, int row) 
	: m_array2D(Array), m_row(row)
{
	
}

template <class T>
T &Row<T>::operator[](int column)
{
	if (0 <= column && column < m_array2D.getColumn()){
		return m_array2D.Select(m_row, column);
	}
	Exception fail("Out of Bounds");
	throw(fail);
}

template <class T>
T &Row<T>::operator[](int column) const
{
	if (0 <= column && column < m_array2D.getRow()){
		return m_array2D.Select(m_row, column);
	}
	Exception fail("Out of Bounds");
	throw(fail);
}

