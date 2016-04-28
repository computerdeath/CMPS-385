//-----------------------------------------------------------------
// Name: Joshua Serrano
// Course: CMPS 385
// Project 2 Part 2
// Due 8/31/2015
// Professor Dr. Ahmadnia
// Purpose: Use objects to display a set of arrays and sorted arrays
//-------------------------------------------------------------------
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
	string day[5] = { "monday","Tue","Wednesday","Thursday","Friday" };
	char days[5][10] = { "Monday","Tuesday","wednesday","Thu","Friday" };
	cout << "Array day:";
	for (int i = 0; i < 5; i++)
		cout << day[i] << "	";
	cout << endl;
	cout << "Array days:";
	for (int j = 0; j < 5; j++)
	{
		for (int g = 0; g < 10; g++)
			cout << days[j][g];
		cout << "  ";
	}
	cout << endl;
	days[2][0] = toupper(days[2][0]);
	//uppercase monday
	day[0][0] = toupper(day[0][0]);
	//output day
	cout << "From array day:" << day[0] << endl;
	
	//output days
	cout << "From array days:";
	for (int g = 0; g < 10; g++)
	{
		cout << days[2][g];
	}
	cout << endl;
	//length
	cout << "The length of " << day[1] << " is " << day[1].length() << " and the length of Tuesday is " << strlen(days[1]) << endl;
	system("pause");
	return 0;
}
/*Array day:monday        Tue     Wednesday       Thursday        Friday
Array days:Monday      Tuesday     wednesday   Thu         Friday
From array day:Monday
From array days:Wednesday
The length of Tue is 3 and the length of Tuesday is 7
Press any key to continue . . .*/