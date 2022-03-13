#include <iostream>
#include<queue>
using namespace std;

class Node{
    public:
    Node* prev;
    Node* next;
    int data;
    Node(int data){
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }
    ~Node(){
        cout<<"inside Node distructor data:"<<this->data<<endl;
        delete this->next;
    }
};


class SinglyLinkedList{
    public:
    Node *head;
    Node* tail;
    
    SinglyLinkedList(){
        head=NULL;
        tail=NULL;
    }
    ~SinglyLinkedList(){
        cout<<"inside distructor"<<endl;
        delete head;
    }
    
    void Insert(int data){
        Node* node=new Node(data);
        if(head==NULL){
            head=node;
            tail=node;
        }else{
            this->tail->next=node;
            this->tail=node;
        }
    }
    
    void Delete(int data){
        Node *temp=this->head;
        Node *prev=NULL;
        while(temp!=NULL && temp->data!=data){
            prev=temp;
            temp=temp->next;
        }
        if(temp!=NULL){
            Node* x=temp;
            temp=temp->next;
            x->next=NULL;
            if(prev=NULL){
                if(head==tail){
                    tail=NULL;
                }
                head=temp;
            }else{
                prev->next=temp;
            }
            delete x;
            cout<<"Deleted"<<endl;
        }else{
            cout<<"Not found"<<endl;
        }
    }
    
    void Print(){
        Node* temp=this->head;
        while(temp){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};


int main() {
    
    SinglyLinkedList sl = SinglyLinkedList();
    sl.Insert(2);
    sl.Insert(0);
    sl.Insert(6);
    sl.Print();
}
