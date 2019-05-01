#include <stdint.h>
#include <iostream>
using namespace std;
struct Node{
		int data;
		struct Node* npx; 
};
struct Node* XOR (struct Node *a, struct Node *b){
	return (struct Node*) ((uintptr_t) (a) ^ (uintptr_t) (b));
}

//insert at (before) head of linked list
void insert(struct Node **head_ref, int data)
{
	Node *newNode = new Node;
	newNode->data=data;
	newNode->npx=NULL;
	Node *head=*head_ref;
	*head_ref=newNode;
    if(head){
    	newNode->npx=XOR(head,NULL);
    	head->npx=XOR(head->npx , newNode);
    }
	
}

void printList (struct Node *head)
{
    //forward print
    Node *prev=NULL;
	while(head){
	    cout<<head->data<<" ";
	    Node *temp=head;
	    head=XOR(head->npx,prev);
	    prev=temp;
	}
	cout<<endl;
	
	//backward print
	head=prev;
	prev=NULL;
	while(head){
	    cout<<head->data<<" ";
	    Node *temp=head;
	    head=XOR(head->npx,prev);
	    prev=temp;
	}
}

int main(){
	int n,tmp;
	Node *head=NULL;
	cin>>n;
	 while(n--){
        cin>>tmp;
        insert(&head, tmp);
    }
    cout<<"forward and backward printing the linked list"<<endl;
    printList (head);
    cout<<endl;

    return 0;
}