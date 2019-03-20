/*
Delete a given node in Linked List under given constraints

Given a Singly Linked List, write a function to delete a given node. Your function must follow following constraints:
1) It must accept pointer to the start node as first parameter and node to be deleted as second parameter i.e., pointer to head node is not global.
2) It should not return pointer to the head node.
3) It should not accept pointer to pointer to head node.

You may assume that the Linked List never becomes empty.


*/

#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node *next;
};

Node *Search(Node *head)
void print(Node *head)

void DeleteNode(Node *head,Node *n)
{
	if(head==n && head->next==NULL)
	{
		cout<<"Node is not deleted because it is head node"<<endl;
		return;
	}
	if(head==n && head->next!=NULL)
	{
		head->data=head->next->data;
		n=head->next;
		head->next=head->next->next;
		delete(n);
		return;
	}
	
	Node *prev=head;
	while(prev->next!=NULL && prev->next!=n)
	{
		prev=prev->next;
	}
	if(prev->next==NULL)
	{
		cout<<"node note found in the  linked list"<<endl;
		return;
	}
	if(prev->next==n)
	{
		prev->next=prev->next->next;
		delete(n);
	}
	
		
}
int main()
{
	Node *head=NULL;
	Node *n=NULL;
	int x;
	int c;
	int var=0;
	while()
	{
		cout<<"Enter 1 for insert a node at begning"<<endl;
		cout<<"Enter 2 for delete a node under constraint"<<endl;
		cout<<"Enter 3 for exit"<<endl;
		cin>>c;
		
		switch(c)
		{

			case 1 : cout<<"Enter an integer "<<endl;
				cin>>x;
				InsertAtBegning(&head,x);
				PrintList(head);
				cout<<endl;
				break;
			case 2 : cout<<"Enter a number to delete that node under constraint"<<endl;
				cin>>x;
				n=search(head);
				DeleteNode(head,n);
				PrintList(head);
				break;
			case 3 : var=1;
				break;
		}
	if(var==1)
	break;
	}







return 0;

}
