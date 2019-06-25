
//min priority Queue uses

#include<iostream>
#include"minPriorityQueue.h"
using namespace std;
int main(){
priorityQueue pq;

	pq.insert(10);
	pq.insert(100);
	pq.insert(20);
	pq.insert(2);
	pq.insert(35);
	pq.insert(5);
	pq.insert(10);

cout<<"size : "<<pq.getSize()<<endl;

	for(int i=0;i<10;i++){
	cout<<pq.getMin()<<endl;
	cout<<"removed "<<pq.removeMin()<<endl;
	}

return 0;

}
