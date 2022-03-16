#include<iostream>
using namespace std;

template <typename T>
class Stack{
    T *a;
    int capacity;
    int top;

    public:
    Stack(int capacity){
        this->capacity=capacity;
        this->a=new T[capacity];
        this->top=-1;
    }
    bool IsFull(){
        if(top+1==capacity)return true;
        return false;
    }
    bool IsEmpty(){
        if(top==-1)return true;
        return false;
    }
    bool Push(T data){
        if(!IsFull()){
            top=top+1;
            a[top]=data;
            return true;
        }
        else{
            cout<<"overflwo"<<endl;
            return false;
        }
    }
    T Pop(){
        if(!IsEmpty()){
            top=top-1;
            return a[top+1];
        }else{
            cout<<"underflow"<<endl;
            T x;
            return x;
        }
    }
    T Top(){
        if(!IsEmpty()){
            return a[top];
        }else{
            cout<<"underflow"<<endl;
            T x;
            return x;
        }
    }
};


int main(){
    Stack<int> s=Stack<int>(10); 
    s.Push(10);
    s.Push(20);
    s.Push(30);
    cout<<s.Pop()<<endl;
    cout<<s.Pop()<<endl; 
    cout<<s.Pop()<<endl;
    cout<<s.Pop()<<endl; 
    s.Push(10);
    s.Push(20);
    s.Push(30);
    cout<<s.Pop()<<endl;
    cout<<s.Pop()<<endl; 
    cout<<s.Pop()<<endl;
    cout<<s.Pop()<<endl; 
}