#include<iostream>
using namespace std;
class stack{
	private:
	int *a;
	int nextIndex;
	int capacity;
	public:
	stack(){
	a=new int[4];
	nextIndex=-1;
	capacity=4;
	}
	
	void push(int x){
	nextIndex++;
	if(nextIndex==capacity)
	{
	int *b=new int [2*capacity];
	for(int i=0;i<capacity;i++)
	b[i]=a[i];
	capacity*=2;
	delete [] a;
	a=b;
	}
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
stack s;
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
