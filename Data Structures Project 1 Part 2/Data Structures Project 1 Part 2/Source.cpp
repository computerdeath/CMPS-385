//?????????????????????????????????????????????????????????????
// Name: Joshua Serrano
// Course: CMPS 385
// Project 1 Part 2
// Due 9/13/2015
// Professor Dr. Ahmadnia
// Purpose: create a program that uses a templace show function and uses sort functions to order arrays.
//???????????????????????????????????????????????????????
#include <iostream>
#include <algorithm> 
#include <string>
using namespace std;
template < class T >
void show(T a,int b)
{	
	cout << "array:";
	for (int i = 0; i < b; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
}
template <class A,class D>
void sort(A &x, D b)
{
		sort(x,x+b);
}
void strings2Upper(string a[], int b)
{
	string store;
	for (int i = 0;i < b;i++)
	{
		store = a[i];
		for (int j = 0;j <store.length();j++)
			store[j] = toupper(store[j]);
		a[i] = store;
	}
}
void char2Upper(char a[], int b)
{
	for (int i=0;i < b;i++)
	{
		a[i] = toupper(a[i]);
	}
}
int main()
{
	int a[5] = { 9,7,1,8,6 };
	string s[3] = { "Winners","Never","Quit"};
	char c[5] = { 'e','o','u','a','i' };
	cout << "Orginal ";
	show(a, 5);
	cout << "Orginal ";
	show(s, 3);
	cout << "Orginal ";
	show(c, 5);
	sort(a, 5);
	sort(s, 3);
	sort(c, 5);
	strings2Upper(s,3);
	char2Upper(c, 5);
	cout << endl;
	cout << "Sorted ";
	show(a, 5);
	cout << "Sorted ";
	show(s, 3);
	cout << "Sorted ";
	show(c, 5);
	system("pause");
	return 0;
}
/*Orginal array:9 7 1 8 6
Orginal array:Winners Never Quit
Orginal array:e o u a i

Sorted array:1 6 7 8 9
Sorted array:NEVER QUIT WINNERS
Sorted array:A E I O U
Press any key to continue . . .*/