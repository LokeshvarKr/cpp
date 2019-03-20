#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> remove_duplicate(int *a,int n){
	vector<int> ans;
	unordered_map<int,bool> seen;
	for(int i=0;i<n;i++){
	if(seen.count(a[i]) > 0)
	continue;
	seen[a[i]]=true;   // pair<int,bool>p(a[i],true); seen.insert(p);
	ans.push_back(a[i]);
	}

	return ans;
	
}

int main(){
int n;
cin>>n;
int *a=new int[n];
for(int i=0;i<n;i++)cin>>a[i];

vector<int> ans=remove_duplicate(a,n);

for(int i=0; i<ans.size(); i++)cout<<ans[i]<<" ";
cout<<endl;
delete [] a;
return 0;

}
