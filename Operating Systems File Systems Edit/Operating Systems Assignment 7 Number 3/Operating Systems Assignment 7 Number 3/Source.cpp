//Joshua Serrano
//Homework 7
//CMPS 460
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	char con;
	do 
	{
		int F1, T1, T2, T3, T4, n = 0; char select; int size, x, mini, count, firstrun = 0, mode;
		cout << "--------PFD Menu---------" << endl << "a.PFD of order 3" << endl << "b.PFD of order 4" << endl;
		cout << "Enter file size:";
		cin >> size;
		cout << "Enter selection:";
		cin >> select;
		if (tolower(select) == 'a')
			mode = 1;
		else
			mode = 2;
		//PFD 3
		F1 = size;
		//determiniie value

		if (mode == 1)
		{
			while (((n + 3) + (n + 2) + n) != size)
			{
				n++;
			}
			T1 = n + 3; T2 = n + 2; T3 = n;
			F1 = T3;
		}
		else
		{
			while (((n + 4) + (n + 3) + (n + 2) + n) != size)
			{
				n++;
			}
			T1 = n + 4; T2 = n + 3; T3 = n + 2; T4 = n;
			F1 = T4;
		}
		cout << "F1\t T1\t T2 \t T3\t"; if (mode == 2) cout << "T4 \n"; else cout << '\n';
		cout << "--------------------------- \n";
		cout << size << "\t -- \t -- \t --\t"; if (mode == 2) cout << "--\n"; else cout << '\n';
		cout << "--\t" << T1 << '\t' << T2 << '\t' << T3 << '\t'; if (mode == 2) cout << T4 << '\n'; else cout << '\n';
		while (F1 != NULL)
		{
			if (T1 != NULL&& T2 != NULL)
				mini = min(T1, T2);
			if (T2 != NULL && T3 != NULL && (min(T2, T3) < mini))
				mini = min(T2, T3);
			if (T1 != NULL&& T3 != NULL && (min(T1, T2) < mini))
				mini = min(T1, T3);
			if (mode == 2)
			{
				if (T1 != NULL&&T4 != NULL && (min(T1, T2) < mini))
					mini = min(T1, T4);
				if (T2 != NULL&&T4 != NULL && (min(T2, T3) < mini))
					mini = min(T2, T4);
				if (T3 != NULL&&T4 != NULL&& T4 < mini)
					mini = min(T3, T4);
			}
			//cout << mini <<"mini"<< endl;
			//Set F1 as minius mini
			if (firstrun != 0)
				F1 = F1 - mini;
			if (F1 <= 0)
				F1 = NULL;
			//subtract all values by mini
			T1 = T1 - mini;
			T2 = T2 - mini;
			T3 = T3 - mini;
			if (T1 < 0)
				T1 = mini;
			if (T2 < 0)
				T2 = mini;
			if (T3 < 0)
				T3 = mini;
			//output numbers
			if (F1 == NULL)
				cout << "-- \t";
			else
				cout << F1 << '\t';
			if (T1 == NULL)
				cout << "-- \t";
			else
				cout << T1 << '\t';
			if (T2 == NULL)
				cout << "-- \t";
			else
				cout << T2 << '\t';
			if (mode == 1)
			{
				if (T3 == NULL)
					cout << "-- \n";
				else
					cout << T3 << '\n';
			}
			if (mode == 2)
			{
				T4 = T4 - mini;
				if (T4 < 0)
					T4 = mini;
				if (T3 == NULL)
					cout << "-- \t";
				else
					cout << T3 << '\t';
				if (T4 == NULL)
					cout << "-- \n";
				else
					cout << T3 << '\n';
			}

			firstrun++;
		}
		cout << '\n';
		cin.ignore();
		cout << "Continue? y/n:";
		cin >> con;
	}while (tolower(con) == 'y');
	system("pause");
	return 0;
}/*--------PFD Menu---------
a.PFD of order 3
b.PFD of order 4
Enter file size:17
Enter selection:a
F1       T1      T2      T3
---------------------------
17       --      --      --
--      7       6       4
4       3       2       --
2       1       --      2
1       --      1       1
--      1       --      --

Continue? y/n:y
--------PFD Menu---------
a.PFD of order 3
b.PFD of order 4
Enter file size:25
Enter selection:b
F1       T1      T2      T3     T4
---------------------------
25       --      --      --     --
--      8       7       6       4
4       4       3       2       --
2       2       1       --      0
1       1       --      1       1
--      --      1       --      --

Continue? y/n:n
Press any key to continue . . .*/