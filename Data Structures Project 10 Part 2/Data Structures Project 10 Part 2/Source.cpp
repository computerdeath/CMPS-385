//Joshua Serrano Project 10 Part 2
#include <iostream>
#include <string>
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
}; NODE*root;bool flag=false;
public:BST() { root = NULL; }
	   void insertBST(month x,NODE*&p)
	   {
		   if (p == NULL)
		   {
			   p = new(NODE);
			   p->info.monthName = x.monthName;
			   p->info.days = x.days;
			   p->left = NULL;
			   p->right = NULL;
		   }
		   else if (x.monthName[0] > p->info.monthName[0])
		   {
			   insertBST(x, p->right);
		   }
		   else 
		   {
			   insertBST( x,p->left);
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
		   }
	   }
	   void displayBST()
	   {
		   displayBST(root);
	   }
	   void insertBST(month x)
	   {
		   insertBST(x,root);
	   }
	   void displayLeaves(NODE*&p)
	   {
		   if (p != NULL)
		   {
			   displayLeaves(p->left);
			   displayLeaves(p->right);
			   if (p->left == NULL && p->right == NULL)
			   {
				   cout << p->info.monthName << ' ' << p->info.days << endl;
			   }
		   }
	   }

	   void displayLeaves()
	   {
		   displayLeaves(root);
	   }
	   void display2child(NODE*p)
	   {
		   
			   if (p != NULL)
			   {
				   display2child(p->left);
				   display2child(p->right);
				   if (p->right == NULL&&p->left != NULL)
				   {
					   cout << p->info.monthName << ' ' << p->info.days << endl;
				   }
			   }
		   
	   }
	   void display2child()
	   {
		   display2child(root);
	   }

};
int main()
{
	BST m;
	month a[12] = { { "January",31 }, { "Febuary",28 }, { "March",31 }, { "April",30 }, { "May",31 }, { "June",30 }, { "July",31 },{"August",31}, { "September",30 }, { "October",31 }, { "November",30 }, { "December",31 } };
	for (int i = 0; i < 12; i++)
	{
		m.insertBST(a[i]);
	}
	m.displayBST();
	cout << endl << "Leaves of tree\n";
	m.displayLeaves();
	cout << endl << "Months with one child\n";
	m.display2child();
	system("pause");
	return 0;
}
/*August  31
April   30
December        31
Febuary         28
July    31
June    30
January         31
May     31
March   31
November        30
October         31
September       30

Leaves of tree
August 31
December 31
July 31
May 31
November 30

Months with one child
June 30
October 31
September 30
Press any key to continue . . .*/