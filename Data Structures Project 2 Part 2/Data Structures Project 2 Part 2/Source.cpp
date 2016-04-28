//-----------------------------------------------------------------
// Name: Joshua Serrano
// Course: CMPS 385
// Project 2 Part 2
// Date 9/20/2015
// Professor Dr. Ahmadnia
// Purpose: Recursive Functions
//-------------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <cmath>
#include <time.h>
using namespace std;
int sum(int n, int m)
{
	if (n == m)
		return m;
	else
		return n + sum(n + 1, m);
}
int g(int n)
{
	if (n <= 3)
		return 2;
	else
		return n + g(n - 1) + g(n - 2);
}
int f(int n)
{
	if (n == 2)
		return pow(3,2);
	else
		return pow(3,n)+ f(n - 1);
}
int main()
{
	clock_t t;
	
	cout << sum(3,8) << endl;
	t = clock();
	cout << g(41) << endl;
	t = clock() - t;
	double time_run = ((double)t) / CLOCKS_PER_SEC;
	cout << "Seconds to execute " << time_run << endl;
	cout << f(10) << endl;
	system("pause");
	return 0;
}
/*33
779585027
Seconds to execute 3.985
88569
Press any key to continue . . .*/