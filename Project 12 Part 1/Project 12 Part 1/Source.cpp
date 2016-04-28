//Joshua Serrano
//Project 12 part 1
#include <iostream>
#include <iomanip>
using namespace std;
class FRACTION
{
private: int n, d;
public: void getFRAC()
{
	cout << "Enter a fraction:";
	cin >> n; cin.ignore(); cin >> d;
}
	void displayFRAC()
	{
		cout << n << '/' << d << endl;
	}
	friend FRACTION operator-(FRACTION f1, FRACTION f2)
	{
		FRACTION a;
		a.d = f1.d*f2.d;
		a.n = f1.n - f2.n;
		return a;
	}
	friend FRACTION operator+(FRACTION f1, FRACTION f2)
	{
		FRACTION a;
		a.d = f1.d*f2.d;
		a.n = (f1.n*f2.d) + (f2.n*f1.d);
		return a;
	}
	friend FRACTION operator *(FRACTION f1, FRACTION f2)
	{
		FRACTION a;
		a.d = f1.d*f2.d;
		a.n = f1.n*f2.n;
		return a;
	}
	friend FRACTION operator /(FRACTION f1, FRACTION f2)
	{
		FRACTION a;
		a.d = f1.d*f2.n;
		a.n = f1.n*f2.d;
		return a;

	}
	 void  operator++(int)
	{
		//FRACTION a;
		d=d + 1;
		n=n + 1;
		//return a;
	}
	 void  operator--(int)
	{
		//FRACTION a;
		d=d- 1;
		n=n - 1;
		
	}
	 void display(FRACTION a,FRACTION b,char sym)
	 {
		 cout << a.n << '/' << a.d << sym << b.n <<'/'<< b.d << '=';
	 }
	 void display(FRACTION a)
	 {
		 cout << a.n << '/' << a.d <<"++"<< '=';
	 }
};
int main()
{
	FRACTION f1, f2, SubOut, addOut, MulOut, DivOut;
	f1.getFRAC();
	f2.getFRAC();
	addOut = f1 + f2;
	f1.display(f1, f2, '+');
	addOut.displayFRAC();
	SubOut = f1 - f2;
	f1.display(f1, f2, '-');
	SubOut.displayFRAC();
	MulOut = f1*f2;
	f1.display(f1, f2, '*');
	MulOut.displayFRAC();
	DivOut = f1/f2;
	f1.display(f1, f2, '/');
	DivOut.displayFRAC();
	f2.display(f2);
	f2++;
	f2.displayFRAC();
	f1.display(f1);
	 f1--;
	 f1.displayFRAC();
	system("pause");
	return 0;
}
/*Enter a fraction:4/5
Enter a fraction:6/7
4/5+6/7=58/35
4/5-6/7=-2/35
4/5*6/7=24/35
4/5/6/7=28/30
6/7++=7/8
4/5++=3/4
Press any key to continue . . .*/