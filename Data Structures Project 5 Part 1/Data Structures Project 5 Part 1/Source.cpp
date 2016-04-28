//-----------------------------------------------------------------
// Name: Joshua Serrano
// Course: CMPS 385
// Project 5 Part 1
// Due 10/9/2015
// Professor Dr. Ahmadnia
// Purpose: Use stacks to calculate posfix
//-------------------------------------------------------------------
#include "STACKPAC.h"
#include <iostream>
#include <string>
using namespace std;
int main()
{
	char con;
	do
	{
		int length; string num; int count = 0; int calculation; int num1; int num2; int place; string tempString; string tempNum; int tempInt;
		cout << "Enter a postfix expression:";
		std::getline(std::cin, num);
		STACK <int, 20> loadNum;
		loadNum.ClearStack();
		//load stacks
	NumCheck: while (num[count] != '$')
	{
		calculation = 0; tempNum = ""; tempInt = 0;
		if (isdigit(num[count]))
		{
			while (!isspace(num[count]))
			{
				tempNum += num[count];
				count++;
			}
			tempInt = atoi(tempNum.c_str());
			loadNum.PushStack(tempInt);

		}
		if (num[count] == '*' || num[count] == '+' || num[count] == '-' || num[count] == '/')
		{
			num1 = loadNum.PopStack(); num2 = loadNum.PopStack();
			if (num[count] == '-')
			{
				calculation = num2 - num1;
				loadNum.PushStack(calculation);
			}
			if (num[count] == '+')
			{
				calculation = num2 + num1;
				loadNum.PushStack(calculation);
			}
			if (num[count] == '/')
			{
				calculation = num2 / num1;
				loadNum.PushStack(calculation);
			}
			if (num[count] == '*')
			{
				calculation = num2*num1;
				loadNum.PushStack(calculation);
			}
		}
		if (isalpha(num[count]))
		{
			int stringCount = 0; tempString = "";
			while (!isspace(num[count]))
			{
				if (num[count] == '$')
				{
					goto NumCheck;
				}
				tempString += num[count];
				stringCount++; count++; 
			}
			int temp;
			cout << "Enter the value of " << tempString << ":";
			cin >> temp; 
			loadNum.PushStack(temp);
		}
		count++;
	}
			  cout << "Final Value:" << loadNum.PopStack() << endl;
			  cout << "Continue y/n:";  cin >> con; cin.ignore();
	} while (con != 'n');
	system("pause");
	return 0;
}
/*Enter a postfix expression:tom jerry + 234 + $
Enter the value of tom:10
Enter the value of jerry:5
Final Value:249
Continue y/n:y
Enter a postfix expression:12 xyz 13 bill 14 + + + + $
Enter the value of xyz:6
Enter the value of bill:10
Final Value:55
Continue y/n:n
Press any key to continue . . ..*/