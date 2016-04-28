#include <iostream>
#include <fstream>
#include <string>
#include<iomanip>
using namespace std;
struct RECORD
{
	int ID;
	char name[50];
	float BALANCE;
};
void DisplayRAF(string fname)
{
	RECORD r;
	fstream fraf;
	cout << fixed << showpoint << setprecision(2);
	fraf.open(fname, ios::in || ios::binary);
	for (int i = 1; i <10; i++)
	{
		fraf.read((char*)&r, sizeof(RECORD));
		if(r.ID!=0)
			cout << r.ID << '\t' <<r.name<<'\t'<< r.BALANCE << endl;
	}
	fraf.close();
}
void CopyText2RAF(string ftextName, string RAFName)
{
	fstream txt, fraf;
	txt.open(ftextName, ios::in);
	fraf.open(RAFName, ios::out | ios::binary);
	RECORD r;
	txt >> r.ID >>r.name>> r.BALANCE;
	while (!txt.eof())
	{
		int byteoffset = (r.ID / 10 - 1)*sizeof(RECORD);
		fraf.seekp(byteoffset, ios::beg);
		fraf.write((char*)&r, sizeof(RECORD));
		txt >> r.ID >>r.name>> r.BALANCE;
	}
	txt.close(); fraf.close();
}
void Deposit(string rafName, RECORD r)
{
	fstream fraf;
	RECORD temp;
	fraf.open(rafName, ios::in | ios::out | ios::binary);
	int byteoffset = (r.ID / 10 - 1)*sizeof(RECORD);
	fraf.seekg(byteoffset, ios::beg);
	fraf.read((char*)&temp, sizeof(RECORD));
	temp.BALANCE += r.BALANCE;
	fraf.seekp(byteoffset, ios::beg);
	fraf.write((char*)&temp, sizeof(RECORD));
	fraf.close();
}
void CopyRaf2Text(string rafName, string textName)
{
	fstream raf, txt;
	raf.open(rafName, ios::in | ios::binary);
	txt.open(textName, ios::out);
	RECORD r;
	raf.read((char*)&r, sizeof(RECORD));
	while (!raf.eof())
	{
		if (r.ID != 0)
			txt << r.ID << '\t' <<r.name<<'\t'<< r.BALANCE << endl;
		raf.read((char*)&r, sizeof(RECORD));
	}
	txt.close(); raf.close();
}
void findID(string rafName, int x)
{
	fstream fraf; int byteoffset;
	RECORD temp;
	fraf.open(rafName, ios::in | ios::out | ios::binary);
	byteoffset = (x / 10 - 1)*sizeof(RECORD);
	fraf.seekp(byteoffset, ios::beg);
	fraf.read((char*)&temp, sizeof(RECORD));
	cout << temp.ID << '\t' << temp.name << '\t' << temp.BALANCE << endl;
	fraf.close();
}
void Withdraw(string rafName, RECORD r)
{
	fstream fraf;
	RECORD temp;
	fraf.open(rafName, ios::in | ios::out | ios::binary);
	int byteoffset = (r.ID / 10 - 1)*sizeof(RECORD);
	fraf.seekg(byteoffset, ios::beg);
	fraf.read((char*)&temp, sizeof(RECORD));
	temp.BALANCE -= r.BALANCE;
	fraf.seekp(byteoffset, ios::beg);
	fraf.write((char*)&temp, sizeof(RECORD));
	fraf.close();
}
void CloseAccount(string rafName, int x)
{
	fstream fraf;
	RECORD temp;
	fraf.open(rafName, ios::in | ios::out | ios::binary);
	int byteoffset = (x / 10 - 1)*sizeof(RECORD);
	fraf.seekg(byteoffset, ios::beg);
	fraf.read((char*)&temp, sizeof(RECORD));
	temp.BALANCE = 0;
	temp.ID = 0;
	fraf.seekp(byteoffset, ios::beg);
	fraf.write((char*)&temp, sizeof(RECORD));
	fraf.close();
}
RECORD dummy = { 0,"bbbb",0.0 };
int main()
{
	//intilizae RAF
	fstream fraf; int selection; bool con = true;
	fraf.open("data.raf", ios::out | ios::binary);
	for (int i = 1; i <=10; i++)
	{
		fraf.write((char *)&dummy, sizeof(RECORD));
	}
	fraf.close();
	CopyText2RAF("Text.txt", "data.raf");
	cout << "------------Bank of America----------" << endl;
	cout << "1.Display all records from the RAF\n2.Display a record when ID is given\n3.Deposit in an account with a given ID\n";
	cout << "4.Withdraw from an account with a given ID\n5.Close an account for a given ID\n6.Exit and copy the rAF into a text file\n";
	while (con == true)
	{
		selection = NULL;	
		cout << "Enter your selection:";
		cin >> selection;
		RECORD temp;
		if(selection== 1) DisplayRAF("data.raf");
		if (selection==2) { int ID; cout << "Enter ID for display:"; cin >> ID; findID("data.raf", ID); }
		if(selection==3) { cout << "Enter ID for account deposit:"; cin >> temp.ID; cout << "Enter amount for deposit:"; cin >> temp.BALANCE; Deposit("data.raf", temp); }
		if (selection == 4) { cout << "Enter ID for widthdraw:"; cin >> temp.ID; cout << "Enter amount to widthdraw:"; cin >> temp.BALANCE; Withdraw("data.raf", temp); }
		if (selection == 5) { int ID; cout << "Enter ID to close account:"; cin >> ID; CloseAccount("data.raf", ID); }
		if (selection == 6) { CopyRaf2Text("data.raf", "Text1.txt"); con == false; break; }
		cin.ignore();
	}

	system("pause");
	return 0;
}
/*------------Bank of America----------
1.Display all records from the RAF
2.Display a record when ID is given
3.Deposit in an account with a given ID
4.Withdraw from an account with a given ID
5.Close an account for a given ID
6.Exit and copy the rAF into a text file
Enter your selection:1
10      Nixon,Kathy     100.10
20      Regan,Ron       200.20
30      Clinton,Bill    300.30
40      Bush,Barbra     400.40
50      Carter,Jimmy    500.50
60      Bush,George     600.60
90      Obama,Barack    900.90
Enter your selection:2
Enter ID for display:50
50      Carter,Jimmy    500.50
Enter your selection:3
Enter ID for account deposit:20
Enter amount for deposit:100
Enter your selection:4
Enter ID for widthdraw:50
Enter amount to widthdraw:100
Enter your selection:1
10      Nixon,Kathy     100.10
20      Regan,Ron       300.20
30      Clinton,Bill    300.30
40      Bush,Barbra     400.40
50      Carter,Jimmy    400.50
60      Bush,George     600.60
90      Obama,Barack    900.90
Enter your selection:5
Enter ID to close account:20
Enter your selection:1
10      Nixon,Kathy     100.10
30      Clinton,Bill    300.30
40      Bush,Barbra     400.40
50      Carter,Jimmy    400.50
60      Bush,George     600.60
90      Obama,Barack    900.90
Enter your selection:6
Press any key to continue . . .
Text File
10	Nixon,Kathy	100.1
30	Clinton,Bill	300.3
40	Bush,Barbra	400.4
50	Carter,Jimmy	400.5
60	Bush,George	600.6
90	Obama,Barack	900.9
*/