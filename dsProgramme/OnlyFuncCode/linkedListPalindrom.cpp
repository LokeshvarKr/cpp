//check wheather a linkedlist is palindrom or not
//time complexity is o(n) and space complexity is o(1)

/*The structure of the Node is
struct Node
{
    int data;
    struct Node* next;
};*/
/*You are required to complete this method */
Node *reverse(Node *head)
{
    if(head->next==NULL)
    return head;
    
    Node *p,*c,*n;
    p=NULL;
    c=head;
    
    while(c)
    {
        n=c->next;
        c->next=p;
        p=c;
        c=n;
    }
    return p;
}
bool isPalindrome(Node *head)
{
    if(head->next==NULL)
    return true;
    
    Node *fast=head;
    Node *slow=head;
    Node *h=head;
    bool result;
    Node *H,*h1;
    
    while(fast->next and fast->next->next)
    {
      slow=slow->next;
      fast=fast->next->next;
    }
    if(fast->next==NULL)
    {
        H=reverse(slow->next);
        //slow->next=NULL;
        h1=H;
        
        while(h1)
        {
            if(h1->data==h->data)
            {
                h1=h1->next;
                h=h->next;
            }
            else
            {
            result=false;
            break;
            }
        }
        if(h1==NULL)
        result=true;
        
        h1=reverse(H);
        slow->next=h1;
        
        return result;
    }
    if(fast->next->next==NULL)
    {
        H=reverse(slow->next);
        h1=H;
         while(h1)
        {
            if(h1->data==h->data)
            {
                h1=h1->next;
                h=h->next;
            }
            else
            {
            result=false;
            break;
            }
        }
            if(h1==NULL)
            result=true;
            
            h1=reverse(H);
            slow->next=h1;
            
            return result;
    }
    
    
}
