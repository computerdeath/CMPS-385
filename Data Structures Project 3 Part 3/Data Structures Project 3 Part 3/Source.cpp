//-----------------------------------------------------------------
// Name: Joshua Serrano
// Course: CMPS 385
// Project 3 Part 3
// Due 9/26/2015
// Professor Dr. Ahmadnia
// Purpose: Use stacks seperate letters and words
//-------------------------------------------------------------------
#include <iostream>
#include <random>
#include <string>
#include <cstring>
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
int main()
{
	CHARstack lowercase;
	CHARstack uppercase;
	CHARstack vowels;
	char f[50];
	int count;
	cout << "Enter a sentence:";
	cin.getline(f, 50);
	count= strlen(f);
	lowercase.ClearStack(); uppercase.ClearStack(); vowels.ClearStack();
	while (count>=0)
	{
		if (islower(f[count]))
		{
			lowercase.PushStack(f[count]);
		}
		if (isupper(f[count]))
			uppercase.PushStack(f[count]);
		if (f[count] == 'a' || f[count] == 'e' || f[count] == 'i' || f[count] == 'o' || f[count] == 'u')
			vowels.PushStack(f[count]);

		count--;
	}
	cout << "Uppercase letters:";
	while (!uppercase.EmptyStack())
	{
		char letter;
		letter=uppercase.PopStack();
		cout << letter;
	}cout << endl << "Lowercase letters:";
	while (!lowercase.EmptyStack())
	{
		char letter;
		letter=lowercase.PopStack();
		cout << letter;
	}cout << endl << "Vowels:";
	while (!vowels.EmptyStack())
	{
		char letter;
		letter=vowels.PopStack();
		cout << letter;
	}
	cout << endl;
	system("pause");
	return 0;
}
/*Enter a sentence:Today Is Monday
Uppercase letters:TIM
Lowercase letters:odaysonday
Vowels:oaoa
Press any key to continue . . .*/