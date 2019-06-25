#include<iostream>
#include<queue>
using namespace std;

void sort_k_sorted_array(int *a,int n,int k){
	priority_queue<int> pq;
	
	for(int i=0;i<k;i++)
	pq.push(a[i]);
	
	int i=0;
	for(;i<n-k;i++){
	a[i]=pq.top();
	pq.pop();
	pq.push(a[i+k]);
	}
	
	for(;i<n;i++){
	a[i]=pq.top();
	pq.pop();
	}
	


} 

int main(){
int n;
cout<<"inter size of array "<<endl;
cin>>n;
int *a=new int [n];
cout<<"Enter "<<n<<" elements "<<endl;
for(int i=0;i<n;i++)
cin>>a[i];

int k;
cout<<"this array is sorted by ?"<<endl;
cin>>k;

sort_k_sorted_array(a,n,k);

for(int i=0;i<n;i++)
cout<<a[i]<<" ";
cout<<endl;

delete [] a;
return 0;
}
