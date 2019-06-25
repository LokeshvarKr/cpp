/*
Code : Reverse LL (Recursive)

Given a linked list, reverse it using recursion.
You don't need to print the elements, just reverse the LL duplicates and return the head of updated LL.

Input format : Linked list elements (separated by space and terminated by -1)`
Sample Input 1 :

1 2 3 4 5 -1

Sample Output 1 :

5 4 3 2 1


*/

//better approch o(n)
class paired{
  public:
  	node *head;
  	node *tail;
};

paired reverse_rec_better(node *head)
{
 	if(head->next==NULL)
    {
      paired ans;
      ans.head=head;
      ans.tail=head;
      return ans;
    }
  paired smallAns =reverse_rec_better(head->next);
  smallAns.tail->next=head;
  smallAns.tail=smallAns.tail->next;
  head->next=NULL;
  return smallAns;
}
node *reverse_linked_list_rec(node *head){
  paired result=reverse_rec_better(head);
  return result.head;
}


//easy solution o(n^2) solution

/*
node *reverse_linked_list_rec(node *head)
{
 if(head->next==NULL)
   return head;
  node *head1,*h;
  head1=reverse_linked_list_rec(head->next);
  h=head1;
  while(head1->next)
    head1=head1->next;
  
  head1->next=head;
  head->next=NULL;
  return h;
}
*/

// very easy method

/*
node *reverse_linked_list_rec(node *head){
	if(head->next==NULL)
  	return head;
  
  	node *temp=reverse_linked_list_rec(head->next);
	node *t=head->next;
  	t->next=head;
  	head->next=NULL;
  
  	return temp;
}

*/
