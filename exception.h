#include <iostream>

using namespace std;
/**************************************************************
*	Author: Keyul Patel
* Date Created:			10/10/15
* Last Modification Date:	10/11/15
* Lab Number:			CST 211 Assignment 2
* Filename:				exception.h
*		 
*
*			Overview: To output messages for exceptions
*			
*			Input: A string
*
*			Output: None
****************************************************************/

class Exception
{
	friend ostream &operator<<(ostream &out, const Exception &thing);

public:
	Exception();
	Exception(const char *msg);
	~Exception();

	Exception &operator=(const Exception &rhs);

	char getMessage() const;
	void setMessage(const char *msg);



	

private:
	char *m_msg;
};

