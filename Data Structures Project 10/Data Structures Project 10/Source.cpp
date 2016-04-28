//Joshua Serrano Project 10 Part 1
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>6
using namespace std;
struct person
{
	string name;
	int id;
	double balance;
};
class BST
{
private:struct NODE
{
	person info;
	NODE*left;
	NODE*right;
}; NODE*root;
public:BST() { root = NULL; }
	   void insertBST(person x, NODE*&p)
	   {
		   if (p == NULL)
		   {
			   p = new(NODE);
			   p->info.name = x.name;
			   p->info.id = x.id;
			   p->info.balance = x.balance;
			   p->left = NULL;
			   p->right = NULL;
		   }
		   else if (x.id > p->info.id)
		   {
			   insertBST(x, p->right);
		   }
		   else if (x.id < p->info.id)
		   {
			   insertBST(x, p->left);
		   }
	   }
	   void displayBST(NODE*p)
	   {
		   if (p != NULL)
		   {
			   displayBST(p->left);
			   cout << p->info.name << " \t" << p->info.id << "\t " << std::fixed << setprecision(2 )<< p->info.balance << endl;
			   displayBST(p->right);
		   }
	   }
	   void displayBST()
	   {
		   displayBST(root);
	   }
	   void insertBST(person x)
	   {
		   insertBST(x, root);
	   }
	   void searchBST(NODE*p, int id)
	   {
		   while (p != NULL)
		   {
			   if (id == p->info.id)
			   {
				   cout << p->info.name << '\t' << p->info.id << '\t' << std::fixed << setprecision(2 )<< p->info.balance << endl;
				   p = NULL;
				   break;
			   }

			   else 
			   {
				   if (id > p->info.id)
				   {
					   //return searchBST(p->right, id);
					   p = p->right;
				   }
				   else if (id < p->info.id)
				   {
					  // return searchBST(p->left, id);
					   p = p->left;
				   }
			   }
		   }

	   }
	   void insertBST(NODE*p, int id,double deposit)
	   {
		   while (p != NULL)
		   {
			   if (id == p->info.id)
			   {
				   p->info.balance += deposit;
				   cout << "Your new balance is:" << p->info.balance << endl;
				   p = NULL;
				   break;
			   }

			   else
			   {
				   if (id > p->info.id)
				   {
					   //return searchBST(p->right, id);
					   p = p->right;
				   }
				   else if (id < p->info.id)
				   {
					   // return searchBST(p->left, id);
					   p = p->left;
				   }
			   }
		   }
	   }
	   void insertBST(int id, double deposit)
	   {
		   insertBST(root, id, deposit);
	   }
		   void searchBST(int id)
		   {
			    searchBST(root, id);
		   }
	   
};
int main()
{
	BST t;
	fstream f;
	person a; person search; int selection; char con; int id; int deposit;
	int count = 0;
	f.open("data.txt", ios::in);
	while (! f.eof())
	{
		f >> a.name >> a.id >> a.balance;
		//cout << count << endl;
		count++;
		//cout << a.name << a.id << a.balance << endl;
		t.insertBST(a);
	}
	
	do {
		cout << "1.Display all accounts" << endl << "2.Search by ID number" << endl << "3.Make a deposit" << endl;
		cout << "Enter  your selection:"; cin >> selection;
		if (selection == 1)
		{
			t.displayBST();
		}
		if (selection == 2)
		{
			cout << "Enter a ID number to display:"; cin >> id;
			t.searchBST(id);
		}
		if (selection == 3)
		{
			cout << "Enter ID number:"; cin >> id;
			cout << "Enter amount to deposit:"; cin >> deposit;
			t.insertBST(id, deposit);
		}
		cin.ignore();
		cout << "Continue y/n:"; cin >> con;
	} while (con == 'y');
	f.close();
	system("pause");
	return 0;
}
/*1.Display all accounts
2.Search by ID number
3.Make a deposit
Enter  your selection:1
Beatrize        10       10.10
Emmanuel        20       20.20
Bryan			30       30.30
Vincent         40       40.40
Keith			60       60.60
James			70       70.70
David			80       80.80
Continue y/n:y
1.Display all accounts
2.Search by ID number
3.Make a deposit
Enter  your selection:2
Enter a ID number to display:80
David   80      80.80
Continue y/n:y
1.Display all accounts
2.Search by ID number
3.Make a deposit
Enter  your selection:3
Enter ID number:70
Enter amount to deposit:100
Your new balance is:170.70
Continue y/n:y
1.Display all accounts
2.Search by ID number
3.Make a deposit
Enter  your selection:1
Beatrize        10       10.10
Emmanuel        20       20.20
Bryan			30       30.30
Vincent         40       40.40
Keith			60       60.60
James			70       170.70
David			80       80.80
Continue y/n:n
Press any key to continue...
*/