//-----------------------------------------------------------------
// Name: Joshua Serrano
// Course: CMPS 385
// Project 3 Part 4
// Due 9/26/2015
// Professor Dr. Ahmadnia
// Purpose: store month, uppercase letters and numbers
//-------------------------------------------------------------------
#include <iostream>
#include <random>
#include <string>
#include <cstring>
#include <time.h>
using namespace std;
class CHARstack
{
private:char j[50];
		int counter;
public: void ClearStack()
{
	counter = 0;
}
		bool FullStack()
		{
			return (counter == 50) ? true : false;
		}
		bool EmptyStack()
		{
			return (counter == 0) ? true : false;
		}
		void PushStack(char x)
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
class STACKint
{
private:int a[20];
		int counter;
public: void ClearStack()
{
	counter = 0;
}
		bool FullStack()
		{
			return (counter == 20) ? true : false;
		}
		bool EmptyStack()
		{
			return (counter == 0) ? true : false;
		}
		void PushStack(int x)
		{
			a[counter] = x;
			counter++;
		}
		int PopStack()
		{
			counter--;
			return a[counter];
		}
};
int main()
{
	STACKint NUM;
	STACKint ALPHA;
	STACKint MONTHS;
	int count=0;
	srand(time(NULL));
	NUM.ClearStack(); ALPHA.ClearStack(); MONTHS.ClearStack();
	while (count < 10)
	{
		int randomNumber = rand() % 29 + 1;
		NUM.PushStack(randomNumber);
		int randomMonth = rand() % 12 + 1;
		MONTHS.PushStack(randomMonth);
		int randomChar = 97 + rand() % 26;
		ALPHA.PushStack(randomChar);
		count++;
	}
	count = 0;
	cout << "Numbers	Uppercase Letters	Months" << endl;
	cout << "--------------------------------------------" << endl;
	while (count < 10)
	{
		cout << NUM.PopStack() << "		";
		char out = toupper(ALPHA.PopStack());
		cout << out << "		";
		string month;
		int monthValue = MONTHS.PopStack();
		if (monthValue == 1) month = "January";
		if (monthValue == 2) month = "Febuary";
		if (monthValue == 3)month = "March";
		if (monthValue == 4) month = "April";
		if (monthValue == 5) month = "May";
		if (monthValue == 6)month = "June";
		if (monthValue == 7) month = "July";
		if (monthValue == 8) month = "August";
		if (monthValue == 9) month = "September";
		if (monthValue == 10) month = "October";
		if (monthValue == 11) month = "November";
		if (monthValue == 12) month = "December";
		cout << month << endl;
		count++;
	}
	
	system("pause");
	return 0;
}
/*Numbers Uppercase Letters       Months
--------------------------------------------
28              Q               October
27              T               August
10              N               Febuary
18              H               December
20              Q               May
26              S               July
10              A               June
29              K               Febuary
3               U               Febuary
20              J               October
Press any key to continue . . .*/