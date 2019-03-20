/*

Design a stack with operations on middle element

How to implement a stack which will support following operations in O(1) time complexity?
1) push() which adds an element to the top of stack.
2) pop() which removes an element from top of stack.
3) findMiddle() which will return middle element of the stack.
4) deleteMiddle() which will delete the middle element.
Push and pop are standard stack operations.

The important question is, whether to use a linked list or array for implementation of stack?

Please note that, we need to find and delete middle element. Deleting an element from middle is not O(1) for array. Also, we may need to move the middle pointer up when we push an element and move down when we pop(). In singly linked list, moving middle pointer in both directions is not possible.

The idea is to use Doubly Linked List (DLL). We can delete middle element in O(1) time by maintaining mid pointer. We can move mid pointer in both directions using previous and next pointers.

Following is implementation of push(), pop() and findMiddle() operations. Implementation of deleteMiddle() is left as an exercise. If there are even elements in stack, findMiddle() returns the first middle element. For example, if stack contains {1, 2, 3, 4}, then findMiddle() would return 2.
*/
#include<iostream>
using namespace std;
struct Node
{
	int data; Node *prev,*next;
};
class stack
{
	private:
	Node *head,*top,*middle;
	int size;
	public:
	stack()
	{
		head=NULL;top=NULL;middle=NULL;size=0;
	}
	void print()
	{
		if(head==NULL)
		return;
		Node *h=head;
		while(h)
		{
			cout<<h->data<<" ";
			h=h->next;

		}

		cout<<endl;	
	}
	void push(int x)
	{
		Node *temp=new Node;
		temp->next=NULL;
		temp->prev=NULL;
		temp->data=x;

		if(head==NULL)
		{
			head=temp;
			top=temp;
			middle=temp;
			size=1;
		}
		else
		{
			temp->prev=top;
			top->next=temp;
			top=top->next;
			size=size+1;
	
			if(size%2!=0)
			middle=middle->next;
		}

	}
	int pop()
	{	
		if(head==NULL)
		return -1;

		Node *temp=NULL;
		if(size==1)
		{
			temp=top;
			top=NULL;
			head=NULL;			
			middle=NULL;
			size=0;
		}
		else
		{
			temp=top;
			top=top->prev;
			top->next=NULL;
			size=size-1;
			if(size%2==0)
			middle=middle->prev;
		}
		int x=temp->data;
		delete temp; 
		return x;

	}
	int findMiddle()
	{
		if(size==0)
		return -1;

		return middle->data;
	}
	int deleteMiddle()
	{
		if(size==0)
		return -1;

		Node *temp=middle;
		if(size==2)
		{
			middle=middle->next;
			middle->prev=NULL;
			head=middle;
			top=middle;
			size=1;
		}
		else if(size%2==0 && size!=2)
		{
			middle->prev->next=middle->next;
			middle=middle->next;
			middle->prev=temp->prev;
			size=size-1;
		}
		else
		{
			middle=middle->prev;
			middle->next=temp->next;
			temp->next->prev=temp->prev;
			size=size-1;
		}
		int x=temp->data;
		delete temp;
		return x;
	}
};
int main()
{
	stack s;
	int c,var=0,x; 
	while(1)
	{	
		cout<<"Enter 1 for push"<<endl;
		cout<<"Enter 2 for pop"<<endl;
		cout<<"Enter 3 for delele middle"<<endl;
		cout<<"Enter 4 for findMiddle"<<endl;
		cout<<"Enter 5 for Quite"<<endl;
		cin>>c;
		switch(c)
		{
			case 1 : cout<<"Enter data(integer)"<<endl;
				cin>>x;
				s.push(x);
				s.print();
				cout<<endl;
				break;
			case 2 :x=s.pop();
				if(x==-1)
				cout<<"Error 'stack is empty' "<<endl;
				s.print();
				cout<<endl;
				break;
			case 3 :x= s.deleteMiddle();
				if(x==-1)
				cout<<"Error 'stack is empty' "<<endl;
				s.print();
				cout<<endl;
				break;
			case 4 :x=s.findMiddle();
				if(x==-1)
				cout<<"Error 'stack is empty' "<<endl;
				else
				cout<<x<<endl;
				cout<<endl;
				break;
			case 5 : var=1;
				break;
		}

		if(var==1)
		break;

	}

	return 0;

}


