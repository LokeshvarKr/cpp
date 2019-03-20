//two linked list sorted are in place mearged
 
Node* SortedMerge(Node* head1,   Node* head2)
{
    Node  *h1,*h2,*p,*head;
    p=NULL;
    h1=head1;
    h2=head2;
    
    if(h1->data < h2->data)
    {
        head=h1;
        p=h1;
        h1=h1->next;
    }
    else
    {
        head=h2;
        p=h2;
        h2=h2->next;
    }

    while(h1 && h2)
    {
        if(h1->data < h2->data)
        {
            p->next=h1;
            p=h1;
            h1=h1->next;
        }
        else
        {
        p->next=h2;
        p=h2;
        h2=h2->next;
        }
    }
    if(h1==NULL)
    p->next=h2;
    if(h2==NULL)
    p->next=h1;
    
    return head;
}
