#include <iostream>
#include <fstream>
#include <string>
#include<iomanip>
using namespace std;
struct RECORD
{
	int ID;
	float BALANCE;
};
void DisplayRAF(string fname)
{
	RECORD r;
	fstream fraf;
	cout << fixed << showpoint << setprecision(2);
	fraf.open(fname, ios::in || ios::binary);
	for (int i = 1; i < 10; i++)
	{
		fraf.read((char*)&r, sizeof(RECORD));
		cout << r.ID << '\t' << r.BALANCE << endl;
	}
	fraf.close();
}
void CopyText2RAF(string ftextName, string RAFName)
{
	//open both files
	fstream txt, fraf;
	txt.open(ftextName, ios::in);
	fraf.open(RAFName, ios::out | ios::binary);
	RECORD r;
	txt >> r.ID >> r.BALANCE;//read from text file
	while (!txt.eof())
	{
		int byteoffset = (r.ID / 10 - 1)*sizeof(RECORD);//find the 
		fraf.seekp(byteoffset, ios::beg);//position
		fraf.write((char*)&r, sizeof(RECORD));//copy into RAF
		txt >> r.ID >> r.BALANCE;//read the next record from text file
		//cout << r.ID << r.BALANCE << endl;
	}
	txt.close(); fraf.close();
}
void Deposit(string rafName, RECORD r)
{
	fstream fraf;
	RECORD temp;
	fraf.open(rafName, ios::in | ios::out|ios::binary);
	int byteoffset = (r.ID / 10 - 1)*sizeof(RECORD);
	//point to record to read
	fraf.seekg(byteoffset, ios::beg);
	//read the record
	fraf.read((char*)&temp, sizeof(RECORD));
	//deposit 
	temp.BALANCE += r.BALANCE;
	//write new reord into file
	fraf.seekp(byteoffset, ios::beg);
	fraf.write((char*)&temp, sizeof(RECORD));
	fraf.close();
}
void CopyRaf2Text(string rafName, string textName)
{
	//open both files
	fstream raf, txt;
	raf.open(rafName, ios::in | ios::binary);
	txt.open(textName, ios::out);
	//read from RAF
	RECORD r;
	raf.read((char*)&r,sizeof(RECORD));//read a record from RA
	while (!raf.eof())
	{
		//write in the text file
		if(r.ID!=0)
		txt << r.ID << '\t' << r.BALANCE << endl;
		raf.read((char*)&r, sizeof(RECORD));//read next record from RAD
	}
	txt.close(); raf.close();
}
RECORD dummy = { 0,0.0 };
int main()
{
	//intilizae RAF
	fstream fraf;
	fraf.open("data.raf", ios::out | ios::binary);
	for (int i = 1; i <= 10; i++)
	{
		fraf.write((char *)&dummy, sizeof(RECORD));
	}
	fraf.close();
	cout << "RAF File" << endl;
	//DisplayRAF("data.raf"); cout << endl;
	//copy data from text file into RAF
	CopyText2RAF("Text.txt", "data.raf");
	DisplayRAF("data.raf");
	//deposit money
	int id; float balance;
	RECORD t;
	cout << "Enter your ID to deposit:"; cin >> t.ID;
	cout << "How much would you like to deposit?"; cin >> t.BALANCE;
	Deposit("data.raf", t);
	DisplayRAF("data.raf");
	CopyRaf2Text("data.raf", "Text2.txt");
	system("pause");
	return 0;
}