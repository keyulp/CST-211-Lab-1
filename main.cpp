#include <iostream>
#include "MineSweeper.h"

using namespace std;

void rules()
{
	system("cls");
	cout << "The rules in Minesweeper are simple:" << endl << endl
		<< "Uncover a mine, and the game ends" << endl << endl
		<< "Uncover an empty square, and you keep playing" << endl << endl
		<< "Uncover a number, and it tells you how many mines" << endl
		<< "lay hidden in the eight surrounding squares information" << endl
		<< "you use to deduce which nearby squares are safe to uncover." << endl << endl;
	system("pause");
	system("cls");
}

bool keepPlay()
{
	int num;
	while (true){
		cout << "1. Play Game" << endl
			<< "2. Rules" << endl
			<< "3. Quit" << endl
			<< "Enter: ";
		cin >> num;
		cout << endl;

		if (num == 1)
		{
			return true;
		}
		else if (num == 2)
		{
			rules();
		}
		else if (num == 3)
		{
			return false;
		}
		else
		{
			cout << "Invalid choice" << endl << endl;
			system("pause");
			system("cls");
		}
	}

}

difficulty select()
{
	char in;
	while (true)
	{
		system("cls");
		cout << "Beginner     [10x10 with  10 mines]: b" << endl
			 << "Intermediate [16x16 with  40 mines]: i" << endl
			 << "Expert       [16x32 with 100 mines]: e" << endl
			 << endl
			 << "Enter a difficulty: " << endl;

		cin >> in;
		cout << endl;
		if (in == 'b')
		{
			return b;
			
		}
		else if (in == 'i')
		{
			return i;
			
		}
		else if (in == 'e')
		{
			return e;
			
		}
		else
		{
			cout << "Invalid choice" << endl << endl;
			system("pause");
			system("cls");
		}
	}
}

int main()
{
	try{
		while (keepPlay()){
			MineSweeper game(select());
			while (game.turn());
		}
		system("cls");
		cout << "Thanks for Playing!" << endl << endl;
	}
	catch (Exception &e)
	{
		cout << e << endl;
	}
	system("pause");
	return 0;
}