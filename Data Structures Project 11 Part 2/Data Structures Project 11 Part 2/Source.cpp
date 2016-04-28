//Joshua Serrano Project 11 part 1
#include <iostream>
#include <string>	
#include <algorithm>
using namespace std;
struct num
{
	int data;
};
class BST
{
private:struct NODE
{
	num info;
	NODE*left;
	NODE*right;
}; NODE*root; int count = 0;
public:BST() { root = NULL; }
	   void insertBST(int x, NODE*&p)
	   {
		   if (p == NULL)
		   {
			   p = new(NODE);
			   p->info.data = x;
			   p->left = NULL;
			   p->right = NULL;
		   }
		   else if (x > p->info.data)
		   {
			   insertBST(x, p->right);
		   }
		   else
		   {
			   insertBST(x, p->left);
		   }
	   }
	   void inorder(NODE*p)
	   {

		   if (p != NULL)
		   {
			   // cout << "Left" << endl;
			   inorder(p->left);
			   cout << p->info.data << '\t';
			   // cout << "Right" << endl;
			   inorder(p->right);
		   }
	   }
	   void inorder()
	   {
		   inorder(root);
	   }
	   void insertBST(int x)
	   {
		   insertBST(x, root);
	   }
	   void postorder(NODE*p)
	   {
		   if (p != NULL)
		   {
			   count++;
			   postorder(p->left);
			   postorder(p->right);
			   cout << p->info.data << '\t';
		   }
	   }
	   void postorder()
	   {
		   postorder(root);
	   }
	   void preorder(NODE*p)
	   {
		   if (p != NULL)
		   {
			   cout << p->info.data << '\t';
			   preorder(p->left);
			   preorder(p->right);
		   }
	   }
	   void preorder()
	   {
		   cout << root->info.data<<'\t';
		   preorder(root);
	   }
	   void nodes()
	   {
		   cout << "Number of nodes:" << count;
	   }
	   int treedepth(NODE*p)
	   {
		   if (p == NULL)
			   return 0;
		   else
		   {
			   int leftside = treedepth(p->left);
			   int rightside = treedepth(p->right);
			   return 1+max(leftside,rightside);
		   }
	   }
	   int treedepth()
	   {
		  return treedepth(root);
	   }
};
int main()
{
	BST f;
	int height;
	int a[6] = { 25,36,9,2,17,40 };
	for (int i = 0; i < 6; i++)
	{
		f.insertBST(a[i]);
	}
	cout << "inorder:";
	f.inorder(); cout << endl;
	cout << "postorder:";
	f.postorder(); cout << endl;
	cout << "preorder:";
	f.preorder(); cout << endl;
	f.nodes();
	cout << endl;
	height = f.treedepth();
	cout << "Heigh of tree is:" << height << endl;
	system("pause");
	return 0;
}
/*inorder:2       9       17      25      36      40
postorder:2     17      9       40      36      25
preorder:25     25      9       2       17      36      40
Number of nodes:6
Heigh of tree is:3
Press any key to continue . . .*/