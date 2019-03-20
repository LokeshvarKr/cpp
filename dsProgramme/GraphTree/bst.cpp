#include<iostream>
using namespace std;
struct TNode
{
	int data;
	TNode *left;
	TNode *right;
	TNode *parent;
};

void printInorder(TNode *x)
{
	if(x!=NULL)
	{
		printInorder(x->left);
		cout<<x->data<<" ";
		printInorder(x->right);	
	}

}
TNode* bst_insert(TNode **head,int data)
{
	TNode *temp=new TNode;
	
	temp->data=data;
	temp->left=temp->right=temp->parent=NULL;

	TNode *x=*head;
	TNode *y=NULL;

	while(x!=NULL)
	{
		y=x;
		if(temp->data < x->data)
			x=x->left;
		else
			x=x->right;
	}
	
	temp->parent=y;

	if(y==NULL)
		*head=temp;
	else if(temp->data < y->data)
		y->left=temp;
	else
		y->right=temp;

}
TNode* bst_search(TNode *head,int data)
{
	TNode *x=head;
	while(x!=NULL && x->data!=data)
	{
		if(data < x->data)
			x=x->left;
		else
			x=x->right;
	}
	
	return x;
}
TNode* tree_min(TNode *x)
{
	while(x->left!=NULL)
		x=x->left;

	return x;
}
void transplant(TNode **head,TNode *u,TNode *v)
{
	if(u->parent==NULL)
		*head=v;
	else if(u->parent->left==u)
		u->parent->left=v;
	else	u->parent->right=v;
	
	if(v!=NULL)
	v->parent=u->parent;
}
void bst_delete(TNode **head,int d)
{
	TNode *z=bst_search(*head,d);
	if(z==NULL)
	cout<<"Error: 'this data is not found in  Tree' "<<endl;
	else
	{ 
		if(z->left==NULL)
		transplant(head,z,z->right);
		
		else if(z->right==NULL)
		transplant(head,z,z->left);
	
		else 
		{
			TNode *y;
			y=tree_min(z->right);
			
			if(y->parent!=z)
			{
				transplant(head,y,y->right);
				y->right=z->right;
				y->right->parent=y;
			}
			
			transplant(head,z,y);
			y->left=z->left;
			y->left->parent=y;
		}
		
		delete z;
	}
}
int main()
{
	TNode *head=NULL;
	TNode *t;
	int e,x,var=1;
	while(1)
	{
		cout<<"Enter 1 for insert"<<endl;
		cout<<"Enter 2 for search"<<endl;
		cout<<"Enter 3 for deletion"<<endl;
		cout<<"Enter 4 for Quiet"<<endl;
		cin>>e;

		switch(e)
		{
		case 1 : cout<<"Enter an element"<<endl;
			cin>>x;
			bst_insert(&head,x);
			cout<<"Elements of tree are :"<<endl;
			printInorder(head);
			cout<<endl;
			break;

		case 2 : cout<<"Enter an element for search"<<endl;
			cin>>x;
			t=bst_search(head,x);
			if(t==NULL)
				cout<<"Not Found"<<endl;
			else
				cout<<t->data<<" is found"<<endl;
			break;

		case 3 : cout<<"Enter an element for delete"<<endl;
			cin>>x;
			bst_delete(&head,x);
			cout<<"Elements of tree are :"<<endl;
			printInorder(head);
			cout<<endl;
			break;

		case 4 :var=0;
			break;

		}

		if(var==0)
		break;

	
	}

	return 0;

}



