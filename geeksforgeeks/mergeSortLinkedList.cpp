void splitList(struct node* source, struct node** frontRef, struct node** backRef)
{
    if(source==NULL){
        return;
    }
    if(source->next==NULL){
        *frontRef=source;
        return;
    }
    if(source->next->next==NULL){
        *frontRef=source;
        *backRef=source->next;
        (*frontRef)->next=NULL;
        return;
    }
    
    node *fast=source,*slow=source;
    while(fast && fast->next){
        fast=fast->next->next;
        slow=slow->next;
    }
    node *temp=slow;
    slow=slow->next;
    temp->next=NULL;
    
    *frontRef=source;
    *backRef=slow;
}
struct node* mergeList(struct node* head1, struct node* head2){
    node *head=new node;
    head->data=0;
    head->next=NULL;
    node *go=head;
    while(head1 && head2){
        if(head1->data <= head2->data){
            go->next=head1;
            head1=head1->next;
            go=go->next;
        }
        else{
            go->next=head2;
            head2=head2->next;
            go=go->next;
        }
    }
    
    if(head1){
        go->next=head1;
    }
    if(head2){
        go->next=head2;
    }
    
    go=head;
    head=head->next;
    go->next=NULL;
    delete go;
    return head;
    
}

struct node *mergeSort(node *head){
    if(head && head->next){
        node *frontRef=NULL,*backRef=NULL;
        splitList(head,&frontRef,&backRef);
        node *front=mergeSort(frontRef);
        node *back=mergeSort(backRef);
        head=mergeList(front,back);
        return head;
    }
    else{
        return head;
    }
}