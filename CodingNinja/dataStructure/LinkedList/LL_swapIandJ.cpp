/*
Swap two Node of LL

Given a linked list, i & j, swap the nodes that are present at i & j position in the LL. You need to swap the entire nodes, not just the data.
Indexing starts from 0. You don't need to print the elements, just swap and return the head of updated LL.
Assume i & j given will be within limits. And i can be greater than j also.

Input format :

Line 1 : Linked list elements (separated by space and terminated by -1)

Line 2 : i and j (separated by space)
Sample Input 1 :

3 4 5 2 6 1 9 -1
3 4

Sample Output 1 :

3 4 5 6 2 1 9

Sample Input 2 :

3 4 5 2 6 1 9 -1
2 4

Sample Output 2 :

3 4 6 2 5 1 9



*/
//head is head of your linked list, i and j are indexes to be swapped
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
node* swap_nodes(node *head,int i,int j)
{
    //write your code here
  if(head==NULL)return head;
  
  node *head1=head,*temp1,*temp2,*iSwap,*jSwap;
	int a=i<j?i:j;
  	int b=i>j?i:j;
  	int x=b-a-1;
  temp1=NULL;
  while(a){
    temp1=head1;
    head1=head1->next;
      a--;
  }
  iSwap=head1;
  head1=head1->next;
  
  temp2=head1;
  while(x)
  {
    temp2=head1;
    head1=head1->next;
    x--;
  }
  jSwap=head1;
  head1=head1->next;
  if(temp1!=NULL)
  temp1->next=jSwap;
  
  jSwap->next=iSwap->next;
  temp2->next=iSwap;
  iSwap->next=head1;
  
  if(temp1==NULL)
    return jSwap;
  else
  return head;
}

