/*
Point arbit pointer to greatest value right side node in a linked list

Given singly linked list with every node having an additional “arbitrary” pointer that currently points to NULL. We need to make the “arbitrary” pointer to greatest value node in a linked list on its right side.

*/
#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* arbit;
    Node* next;
};

void PrintNext(Node *head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
	cout<<endl;
}
void PrintArbit(Node *head)
{
    while(head->arbit)
    {
        cout<<head->data<<"-->"<<head->arbit->data<<" "<<endl;
        head=head->next;
    }
	cout<<endl;
}
void Push(Node **head,int data)
{
    static Node *h=*head;
    Node *temp=new Node;
    temp->arbit=NULL;
    temp->next=NULL;
    temp->data=data;
    
    if(h==NULL)
    {
        *head=temp;
        h=*head;
    }
    else
    {
        h->next=temp;
        h=h->next;
    }
}
Node *Reverse(Node *head)
{
    Node *c=head,*p=NULL,*n;
    while(c)
    {
        n=c->next;
        c->next=p;
        p=c;
        c=n;
    }
    return p;
}
Node *PopulatedArbit(Node *head)
{
    if(head==NULL)
    return NULL;
    
    head=Reverse(head);
    Node *h=head,*max=head;
    while(h->next)
    {
        h->next->arbit=max;
        h=h->next;
        if(h->data > max->data)
        max=h;
    }
    head=Reverse(head);
    return head;
}
int main()
{
    int n,x;
    Node *head=NULL;
    cout<<"Enter no. of elements "<<endl;
    cin>>n;
    cout<<"Enter elements of linked list"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        Push(&head,x);
    }
        cout<<"before populated arbit"<<endl;
        PrintNext(head);
        head=PopulatedArbit(head);
        cout<<"after populated arbit"<<endl;
        PrintArbit(head);
    return 0;
}
