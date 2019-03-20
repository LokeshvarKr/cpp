#include<iostream>
#include<climits>
#include<utility>
using namespace std;


void print_cut_rod(int *s,int n)
{
	while(n>0){
	cout<<s[n]<<" ";
	n=n-s[n];
	}

}
//tabulation bottom-up
pair<int*,int*> extended_cut_rod_bottom_up(int *p,int n)
{
int *r=new int [n+1];
int *s=new int [n+1];
r[0]=0;
for(int i=1;i<=n;i++){
	int q=INT_MIN;
	
	for(int j=1;j<=i;j++){
	if(q<p[j]+r[i-j]){
		q=p[j]+r[i-j];
		s[i]=j;
		}
	}
	r[i]=q;

}


pair<int*,int*> ans;
ans.first=r;
ans.second=s;
return ans;

}
int cut_rod_bottom_up(int *p,int n)
{
int *r=new int [n+1];
int *s=new int [n+1];
r[0]=0;
for(int i=1;i<=n;i++){
	int q=INT_MIN;
	for(int j=1;j<=i;j++){	
	q=max(q,p[j]+r[i-j]);
	}
	r[i]=q;
	
}

int ans=r[n];
delete [] r;
return ans;

}
//memoization
int cut_rod_mem_aux(int *p,int n,int *r){
	
	if(r[n]>=0)return r[n];

	if(n==0){
	r[0]=0;
	return 0;
	}

	else{
		int q=INT_MIN;
		
		for(int i=1;i<=n;i++){
		q=max(q,p[i]+cut_rod_mem_aux(p,n-i,r));
		}
		r[n]=q;
		
		return q;

	}

}
 
int cut_rod_memoization(int *p,int n){
int *r=new int [n+1];

for(int i=0;i<=n;i++)r[i]=-1;
int ans=cut_rod_mem_aux(p,n,r);

delete [] r;

return ans;

}

//brute force recursive
int cut_rod(int *p,int n){

if(n==0)return 0;

int q=INT_MIN;
for(int i=1;i<=n;i++){
q=max(q,p[i]+cut_rod(p,n-i));
}
return q;

}


int main(){
	int size;
	cout<<"size of price array: "<<endl;
	cin>>size;
	int *p=new int[size+1];

	p[0]=0;
	cout<<"Enter price array"<<endl;
	for(int i=1;i<=size;i++)cin>>p[i];

	int n;
	cout<<"Enter length of Rod"<<endl;
	cin>>n;

	pair<int*,int*> ans=extended_cut_rod_bottom_up(p,n);
	cout<<"maximum revenue "<<ans.first[n]<<endl;
	cout<<"actual solution"<<endl;
	print_cut_rod(ans.second,n);
	cout<<endl;
	delete [] ans.first;
	delete [] ans.second;


	delete [] p;
	return 0;


}

