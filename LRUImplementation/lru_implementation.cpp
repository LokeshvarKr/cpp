#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
class Cache{
	int cache_size;
	int count_page_fault;
	list<int> dq;
	unordered_map<int,list<int> :: iterator> m;
public:
	Cache(int size):cache_size(size),count_page_fault(0){}
	void refer(int x){
		if(m.find(x)==m.end()){
			count_page_fault++;
			if(dq.size()==cache_size){
				int b=dq.back();
				m.erase(b);
				dq.pop_back();

				dq.push_front(x);
				m[x]=dq.begin();
			}
			else{
				dq.push_front(x);
				m[x]=dq.begin();
			}
		}
		else{
			dq.erase(m[x]);
			m.erase(x);
			dq.push_front(x);
			m[x]=dq.begin();
		}
	}

	void display(){
		cout<<"page fault count: "<<count_page_fault<<endl;
		cout<<"pagepresent in cache : "; 
		for(int x: dq){
			cout<<x<<" ";;
		}
		cout<<endl;
	}

};
int main(){
	int n;
	cout<<"cache size?"<<endl;
	cin>>n;
	Cache myCache(n); 
	int page;
	while(true){
		cout<<"Enter page number (Enter -1 to stop)"<<endl;
		cin>>page;
		if(page<=0){
			break;
		}
		myCache.refer(page);
	}
	myCache.display();
	return 0;
}