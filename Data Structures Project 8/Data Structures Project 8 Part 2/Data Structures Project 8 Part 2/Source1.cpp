#include <iostream>
using namespace std;
class List
{
private:struct NODE
{
	int info;
	NODE*next;
	NODE*back;
}; NODE*top; NODE*end;
public:
	void initlist()
	{
		top = NULL;
		end = NULL;
	}
	void addList(int x)
	{
		NODE*temp = new(NODE);
		temp->next = NULL;
		temp->info = x;
		if (top == NULL)
		{
			temp->back = NULL;
			top = temp;
		}
		else
		{
			NODE*p = top; NODE*q = p;
			while (p->next != NULL)
			{
				//q = p;
				p = p->next;
				//p->back = q;
			}
			p->next = temp;
			temp->back = p;
		}
	}
	void Display()
	{
		NODE*p = top;
		while (p->next != NULL)
		{
			cout << p->info << '\t';
			p = p->next;
		}
	//	p = p->next;
		cout << p->info;
		cout << endl;
	}
	void findend()
	{
		NODE*p = top;
		while (p->next != NULL)
		{
			p = p->next;
		}
		end = p;
	}
	void DisplayBack()
	{
		NODE*p = end;
		while (p->back != NULL)
		{
			cout << p->info << "\t";
			p = p->back;
		}
		cout << p->info << endl;
	}
	void delete15()
	{
		NODE*p = top;
		NODE*q = p;
		while (p->next != NULL)
		{
			q = p;
			p = p->next;
			if (p->info == 15)
			{
				q->next = p->next;
				p->back = q;
			}
		}
	}
	void insert60()
	{
		NODE*p = top;
		NODE*q;
		NODE*temp = new(NODE);
		temp->info = 60;
		while (p->next != NULL)
		{
			q = p;
			p = p->next;
			if (p->info == 30)
			{
				temp->next = p;
				temp->back = q;
				p->back = temp;
				q->next = temp;
			}
		}
	}
	void deleteLast()
	{
		NODE*p = end;
		p = p->back;
		p->next = NULL;
	}
};
int main()
{
	int num[10] = { 14,7,4,6,30,15,20,45,56,33 };
	List c;
	c.initlist();
	for (int i = 0; i < 10; i++)
	{
		cout << num[i] << endl;
		c.addList(num[i]);
	}
	c.findend();
	c.Display();
	//c.DisplayBack();
	c.delete15();
	c.Display();
	c.insert60();
	c.Display();
	c.deleteLast();
	c.Display();
	system("pause");
	return 0;
}