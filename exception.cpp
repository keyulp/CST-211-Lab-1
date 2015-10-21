#include "exception.h"

/**************************************************************
*	Author: Keyul Patel
* Date Created:			10/10/15
* Last Modification Date:	10/11/15
* Lab Number:			CST 211 Assignment 2
* Filename:				exception.cpp
*
*
*			Overview: To output messages for exceptions
*
*			Input: A string
*
*			Output: None
****************************************************************/


Exception::Exception(const char *msg)
{
	m_msg = new char[strlen(msg)];

	for (unsigned int i = 0; i < strlen(msg); i++)
	{
		m_msg[i] = msg[i];
	}

}

Exception::~Exception()
{
	delete []m_msg;
}

char Exception:: getMessage() const 
{ 
	return *m_msg; 
}

void Exception::setMessage(const char *msg)
{
	delete[]m_msg;
	m_msg = new char[strlen(msg)];

	for (unsigned int i = 0; strlen(msg) < i; i++)
	{
		m_msg[i] = msg[i];
	}
}

Exception &Exception::operator=(const Exception &rhs)
{

	delete[] m_msg;
	m_msg = new char[strlen(rhs.m_msg)];

	setMessage(rhs.m_msg);
	return *this;
}

ostream &operator<<(ostream &out, const Exception &thing)
{
	return out << thing.getMessage();

}