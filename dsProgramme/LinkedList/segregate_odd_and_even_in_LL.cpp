/*
SEGREGATE EVEN AND ODD IN LL

Given a Linked List of integers, write a function to modify the linked list such that all even numbers appear before all the odd numbers in the modified linked list. Also, keep the order of even and odd numbers same.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N,N is the number of elements in Linked List.
The second line of each test case contains N input,elements in Linked List.

Output:

Print the all even numbers then odd numbers in the modified Linked List.

Constraints:

1 ≤ T ≤ 100
1 ≤ N ≤ 100
1 ≤ size of elements ≤ 1000

Example:

Input
3
7
17 15 8 9 2 4 6
4
1 3 5 7
7
8 12 10 5 4 1 6

Output
8 2 4 6 17 15 9
1 3 5 7
8 12 10 4 6 5 1
*/
#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
void segregate(Node **head)
{
    Node *h=*head,*odd=NULL,*even=NULL,*H=NULL,*od=NULL;
    
    while(h)
    {
        if((h->data)%2==0)
        {
            if(H==NULL)
            {
                H=h;
                even=H;
                h=h->next;
            }
            else
                {
                    even->next=h;
                    even=even->next;
                    h=h->next;
                }
        }
        else
        {
         
            if(odd==NULL && od==NULL)
            {
                od=h;
                odd=od;
                h=h->next;
            }
            else
            {
                odd->next=h;
                odd=odd->next;
                h=h->next;
            }
        }
    }
        odd->next=NULL;
        even->next=od;
        
        *head=H;
        
        while(H)
        {
            cout<<H->data<<" ";
            H=H->next;
        }
        cout<<endl;
}
int main() 
{
	int t,n,x;
	Node *head=NULL,*h=NULL,*temp;
	cin>>t;
	for(int i=0;i<t;i++)
	{
	    cin>>n;
	    for(int j=0;j<n;j++)
	    {
	        cin>>x;
	        Node *newNode=new Node;
	        newNode->data=x;
	        newNode->next=NULL;
	        
	        if(head==NULL)
	        {
	            head=newNode;
	            h=head;
	        }
	        else
	        {
	            h->next=newNode;
	            h=h->next;
	        }
	    }
	    
	    
	    segregate(&head);
	    
	    
	    while(head)
	    {
	        temp=head;
	        head=head->next;
	        delete(temp);
	    }
	    
	    head=NULL;
	
	}
	
	return 0;
}
