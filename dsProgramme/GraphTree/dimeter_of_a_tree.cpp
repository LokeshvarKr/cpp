#include<iostream>
#include<algorithm>
using namespace std;
struct Node
{
	int data;
	Node* left;
	Node* right;
	Node* parent;
};
void Insert(Node **head,int d)
{
	Node *temp=new Node;

	temp->data=d;
	temp->left=NULL;
	temp->right=NULL;
	temp->parent=NULL;

	Node *X=(*head);
	Node *Y=NULL;

	while(X!=NULL)
	{
		Y=X;
		if(d <= X->data)
			X=X->left;
		else
			X=X->right;
	}
	temp->parent=Y;


	if(Y==NULL)
		(*head)=temp;
	else
	{
		if(d <= Y->data)
		Y->left=temp;
		else
		Y->right=temp;
	}

}
void Print(Node *head)
{
	if(head==NULL)
		return;
	Print(head->left);
	cout<<head->data<<" ";
	Print(head->right);
}
int Height(Node *head)
{
	if(head==NULL)
	return -1;
	else
	return 1+max(Height(head->left),Height(head->right));
}
int Diameter_of_Tree(Node *head)
{
	if(head==NULL)
		return -1;
	
int option1=Height(head->left)+Height(head->right);
int option2=Diameter_of_Tree(head->left);
int option3=Diameter_of_Tree(head->right);

return 1+max(option1,max(option2,option3));

}
int main()
{
	Node *head=NULL;
	int x,var,p,q;
	while(1)
	{
		cout<<"Enter 1. to insert a node in binary tree"<<endl;
		cout<<"Enter 2. to  find Diameter of the tree"<<endl;
		cin>>x;

		switch(x)
		{
			var=0;
	
			case 1 :cout<<"Enter a integer no. to insert in tree"<<endl;
				cin>>p;
				Insert(&head,p);
				cout<<endl;
				Print(head);
				cout<<endl;
				break;
	
			case 2 :cout<<"Dimeter of the tree is :"<<endl;
				q=Diameter_of_Tree(head);
				cout<<q<<endl;
				break;
			case 3 :var=1;
				break;
		}
	
	if(var==1)
	break;

	}

return 0;

}
