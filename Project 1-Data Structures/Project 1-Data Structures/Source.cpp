//-----------------------------------------------------------------
// Name: Joshua Serrano
// Course: CMPS 385
// Project 1
// Date 8/31/2015
// Professor Dr. Ahmadnia
// Purpose: Use objects to display a set of arrays and sorted arrays
//-------------------------------------------------------------------
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
struct PERSON
{
	string name;
	int age;
	float gpa;
};

void Copy(string fname, PERSON n[])
{
	fstream f; 
	int i = 0;
	f.open(fname, ios::in);
	while (true)
	{
		f >> n[i].name >> n[i].age >> n[i].gpa;
		i++;
		if (f.fail()) break;
	}
}
void Display(PERSON n[])
{

	for (int i = 0; i<5; i++)
	{
		cout << n[i].name <<"    "<< '\t' << n[i].age << '\t'<< std::setprecision(2)<<fixed << n[i].gpa << endl;
	}
}
void DisplayTeens(PERSON n[])
{
	cout << "The list of teenagers is:";
	for (int i = 0; i < 5; i++)
	{
		if (n[i].age <= 18)
			cout << n[i].name << '\t';
	}
	cout << endl;
}
float gpaAVE(PERSON n[])
{
	float total=0, average=0;
	for (int i = 0; i < 5; i++)
	{
		total+= n[i].gpa;
	}
	average = total / 5;
	return average;
}
float ageAVE(PERSON n[])
{
	float total = 0, average = 0;
	for (int i = 0; i < 5; i++)
	{
		total += n[i].age;
	}
	average = total / 5;
	return average;
}
void Display(float gpaAVE, float ageAVE)
{
	cout << "Their GPA average is:" << std::setprecision(3) << gpaAVE << endl;
	cout << "Their age average is:" << std::setprecision(3) << ageAVE << endl;
}
int main()
{
	PERSON a[5];
	float gpaAverage = 0;
	float ageAverage = 0;
	//copy data from data to array a
	Copy("data.txt", a);
	cout << "Name		Age	GPA" << endl; cout << "----------------------------" << endl;
	Display(a);
	DisplayTeens(a);
	gpaAverage = gpaAVE(a);
	ageAverage = ageAVE(a);
	Display(gpaAverage, ageAverage);
	system("pause");
	return 0;
}
/*Name            Age     GPA
----------------------------
Beatrize        33      3.30
Tresner         44      4.30
Urias           19      2.91
Vincent         17      3.11
Alexander       21      3.20
The list of teenagers is:Vincent
Their GPA average is:3.364
Their age average is:26.800
Press any key to continue . . .*/