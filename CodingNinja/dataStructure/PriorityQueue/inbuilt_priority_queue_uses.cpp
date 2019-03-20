#include<iostream>
#include<queue>
using namespace std;

int main(){

// bydefault it is max priority queue
cout<<"for max priority queue"<<endl<<endl;

priority_queue<int> max_pq;

max_pq.push(101);
max_pq.push(111);
max_pq.push(30);
max_pq.push(1);
max_pq.push(110);
max_pq.push(145);
max_pq.push(456);
max_pq.push(76);

cout<<"size(): "<<max_pq.size()<<endl;
cout<<"empty(): "<<max_pq.empty()<<endl;

for(int i=0;!max_pq.empty();i++){

cout<<"top(): "<<max_pq.top()<<endl;
max_pq.pop();

}

cout<<"empty(): "<<max_pq.empty()<<endl;
cout<<"size(): "<<max_pq.size()<<endl;
max_pq.pop();
cout<<"top(): "<<max_pq.top()<<endl;
max_pq.pop();


// for min priority queue 

cout<<"for min priority queue"<<endl<<endl;

priority_queue<int,vector<int>,greater<int> > min_pq;

min_pq.push(101);
min_pq.push(111);
min_pq.push(30);
min_pq.push(1);
min_pq.push(110);
min_pq.push(145);
min_pq.push(456);
min_pq.push(76);

cout<<"size(): "<<min_pq.size()<<endl;
cout<<"empty(): "<<min_pq.empty()<<endl;

for(int i=0;!min_pq.empty();i++){

cout<<"top(): "<<min_pq.top()<<endl;
min_pq.pop();

}

cout<<"empty(): "<<min_pq.empty()<<endl;
cout<<"size(): "<<min_pq.size()<<endl;
min_pq.pop();
cout<<"top(): "<<min_pq.top()<<endl;
min_pq.pop();
return 0;
}
