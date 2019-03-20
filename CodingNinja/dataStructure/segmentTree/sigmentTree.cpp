#include<iostream>
using namespace std;

void builtTree(int *a,int *tree,int start,int end,int treeNode){
	if(start==end){
		tree[treeNode]=a[start];
		return;
	}

	int mid=(start+end)/2;
	builtTree(a,tree,start,mid,2*treeNode);
	builtTree(a,tree,mid+1,end,2*treeNode+1);
	tree[treeNode]=tree[2*treeNode] + tree[2*treeNode+1];
}
void update(int *a,int *tree,int s,int e,int treeNode,int index,int value){
	if(s==e){
		a[index]=value;
		tree[treeNode]=value;
		return;
	}
	int mid=(s+e)/2;
	if(index > mid){
		update(a,tree,mid+1,e,2*treeNode+1,index,value);
	}
	else{
	 update(a,tree,s,mid,2*treeNode,index,value);
	}
	tree[treeNode]=tree[treeNode*2]+tree[treeNode*2+1];

}
int maxRangeQuery(int *tree,int s,int e,int treeNode,int l,int r){
	//range is completely outside
	if(e < l || s > r){
		return 0;
	}
	//range completely inside
	if(s>=l && e<=r){
		return tree[treeNode];
	}

	//partially inside partially outside
	int mid=(s+e)/2;
	int ans1=maxRangeQuery(tree,s,mid,treeNode*2,l,r);
	int ans2=maxRangeQuery(tree,mid+1,e,treeNode*2+1,l,r);
	return ans1+ans2;
}

int main(){
	int n;
	cin>>n;
	int *a=new int [n];
	for(int i=0;i<n;i++)cin>>a[i];

	int *tree=new int [n+n+n];
	builtTree(a,tree,0,n-1,1);

	for(int i=0;i<3*n;i++)cout<<tree[i]<<" ";
	cout<<endl;
	
	int index,value;
	cout<<"Enter index and value to update"<<endl;
	cin>>index>>value;
	update(a,tree,0,n-1,1,index,value);

	for(int i=0;i<3*n;i++)cout<<tree[i]<<" ";
	cout<<endl;

	int l,r;
	cout<<"query range enter range (l,r)"<<endl;
	cin>>l>>r;
	int result=maxRangeQuery(tree,0,n-1,1,l,r);
	cout<<result<<endl;
	delete [] a;
	delete [] tree;
	return 0;
}