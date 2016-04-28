//-----------------------------------------------------------------
// Name: Joshua Serrano
// Course: CMPS 385
// Project 4 Part 3
// Due 10/3/2015
// Professor Dr. Ahmadnia
// Purpose: Use stacks to check for palindrome
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
		char palindrome[50]; int length; bool isPlaindrone = true; int count = 0; char hold1, hold2;
		STACK <char, 50> p; STACK <char, 50> flipIn; STACK <char, 50> flipOut;
		cout << "Enter a sentence:";
		cin.getline(palindrome, 50);
		length = strlen(palindrome);
		p.ClearStack(); flipIn.ClearStack(); flipOut.ClearStack();
		while (count < length)
		{
			p.PushStack(palindrome[count]);
			flipIn.PushStack(palindrome[count]);
			count++;
		}
		//flip
		while (!flipIn.EmptyStack())
		{
			flipOut.PushStack(flipIn.PopStack());
		}
		//check
		while (!flipOut.EmptyStack())
		{
			hold1 = p.PopStack();
			hold2 = flipOut.PopStack();
			if (hold1 == '?' || hold1 == '!')
			{
				 break;
			}
			if (hold1 == ',')
			{
				 hold1 = p.PopStack();
			}
			if (hold2 == ',')
			{
				 hold2 = flipOut.PopStack();
			}
			if (!isalpha(hold1))
			{
				hold1 = p.PopStack();
			}
			if (!isalpha(hold2))
			{
				hold2 = flipOut.PopStack();
			}
			if (isspace(hold1))
			{
				hold1 = p.PopStack(); 
			}
			if (isspace(hold2))
			{
				hold2 = flipOut.PopStack(); 
			}
			hold1 = tolower(hold1);
			hold2 = tolower(hold2);
			if (hold1 != hold2)
			{
				isPlaindrone = false; 
			}
			
		}
		if (isPlaindrone == true)
			cout << "The sentence is a palindrome" << endl;
		else
			cout << "The sentence is not a palindrome" << endl;
		//continue 
		cout << "Countinue? y/n:";
		cin >> con; tolower(con); cin.ignore();
	} while (con != 'n');
	system("pause");
	return 0;
}
/*Enter a sentence:Too bad, I hid a boot
The sentence is a palindrome
Countinue? y/n:y
Enter a sentence:Do Geese see God?
The sentence is a palindrome
Countinue? y/n:n
Press any key to continue . . .*/