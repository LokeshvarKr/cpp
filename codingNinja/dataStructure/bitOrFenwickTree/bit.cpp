#include<iostream>
using namespace std;

//sum query using bit or fenwick tree

void update(int index,int value,int *bst,int n){
	for(;index<=n;index+=(index & (-index))){
		bst[index]+=value;
	}
}

int query(int index,int *bst){
	int sum=0;
	for(;index>0;index-=(index & (-index))){
		sum+=bst[index];
	}
	return sum;
}
int main(){
	int n;
	cin>>n;
	int *a=new int[n+1]();
	int *bit=new int[n+1]();

	for(int i=1;i<=n;i++){
		cin>>a[i];
		update(i,a[i],bit,n);
	}
	int r1,r2;
	cout<<"Enter range [r1,r2] :"<<endl;
	cin>>r1>>r2;
	cout<<query(r2,bit) - query(r1-1,bit)<<endl;

	delete [] a;
	delete [] bit;
	return 0;
}