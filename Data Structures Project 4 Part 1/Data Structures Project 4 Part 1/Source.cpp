//-----------------------------------------------------------------
// Name: Joshua Serrano
// Course: CMPS 385
// Project 4 Part 1
// Due 10/4/2015
// Professor Dr. Ahmadnia
// Purpose: Use stacks to flip months and numbers
//-------------------------------------------------------------------
#include <iostream>
#include <string>
#include "STACKPAC.h"
using namespace std;
int main()
{
	int a[7] = { 5,9,7,6,2,3,2 };
	char c[5] = { 'e','o','a','i','u' };
	string months[12] = { "Jan","Feb","Mar","APR","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
	STACK <int, 7> s;
	STACK <char, 5> j;
	STACK <string, 12> b;
	int count = 0;
	s.ClearStack(); j.ClearStack(); b.ClearStack();

	while (!s.FullStack())
	{
		s.PushStack(a[count]);
		count++;
	}
	count = 0;
	while (!j.FullStack())
	{
		j.PushStack(c[count]);
		count++;
	} count = 0;
	while (!b.FullStack())
	{
		b.PushStack(months[count]);
		count++;
	} 
	count = 0;
	while (!s.EmptyStack())
	{
		cout << s.PopStack() <<'\t';
	}cout << endl;
	while (!b.EmptyStack())
	{
		cout << b.PopStack() <<'\t';
	}cout << endl;
	while (!j.EmptyStack())
	{
		cout << j.PopStack()<<'\t';
	} cout << endl;
	system("pause");
	return 0;
}/*2       3       2       6       7       9       5
Dec     Nov     Oct     Sep     Aug     Jul     Jun     May     APR     Mar
Feb     Jan
u       i       a       o       e
Press any key to continue . . .*/