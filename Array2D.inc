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

template <class T>
Array2D<T>::Array2D()
{
}

template <class T>
Array2D<T>::Array2D(int row, int col)
	: m_cols(col), m_rows(row)
{
	create_array(m_array, m_rows, m_cols);

}

template <class T> 
Array2D<T>::Array2D(const Array2D &arrayC)
{
	m_rows = arrayC.getRow();
	m_cols = arrayC.getColumn();
	create_array(m_array, m_rows, m_cols);
	for (int idx = 0; idx < m_rows; idx++)
	{
		T *memberElement = m_array[idx];
		for (int id = 0; id < m_cols; id++)
		{
			memberElement[id] = arrayC[idx][id];
		}
	}
}

template <class T>
Array2D<T>::~Array2D()
{
	for (int id = 0; id < m_cols; id++)
	{
		delete[]m_array[id];
	}
	delete[]*m_array;
}

template <class T>
Array2D<T> &Array2D<T>::operator=(const Array2D<T> &rhs)
{
	if (this != &rhs)
	{ 
		delete[]m_array;
		m_rows = arrayC.getRow();
		m_cols = arrayC.getColumn();
		create_array(m_array, m_rows, m_cols);
		for (int idx = 0; idx < m_rows; idx++)
		{
			T *memberElement = m_array[idx];
			for (int id = 0; id < m_cols; id++)
			{
				memberElement[id] = rhs[idx][id];
			}
		}
		
	}

	return *this;
}

template <class T>
Row<T> Array2D<T>::operator[](int index)
{
	if (0 <= index && index < getRow()){
		Row<T> rowObj(*this, index);
		return rowObj;
	}
	Exception fail("Out of Bounds");
	throw(fail);
}

template <class T>
Row<T> Array2D<T>::operator[](int index) const
{
	if (0 <= index && index < getRow()){
		Row<T> rowObj(*this, index);
		return rowObj;
	}
	Exception fail("Out of Bounds");
	throw(fail);
}

template <class T>
int Array2D<T>::getRow() const
{
	return m_rows;
}

template <class T>
void Array2D<T>::setRow(int rows) 
{
	T **temp_array;

	create_array(temp_array, rows, m_cols);
	array_transfer(temp_array, rows, m_cols, true);

	delete[]m_array;

	create_array(m_array, rows, m_cols);
	array_transfer(temp_array, rows, m_cols, false);

	delete[]temp_array;
}

template <class T>
int Array2D<T>::getColumn() const
{
	return m_cols;
}

template <class T>
void Array2D<T>::setColumn(int columns)
{
	T **temp_array;

	create_array(temp_array, m_rows, columns);
	array_transfer(temp_array, m_rows, columns, true);
	
	delete []m_array;

	create_array(m_array, m_rows, columns);
	array_transfer(temp_array, m_rows, columns, false);

	delete[]temp_array;
	
}

template <class T>
T &Array2D<T>::Select(int row, int col) const
{
	T *element = m_array[row];
	return element[col];
}

template <class T>
void Array2D<T>::create_array(T **&new_array, int rows, int cols)
{
	new_array = new T*[rows];
	for (int i = 0; i < rows; i++)
	{
		m_array[i] = new T[cols];

	}
}

template <class T>
void Array2D<T>::array_transfer(T **new_array, int rows, int cols, bool conserve)
{

	for (int idx = 0; idx < rows; idx++)
	{
		T *memberElement = m_array[idx];
		T *tempElement = new_array[idx];
		for (int id = 0; id < cols; id++)
		{
			if (conserve)
			{
				tempElement[id] = memberElement[id];
			}
			else
			{
				memberElement[id] = tempElement[id];
			}
		}
	}

}