//-----------------------------------------------------------------
// Name: Joshua Serrano
// Course: CMPS 385
// Project 4 Part 2
// Due 10/4/2015
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

		int length; char num[20]; int count = 0; int calculation; int num1; int num2; int place;
		cout << "Enter a postfix expression:";
		cin.getline(num, 20);
		length = strlen(num);
		STACK <int, 20> loadNum;
		loadNum.ClearStack();
		//load stacks
		while (count < length)
		{
			calculation = 0;
			if (isdigit(num[count]))
			{
				place = atoi(&num[count]);
				loadNum.PushStack(place);

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
			count++;
		}
		cout << "Value:" << loadNum.PopStack() << endl;
		cout << "Continue y/n:";  cin >> con; cin.ignore();
	} while (con != 'n');

	system("pause");
	return 0;

}
/*Enter a postfix expression:7 4 9 4 + + * 5 +
Value:124
Continue y/n:y
Enter a postfix expression:7 8 9 4 + + * 5 +
Value:152
Continue y/n:n
Press any key to continue . . .*/