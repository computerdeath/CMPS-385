//-----------------------------------------------------------------
// Name: Joshua Serrano
// Course: CMPS 385
// Project 3 Part 2
// Due 9/26/2015
// Professor Dr. Ahmadnia
// Purpose: Use stacks to change the bases of numbers
//-------------------------------------------------------------------
#include <iostream>
#include <random>
#include <time.h>
using namespace std;
class STACKint
{
private:int j[10];
		int counter;
public: void ClearStack()
{
	counter = 0;
}
		bool FullStack()
		{
			return (counter == 10) ? true : false;
		}
		bool EmptyStack()
		{
			return (counter == 0) ? true : false;
		}
		void PushStack(int x)
		{
			j[counter] = x; 
			counter++;
		}
		int PopStack()
		{
			counter--;
			return j[counter];
		}
};
int main()
{
	STACKint NUM;
	STACKint oddNUM;
	STACKint evenNUM;
	srand (time(NULL));
	NUM.ClearStack(); oddNUM.ClearStack(); evenNUM.ClearStack();
	int count = 0;
	while (count<10)
	{
		int randomNumber=rand() % 99 + 1;
		NUM.PushStack(randomNumber);
		if (randomNumber % 2 == 0)
			evenNUM.PushStack(randomNumber);
		else
			oddNUM.PushStack(randomNumber);
		count++;
	} 
	cout << "All random numbers:";
	while (!NUM.EmptyStack())
	{
		cout << NUM.PopStack() << " ";
	}
	cout << endl << "Even numbers";
	while (!evenNUM.EmptyStack())
	{
		cout << evenNUM.PopStack() << " ";
	}
	cout << endl << "Odd numbers:";
	while (!oddNUM.EmptyStack())
	{
		cout << oddNUM.PopStack() << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
/*All random numbers:13 65 35 30 53 97 91 65 38 10
Even numbers30 38 10
Odd numbers:13 65 35 53 97 91 65
Press any key to continue . . .*/