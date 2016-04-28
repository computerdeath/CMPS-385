//-----------------------------------------------------------------
// Name: Joshua Serrano
// Course: CMPS 385
// Project 3 Part 1
// Due 9/26/2015
// Professor Dr. Ahmadnia
// Purpose: Use stacks to change the bases of numbers
//-------------------------------------------------------------------
#include <iostream>
using namespace std;
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
	STACKint j;
	int i;
	int position = 1;
	j.ClearStack();
	cout << "Enter a positive inerger number:";
	cin >> i;
	int num1 = i, num2 = i, num3 = i;
	cout << i << " at base 2 is ";
	while (num1 != 0)
	{
		int a = num1 % 2;
		j.PushStack(a);
		num1 = num1 / 2;
	} 
	while (!j.EmptyStack())
	{

		cout << j.PopStack();
		position++;

	} j.ClearStack(); cout << endl << i << " at base 8 is:";
	while (num2 != 0)
	{
		int a = num2 % 8;
		j.PushStack(a);
		num2 = num2 / 8;
	} 
	while (!j.EmptyStack())
	{

		cout << j.PopStack();
		position++;

	} j.ClearStack(); cout << endl << i << " at base 16 is:";
	while (num3 != 0)
	{
		int a = num3 % 16;
		j.PushStack(a);
		num3 = num3 / 16;
	}
	while (!j.EmptyStack())
	{

		cout<<std::hex<<j.PopStack();
		position++;
	
	}
	cout << endl;
	system("pause");
	return 0;
}
/*Enter a positive inerger number:163
163 at base 2 is 10100011
163 at base 8 is:243
163 at base 16 is:a3
Press any key to continue . . .*/