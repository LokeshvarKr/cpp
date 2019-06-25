#include<iostream>
using namespace std;
class Node{
public:
	int a;
	int b;
	int c;
	Node(){
		cout<<"constructor"<<endl;
	}
	~Node(){
		cout<<"destructor"<<endl;
	}

};
int main(){
	int n;
	cin>>n;
	Node *list=new Node[n];
	delete [] list;
	return 0;
}