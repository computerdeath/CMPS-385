#include <iostream>
using namespace std;
struct NODE {
	int data;
	NODE *next;
};
void DisplayOrderThree(int a, int b, int c, int d, int Distribution)
{
	cout << "\n" << Distribution << "\t--\t--\t--\n";
	NODE *f1, *t1, *t2, *t3;
	f1 = new NODE; t1 = new NODE; t2 = new NODE; t3 = new NODE;
	f1->data = a; t1->data = b; t2->data = c;	t3->data = d;
	f1->next = t1; t1->next = t2; t2->next = t3; t3->next = NULL;
	NODE *p, *q, *r;
	int minimum = Distribution;
	while ((f1->data + t1->data + t2->data + t3->data) > 1) 
	{
		p = f1;
		while (p != NULL) 
		{
			if (minimum > p->data && p->data != 0)
			{
				minimum = p->data;
			}
			p = p->next;
		}
		q = f1;
		while (q != NULL)
		{
			if (q->data == 0) {
				cout << "--\t";
				q = q->next;
			}
			else 
			{
				cout << q->data << "\t";
				q = q->next;
			}
		}
		cout << "\n";
		r = f1;
		while (r != NULL)
		{
			r->data -= minimum;
			if (r->data < 0) 
			{
				r->data = minimum;
			}
			r = r->next;
		}
	}
	q = f1;
	while (q != NULL) {
		if (q->data == 0) 
		{
			cout << "--\t";
			q = q->next;
		}
		else
		{
			cout << q->data << "\t";
			q = q->next;
		}
	}
}
void DisplayOrderFour(int a, int b, int c, int d, int e, int Distribution) {
	cout << "\n" << Distribution << "\t--\t--\t--\t--\n";
	NODE *f1, *t1, *t2, *t3, *t4;
	f1 = new NODE; t1 = new NODE; t2 = new NODE; t3 = new NODE; t4 = new NODE;
	f1->data = a; t1->data = b; t2->data = c;	t3->data = d; t4->data = e;
	f1->next = t1; t1->next = t2; t2->next = t3; t3->next = t4; t4->next = NULL;
	NODE *p, *q, *r;
	int minimum = Distribution;
	while ((f1->data + t1->data + t2->data + t3->data + t4->data) > 1) 
	{
		p = f1;
		while (p != NULL)
		{
			if (minimum > p->data && p->data != 0) {
				minimum = p->data;
			}
			p = p->next;
		}
		q = f1;
		while (q != NULL)
		{
			if (q->data == 0)
			{
				cout << "--\t";
				q = q->next;
			}
			else 
			{
				cout << q->data << "\t";
				q = q->next;
			}
		}
		cout << "\n";
		r = f1;
		while (r != NULL)
		{
			r->data -= minimum;
			if (r->data < 0) 
			{
				r->data = minimum;
			}
			r = r->next;
		}
	}
	q = f1;
	while (q != NULL)
	{
		if (q->data == 0)
		{
			cout << "--\t";
			q = q->next;
		}
		else 
		{
			cout << q->data << "\t";
			q = q->next;
		}
	}
}

int main() {
	cout << endl;

	int fileSize, FileDistribution;
	char choice, cont;
	int OrderThree[7] = { 1, 3, 5, 9, 17, 31, 57 };
	int OrderFour[7] = { 1, 4, 7, 13, 25, 49, 94 };
		cout << endl;
		cout << "a. PFD of order 3\n";
		cout << "b. PFD of order 4\n";
		cout << "   Enter a file size (< 55): ";
		cin >> fileSize;
		cout << "   Enter your choice (a/b): ";
		cin >> choice;
		cout << endl;

		if (choice == 'a') 
		{
			cout << "F1\tT1\tT2\tT3\n";
			cout << "==========================";
			for (int i = 0; i < 7; i++) 
			{
				if (fileSize > OrderThree[i])
				{
					FileDistribution = OrderThree[i + 1];
				}
				else if (fileSize == OrderThree[i]) 
				{
					FileDistribution = OrderThree[i];
				}
				else
				{
					break;
				}
			}
			// Passing Perfect Fibonacci Distribution to Display function
			// for final output
			switch (FileDistribution) {
			case 1:
				DisplayOrderThree(0, 1, 0, 0, FileDistribution);
				break;
			case 3:
				DisplayOrderThree(0, 1, 1, 1, FileDistribution);
				break;
			case 5:
				DisplayOrderThree(0, 2, 2, 1, FileDistribution);
				break;
			case 9:
				DisplayOrderThree(0, 4, 3, 2, FileDistribution);
				break;
			case 17:
				DisplayOrderThree(0, 7, 6, 4, FileDistribution);
				break;
			case 31:
				DisplayOrderThree(0, 13, 11, 7, FileDistribution);
				break;
			case 57:
				DisplayOrderThree(0, 24, 20, 13, FileDistribution);
				break;
			default:
				break;
			}
		}
		else if (choice == 'b' && fileSize < 94)
		{
			cout << "F1\tT1\tT2\tT3\tT4\n";
			cout << "==================================";
			for (int i = 0; i < 7; i++)
			{
				if (fileSize >OrderFour[i]) 
				{
					FileDistribution = OrderFour[i + 1];
				}
				else if (fileSize == OrderFour[i]) 
				{
					FileDistribution = OrderFour[i];
				}
				else {
					break;
				}
			}

			switch (FileDistribution)
			{
			case 1:
				DisplayOrderFour(0, 1, 0, 0, 0, FileDistribution);
				break;
			case 4:
				DisplayOrderFour(0, 1, 1, 1, 1, FileDistribution);
				break;
			case 7:
				DisplayOrderFour(0, 2, 2, 2, 1, FileDistribution);
				break;
			case 13:
				DisplayOrderFour(0, 4, 4, 3, 2, FileDistribution);
				break;
			case 25:
				DisplayOrderFour(0, 8, 7, 6, 4, FileDistribution);
				break;
			case 49:
				DisplayOrderFour(0, 15, 14, 12, 8, FileDistribution);
				break;
			case 94:
				DisplayOrderFour(0, 29, 27, 23, 15, FileDistribution);
				break;
			default:
				break;
			}
			// If user entered an invalid choice, program stops
		

	return 0;
}