#include<iostream>
using namespace std;
class stack{
	private:
	int *a;
	int nextIndex;
	public:
	stack(int capacity){
	a=new int[capacity];
	nextIndex=-1;
	}
	void push(int x){
	nextIndex++;
	a[nextIndex]=x;
	}
	int pop(){
	int x=a[nextIndex];
	nextIndex--;
	return x;
	}
	int top(){
	if(nextIndex!=-1)
	return a[nextIndex];
	else return -1;
	}
	int size(){
	return nextIndex+1;
	}
	bool isEmpty(){
	if(nextIndex==-1)return true;
	return false;
	}

};
int main(){
int choice,x,var=0;
stack s(20);
while(1){

cout<<"1 push()"<<endl;
cout<<"2 pop()"<<endl;
cout<<"3 top()"<<endl;
cout<<"4 size()"<<endl;
cout<<"5 isEmpty()"<<endl;
cout<<"Enter your choice"<<endl;
cin>>choice;
switch(choice){
case 1:cout<<"Enter data"<<endl;
	cin>>x;
	s.push(x);
	cout<<endl;
	break;
case 2:cout<<s.pop()<<endl;
	break;
case 3:cout<<s.top()<<endl;
	break;
case 4:cout<<s.size()<<endl;
	break;
case 5:cout<<s.isEmpty()<<endl;
	break;
default :var=1;
	break;
}
if(var==1)
break;
}
return 0;
}
