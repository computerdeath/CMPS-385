//Joshua Serrano Project 11 part 1
#include <iostream>
#include <string>	
#include <iomanip>
#include <fstream>
using namespace std;
struct month
{
	string monthName;
	int days;
};
class BST
{
private:struct NODE
{
	month info;
	NODE*left;
	NODE*right;
}; NODE*root;  int twochild = 0; int nochild = 0; int onechild = 0;
public:BST() { root = NULL; }
	   void insertBST(month x, NODE*&p)
	   {
		   if (p == NULL)
		   {
			   p = new(NODE);
			   p->info.monthName = x.monthName;
			   p->info.days = x.days;
			   p->left = NULL;
			   p->right = NULL;
		   }
		   else if (x.monthName > p->info.monthName)
		   {
			   insertBST(x, p->right);
		   }
		   else
		   {
			   insertBST(x, p->left);
		   }
	   }
	   void displayBST(NODE*p)
	   {
		  
		   if (p != NULL)
		   {
			   // cout << "Left" << endl;
			   displayBST(p->left);
			   cout << p->info.monthName << " \t" << p->info.days << endl;
			   // cout << "Right" << endl;
			   displayBST(p->right);
			   if (p->left != NULL&&p->right == NULL)
			   {
				   onechild++;
			   }
			   if (p->left == NULL&&p->right != NULL)
			   {
				   onechild++;
			   }
			   if (p->left == NULL&&p->right == NULL)
			   {
				   nochild++;
			   }
			   if (p->left != NULL&&p->right != NULL)
			   {
				   twochild++;
			   }
		   }
	   }
	   void displayBST()
	   {
		   displayBST(root);
	   }
	   void insertBST(month x)
	   {
		   insertBST(x, root);
	   }
	   void displayall()
	   {
			cout << "Nodes that have two children:" << twochild << endl;
			cout << "Nodes that have no children:" << nochild << endl;
			cout<<"Nodes that have only one child:"<< onechild << endl;
	   }
	   void searchBST(NODE*p, string monthname)
	   {
		   while (p != NULL)
		   {
			   if (monthname == p->info.monthName)
			   {
				   cout << p->info.monthName << '\t' << p->info.days << endl;
				   p = NULL;
				   break;
			   }

			   else
			   {
				   if (monthname > p->info.monthName)
				   {
					   p = p->right;
				   }
				   else if (monthname < p->info.monthName)
				   {
					   p = p->left;
				   }
			   }
		   }

	   }
	   void searchBST(string monthname)
	   {
		   searchBST(root, monthname);
	   }
};
int main()
{
	BST m;
	month a;
	fstream f;
	string searchmonth;
	f.open("data.txt", ios::in);
	while (!f.eof())
	{
		f >> a.monthName >> a.days;
		m.insertBST(a);
	}
	m.displayBST();
	m.displayall();
	cout << "Enter name of month to see how many days:";
	cin >> searchmonth;
	m.searchBST(searchmonth);
	system("pause");
	return 0;
}
/*April   30
August  31
December        31
February        28
January         31
July			31
June			30
March			31
May				31
November        30
October         31
September       30
Nodes that have two children:2
Nodes that have no children:3
Nodes that have only one child:7
Enter name of month to see how many days:May
May     31
Press any key to continue . . .*/