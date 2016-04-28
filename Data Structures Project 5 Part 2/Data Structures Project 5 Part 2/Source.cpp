//-----------------------------------------------------------------
// Name: Joshua Serrano
// Course: CMPS 385
// Project 5 Part 2
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
	char num[20]; int count = 0; string out; int OperatorCount = 0; int ParenNumCount = 0;
	STACK <char, 20> loadNum; STACK <char, 20> loadOperator; STACK <char, 20> flipStack; STACK <char, 20> FlipOperator;
	cout << "Enter an infix expression:";
	cin.getline(num,20);
	loadNum.ClearStack(); loadOperator.ClearStack(); flipStack.ClearStack(); FlipOperator.ClearStack();
NumCheck: while (num[count] != '$')
{
	if (num[count] == '(')
	{
		 count++;
		while (num[count] != ')')
		{
			
			if (isalpha(num[count]))
			{
				loadNum.PushStack(num[count]);
				count++; ParenNumCount++; 
			}
			else if (num[count] == '*' || num[count] == '+' || num[count] == '-' || num[count] == '/')
			{
				loadOperator.PushStack(num[count]);
				count++; OperatorCount++; 
			}

		}
		count++;
		goto NumCheck;
	}
	if (isalpha(num[count]))
	{
		loadNum.PushStack(num[count]);
		count++; 
		goto NumCheck; 
	}
	if (num[count] == '*' || num[count] == '+' || num[count] == '-' || num[count] == '/')
	{
		loadOperator.PushStack(num[count]);
		count++; 
		OperatorCount++;
	}
	if (num[count] == '$') {  goto NumCheck; }
}
		  

		  //flip
		  while (!loadNum.EmptyStack())
		  {
			  flipStack.PushStack(loadNum.PopStack());
		  }
		  while (!loadOperator.EmptyStack())
		  {
			  FlipOperator.PushStack(loadOperator.PopStack());
		  }
		  count = 0;
		  //output
		  if (ParenNumCount % 2 == 0)
		  {
			  while (!flipStack.EmptyStack())
			  {
				  if (count % 2 == 0)
				  {
					  out += flipStack.PopStack();
					  out += flipStack.PopStack();
					  if (OperatorCount >= 0)
					  {
						  out += FlipOperator.PopStack();
						  OperatorCount--;
					  }
					  count++;
				  }
				  else
				  {
					  out += flipStack.PopStack();
					  if (OperatorCount >= 0)
					  {
						  out += FlipOperator.PopStack();
						  OperatorCount--;
					  }
				  }
			  }

		  }
		  else if (ParenNumCount % 2 != 0)
		  {
			  while (!flipStack.EmptyStack())
			  {
				  out += flipStack.PopStack();
			  }
			  while (!FlipOperator.EmptyStack())
			  {
				  out += FlipOperator.PopStack();
			  }
		  }
		  
		  cout << "Postfix form of the expression is:" << out << endl; cout << "Continue y/n:";  cin >> con; cin.ignore();
	} while (con != 'n');
		  system("pause");
		  return 0;
}
/*Enter an infix expression:(a+b)*c$
Postfix form of the expression is:ab+c*
Continue y/n:y
Enter an infix expression:a*(b-c*d)$
Postfix form of the expression is:abcd*-*
Continue y/n:n
Press any key to continue . . .*/