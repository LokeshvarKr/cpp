/*
  Reverse a linked list
  The input list will have at least one element  
  Return pointer to head of reverse linked list 
  Node is defined as 
  struct node
  {
     int data;
     struct Node *next;
  }
*/

/*given 1->2->3->4->5->6->7->8->NULL
output 3->2->1->6->5->4->8->7->NULL
*/
struct node *reverse (struct node *head, int k)
{ 
  struct node *x,*p,*c,*n;
  p=NULL;
  c=head;
  for(int i=0;i<k && c!=NULL; i++)
  {
   n=c->next;
   c->next=p;
   p=c;
   c=n;
  }
  if(c)
  {
      x=reverse(c,k);
      head->next=x;
  }
  return p;
  
}

