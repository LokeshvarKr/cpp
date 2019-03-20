/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Structure of the linked list node is as
struct node
{
	int data;
	struct node* next;
};
*/
/* split the nodes of the given list into front and back halves,
     and return the two lists using the reference parameters.*/
void splitList(struct node* source, struct node** frontRef, struct node** backRef)
{
    node *slow=source,*fast=source;
    
    *frontRef=source;
    while(fast->next && fast->next->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
        *backRef=slow->next;
        slow->next=NULL;
}
// merges two sorted list into one big list
struct node* mergeList(struct node* a, struct node* b)
{
    node *source=NULL;
    
    node *head=NULL;
    
    if(a->data < b->data)
    {
        head=a;
        a=a->next;
    }
    
    else
    {
        head=b;
        b=b->next;
    }
    
    source=head;
    
    while(a && b)
    {
        if(a->data < b->data)
        {
            source->next=a;
            source=source->next;
            a=a->next;
        }
        else
        {
            source->next=b;
            source=source->next;
            b=b->next;
        }
    }
        if(b)
            source->next=b;

        if(a)
            source->next=a;
    
    return head;

    
}
