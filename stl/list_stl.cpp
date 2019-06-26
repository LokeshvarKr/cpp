#include<list>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){

	list<int> l;
	
	//push pop
	l.push_front(15);
	l.push_front(7);
	l.push_front(20);
	l.push_front(8);
	l.push_back(100);
	l.push_back(200);
	l.push_back(180);

	//traversing list
	for(auto x=l.begin();x!=l.end();x++){
		cout<<*x<<" ";
	}
	cout<<endl;

	l.sort();

	for(auto x:l){
		cout<<x<<" ";
	}
	cout<<endl;


	l.reverse();
	for(auto x:l){
		cout<<x<<" ";
	}
	cout<<endl;

	list<int> l2=l;
	for(auto x:l2){
		cout<<x<<" ";
	}
	cout<<endl;

	l.reverse();
	l2.reverse();
	l.merge(l2);

	for(auto x:l){
		cout<<x<<" ";
	}
	cout<<endl;

	auto x=l.begin();
	l.emplace(x,3);

	for(auto x:l){
		cout<<x<<" ";
	}
	cout<<endl;

	for(auto x:l){
		cout<<x<<" ";
	}
	cout<<endl;
	
	cout<<l.empty()<<endl;
	l.clear();
	cout<<l.empty()<<endl;

	return 0;
}