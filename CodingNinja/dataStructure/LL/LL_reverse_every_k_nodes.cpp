/*

kReverse

Implement kReverse( int k ) in a linked list i.e. you need to reverse first K elements then reverse next k elements and join the linked list and so on.
Indexing starts from 0. If less than k elements left in the last, you need to reverse them as well. If k is greater than length of LL, reverse the complete LL.
You don't need to print the elements, just return the head of updated LL.

Input format :

Line 1 : Linked list elements (separated by space and terminated by -1)

Line 2 : k
Sample Input 1 :

1 2 3 4 5 6 7 8 9 10 -1
4

Sample Output 1 :

4 3 2 1 8 7 6 5 10 9

Sample Input 2 :

1 2 3 4 5 -1
2

Sample Output 2 :

2 1 4 3 5 

Sample Input 3 :

1 2 3 4 5 6 7 -1
3

Sample Output 3 :

3 2 1 6 5 4 7



*/

//head is the head of the linked list, n is number of elements to be reversed
// Following is the node structure
/**************
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
***************/

// recursively

// recursively 

class Pair{
public:
  node *h1;
  node *t1;
};

Pair reverse(node *h1){
  
  if(h1->next==NULL)
  {
    Pair ans;
    ans.h1=h1;
    ans.t1=h1;
    
    return ans;
  }
  
  node *prev=NULL,*current=h1,*Next;
  while(current){
    Next=current->next;
    current->next=prev;
    prev=current;
    current=Next;
  }
  Pair ans;
  ans.h1=prev;
  ans.t1=h1;
  return ans;
}

node* kReverse(node *head,int n){

  if(head==NULL ||head->next==NULL || n==0 || n==1 )return head;
  
  
  int count=1;
  node *h1=head,*t1=head,*h2=NULL,*h=NULL;
  
  while(t1 && count<n){
    t1=t1->next;
    count++;
  }
  
  if(t1){
  h2=t1->next;
  t1->next=NULL;
  h=kReverse(h2,n);
  }
  
  Pair ans=reverse(h1);
  ans.t1->next=h;
  
  return ans.h1;
 
}



//iteratively

node* kReverse(node*head,int n)
{
  if(head==NULL)return head;
  if(head->next==NULL)return head;
  
  node  *h=NULL, *head1=head,*prev=NULL,*current=head,*Next;
  
  int k=n;
  while(current && k)
  	{
    	k--;
    	Next=current->next;
    	current->next=prev;
    	prev=current;
    	current=Next;	
  	}
  	h=prev;
  	prev=NULL;
 
  while(current)
  {	
 	k=n;
    head1=current;
  	while(current && k)
  	{
      	k--;
    	Next=current->next;
    	current->next=prev;
    	prev=current;
    	current=Next;
  	}
    
    head->next=prev;
  	head=head1;
    prev=NULL;
    
 }
  
  return h;
  
}

