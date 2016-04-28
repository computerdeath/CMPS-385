//Joshua Serrano
//Project 5 Problems 1-3
#include <iostream>
using namespace std;
class List
{
private:struct NODE {
	int data;
	NODE*next;
};
NODE*top = NULL;
public:void ListClear() {
	top = NULL;
}
	   bool isEmpty() {
		   if (top == NULL) return true; else return false;
	   }
	   void PushList(int x)
	   {
		    NODE*temp=new(NODE);
		   temp->data=x;
		   temp->next = top;
		   top = temp;
	   }
	   void ListDisplay()
	   {
		   NODE*p = top;
		   while (p != NULL)
		   {
			   cout << p->data << ' ';
			   p = p->next;
		   }
		   cout << endl;
	   }
	   int ListCount()
	   {
		   int count = 0;
		   NODE*p = top;
		   while (p != NULL)
		   {
			   count++;
			   p = p->next;
		   }
		   return count;
	   }
	   int ListTotal()
	   {
		   int total=0;
		   NODE*p = top;
		   while (p != NULL)
		   {
			   total += p->data;
			   p = p->next;

		   }
		   return total;
	   }
	  
	   int ListMinimum()
	   {
		   int minimum = 0, temp;
		   NODE*p = top;
		   minimum = p->data;
		   while (p != NULL)
		   {
			   temp = p->data;
			   if(temp<minimum)
				   minimum=temp;
			   p = p->next;
		   }
		   return minimum;
	   }
	   int ListMaximum()
	   {
		   int maximum = 0, temp;
		   NODE*p = top;
		   maximum = p->data;
		   while (p != NULL)
		   {
			   temp = p->data;
			   if (temp > maximum)
				   maximum = temp;
			   p = p->next;
		   }
		   return maximum;
	   }
	   int ListAverage(int x)
	   {
		   //calc even average
		   NODE*p = top;
		   int*num; int total=0, temp,average, count = 0;
		   num = new int[x];
		   while (p != NULL)
		   {
			   temp = p->data;
			   if (temp % 2 == 0)
			   {
				   total += temp;
				   count++;
			   }
			   p = p->next;
		   }
		   average = total / count;
		   return average;
	   }
	   
};
int main()
{
	List t; List f; List y;
	int a[7] = { 3,6,9,1,8,5,2 };
	int b[5] = { 10,50,70,20,40 };
	int c[6] = { 100,500,800,300,200,900 };
	//1.
	for (int i = 0; i < 7; i++)
	{
		t.PushList(a[i]);
	}
	t.ListDisplay();
	cout << "Total:" << t.ListTotal() << endl;
	cout << "Number of items in list:" << t.ListCount() << endl;
	//2.
	for (int i = 0; i < 5; i++)
		f.PushList(b[i]);
	f.ListDisplay();
	cout << "Maximum:" << f.ListMaximum() << endl;
	cout << "Minimum:" << f.ListMinimum() << endl;
	//3.
	for (int i = 5; i>=0; i--)
		y.PushList(c[i]);
	y.ListDisplay();
	cout << "Average of even numbers:" << y.ListAverage(6) << endl;
	system("pause");
	return 0;
}/*2 5 8 1 9 6 3
Total:34
Number of items in list:7
40 20 70 50 10
Maximum:70
Minimum:10
900 200 300 800 500 100
Average of even numbers:466
Press any key to continue . . .*/