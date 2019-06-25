/*

Delete every N nodes

Given a linked list and two integers M and N. Traverse the linked list such that you retain M nodes then delete next N nodes, continue the same until end of the linked list. That is, in the given linked list you need to delete N nodes after every M nodes.

Input format :

Line 1 : Linked list elements (separated by space and terminated by -1)

Line 2 : M

Line 3 : N
Sample Input 1 :

1 2 3 4 5 6 7 8 -1
2
2

Sample Output 1 :

1 2 5 6

Sample Input 2 :

1 2 3 4 5 6 7 8 -1
2
3

Sample Output 2 :

1 2 6 7


*/
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

node* skipMdeleteN(node  *head, int M, int N)
{
   // Write your code here
  if(head==NULL)return head;
  if(M==0) return head;
  node *head1=head,*temp,*temp1;
  int m,n;
  while(head1)
  {
    m=M;
    n=N;
    while(head1 && m)
    {
      
      temp1=head1;
      head1=head1->next;
      m--;
    }
    
    if(head1==NULL)
      break;
    
  	while(head1 && n)
    {
      temp=head1;
      head1=head1->next;
      delete temp;
      n--;
    }
    temp1->next=head1;
   	if(head1==NULL)
      break;

  }

  return head;
  
}

