//Joshua Serrano
//Data Structures Project 8 Part 1
#include<iostream>
#include<time.h>
using namespace std;
class List
{
private:struct NODE
{
	int data;
	NODE*next;
	NODE*back;
}; NODE*top; NODE*end;
public:void ClearList()
{
	top = NULL; end = NULL;
}
	   void PushList(int x)
	   {
		   NODE*temp = new(NODE); NODE*p = top;
		   temp->data = x;
		   temp->next = top;
		   top = temp;
	   }
	   void ListDisplay()
	   {
		   NODE*p = top;
		   while (p->next != NULL)
		   {
			   cout << p->data << ' ';
			   p = p->next;
		   }
		   cout << p->data << ' ';
		   cout << endl;
	   }
	   void Convert2Circular()
	   {
		   NODE*p = top; NODE*a = end;
		   while (p->next != NULL)
		   {
			   p = p->next;
		   }
		   end = p;
		   p->next = top;
		   //p->next = end;
		   //cout << "End:" << end->data << endl;
	   }
	   void DisplayThree()
	   {
		   NODE*p = top; NODE*q = end;
		   int counter = 0;
		   while (counter != 3)
		   {
			   cout << p->data << ' ';
			   p = p->next;
			   if (p->data == top->data)
			   {
				   counter++; cout << "||";
			   }
		   }
		   cout << endl;
	   }
};
int main()
{
	srand(time(NULL));
	List Alpha;
	Alpha.ClearList();
	int RandomNumber;
	for (int i = 0; i < 10; i++)
	{
		RandomNumber = rand() % 50;
		Alpha.PushList(RandomNumber);
	}
	Alpha.ListDisplay();
	Alpha.Convert2Circular();
	cout << "Display 3 times after converting to circular linked list" << endl;
	Alpha.DisplayThree();
	system("pause");
	return 0;

}
/*32 29 16 19 30 22 18 10 30 31
Display 3 times after converting to circular linked list
32 29 16 19 30 22 18 10 30 31 ||32 29 16 19 30 22 18 10 30 31 ||32 29 16 19 30 2
2 18 10 30 31 ||
Press any key to continue . . .*/