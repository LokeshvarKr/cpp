/*

Bubble Sort (Iterative) LinkedList

Sort a given linked list using Bubble Sort (iteratively). While sorting, you need to swap the entire nodes, not just the data.
You don't need to print the elements, just sort the elements and return the head of updated LL.

Input format : Linked list elements (separated by space and terminated by -1)`
Sample Input 1 :

1 4 5 2 -1

Sample Output 1 :

1 2 4 5


*/
//head is the head of the linked list
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
node* bubble_sort_LinkedList_itr(node* head)
{
    if(head==NULL)return head;
  if(head->next==NULL)return head;
  
  int n=0;
  node *h=head;
  while(h){
    h=h->next;
    n++;
  }
  node *t,*prev;
  
  for(int i=1;i<n;i++)
  {
    prev=NULL;
    h=head;
    for(int j=1;j<=n-i;j++)
    {
      if(h->data > h->next->data)
      {
        t=h->next;
        h->next=t->next;
        t->next=h;
        if(prev==NULL)
        {
         prev=t;
         head=t;
        }
        else
        {
        	prev->next=t;
        	prev=t;
      	}
      }
      else
      {
        prev=h;
      	h=h->next;
      }
    }
  }
  return head;
  
}

