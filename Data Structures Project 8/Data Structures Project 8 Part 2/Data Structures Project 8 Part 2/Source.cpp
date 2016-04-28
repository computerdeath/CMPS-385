#include <iostream>
#include <string>
using namespace std;
class Set
{
private: struct MONTH
{
	string name;
	int days;
	MONTH*next;
}; MONTH*Hashtable[4];
MONTH month[12] = { { "Jan",31 },{ "Feb",28 },{ "Mar",31 },{ "Apr",30 },{ "May",31 },{ "June",30 },{ "July",31 },{ "Aug",31 },{ "Sep",30 },{ "Oct",31 },{ "Nov",30 },{ "Dec",31 } };
public: 
		void InitializeHash()
		{
			for (int i = 0; i < 4; i++)
			{
				Hashtable[i] = NULL;
			}
		}
		int HashMonth(int x)
		{
			MONTH Hashm = month[x];
			int place;
			place = (Hashm.name[0] + Hashm.name[1] + Hashm.name[2]) % 4;
			//cout << "Place:" << place << endl;
			return place;

		}
		void insertInto(int x)
		{
			MONTH Hashm = month[x]; MONTH*temp;
			int i = HashMonth(x);
			temp = new(MONTH);
			temp->name = Hashm.name;
			temp->days = Hashm.days;
			if (Hashtable[i] == NULL)
			{
				Hashtable[i] = temp;
				Hashtable[i]->next = NULL;
			}
			else
			{
				temp->next = Hashtable[i];
				Hashtable[i] = temp;
			}
		}
		void DisplayHash()
		{
			MONTH*HashDis; 
			for (int i = 0; i < 4; i++)
			{
				HashDis = Hashtable[i];
				//cout << i << endl;
				while (HashDis->next != NULL)
				{
					cout << HashDis->name << " " << HashDis->days << " ";
					HashDis = HashDis->next;
				}
				cout << HashDis->name << " " << HashDis->days << " ";
				cout << endl;
			}
		}
		void searchDays(string monthName)
		{
			MONTH*HashLocation;
			int place;
			place = (monthName[0] + monthName[1] + monthName[2]) % 4;
			monthName[0] = toupper(monthName[0]); monthName[1] = tolower(monthName[1]); monthName[2] = tolower(monthName[2]);
			HashLocation = Hashtable[place];
			while (HashLocation->name != monthName)
			{
				if (HashLocation->next == NULL)
					break;
				HashLocation = HashLocation->next;
				
			}
			cout << "The number of days in " << HashLocation->name << " is:" << HashLocation->days << endl;
		}
};
int main()
{
	Set A;
	string monthInput;
	//A.InitializeMonth();
	A.InitializeHash();
	for (int i = 0; i < 12; i++)
	{
		A.insertInto(i);
	}
	cout << "Hash Table" << endl;
	A.DisplayHash();
	cout << "---------------------------------" << endl;
	cout<< "Enter the 3 letter abbreviation of the month:";
	cin >> monthInput;
	A.searchDays(monthInput);
	system("pause");
	return 0;
}
/*Hash Table
Dec 31 Sep 30 Mar 31
Aug 31 June 30 Feb 28 Jan 31
Oct 31
Nov 30 July 31 May 31 Apr 30
---------------------------------
Enter the 3 letter abbreviation of the month:oct
The number of days in Oct is:31
Press any key to continue . . .*/