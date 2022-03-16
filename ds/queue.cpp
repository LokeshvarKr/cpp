#include<iostream>
using namespace std;
template<typename T>
class Queue{
    T *a;
    int capacity;
    int front;
    int rear;
    public:
    Queue(int capacity){
        this->capacity=capacity;
        a=new T[capacity];
        this->front=0;
        this->rear=0;

    }
    bool IsFull(){
        if((rear+1)%capacity==front)return true;
        return false;
    }
    bool IsEmpty(){
        if (front==rear)return true;
        return false;
    }
    bool Enqueue(T data){
        if(!IsFull()){
            a[rear]=data;
            rear=rear+1;
            return true;
        }else{
            cout<<"overflow"<<endl;
            return false;
        }
    }
    T Dequeue(){
        if(!IsEmpty()){
            int t=front;
            front=(front+1)%capacity;
            return a[t];
        }else{
            cout<<"underflow"<<endl;
            T x;
            return x; 
        }
    }
};



int main(){
    Queue<int> q=Queue<int>(10); 
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    cout<<q.Dequeue()<<endl;
    cout<<q.Dequeue()<<endl; 
    cout<<q.Dequeue()<<endl;
    cout<<q.Dequeue()<<endl; 
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    cout<<q.Dequeue()<<endl;
    cout<<q.Dequeue()<<endl; 
    cout<<q.Dequeue()<<endl;
    cout<<q.Dequeue()<<endl; 
}