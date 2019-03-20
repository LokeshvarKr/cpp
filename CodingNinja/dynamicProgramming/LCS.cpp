#include<iostream>
#include<string>
#include<climits>
using namespace std;
//brute force
int lcs(string S,string T){

	if(S.length()==0 || T.length()==0)return 0;

	if(S[0]==T[0])
	return 1+lcs(S.substr(1),T.substr(1));

	else {
	int a=lcs(S.substr(1),T);
	int b=lcs(S,T.substr(1));

	return max(a,b);
	}

}


//memoization

int lcs_mem(int **ans,string S,string T){

	if(S.length()==0 || T.length()==0)return 0;

	int m=S.length();
	int n=T.length();

	if(ans[m][n]!=-1)
	return ans[m][n];

	else {
		if(S[0]==T[0]){
		ans[m][n]=1+lcs_mem(ans,S.substr(1),T.substr(1));
		}
		else {
		int a=lcs_mem(ans,S.substr(1),T);
		int b=lcs_mem(ans,S,T.substr(1));
		ans[m][n]=max(a,b);
		}
		
		return ans[m][n];

	}


}
int lcs2(string S,string T){

	int m=S.size();
	int n=T.size();

	int **ans=new int *[m+1];
	for(int i=0;i<=m;i++){
		ans[i]=new int [n+1];
		for(int j=0;j<=n;j++){
		ans[i][j]=-1;
		}
	}

	int ansRet=lcs_mem(ans,S,T);


	for(int i=0;i<=m;i++)
	delete [] ans[i];
	
	delete [] ans;


	return ansRet;

}


// Dynamic approach (bottom up)
int lcs3(string S,string T){

	int m=S.size();
	int n=T.size();

	int **ans=new int *[m+1];
	for(int i=0;i<=m;i++){
		ans[i]=new int [n+1];
		for(int j=0;j<=n;j++){
		ans[i][j]=-1;
		}
	}


	for(int i=0;i<=m;i++){

		for(int j=0;j<=n;j++){

			if(i==0||j==0)
			ans[i][j]=0;
			else if(S[i-1]==T[j-1])
			ans[i][j]=1+ans[i-1][j-1];
			else
			ans[i][j]=max(ans[i-1][j],ans[i][j-1]);
		}
	}

	int ansRet=ans[m][n];


	for(int i=0;i<=m;i++)
	delete [] ans[i];
	
	delete [] ans;


	return ansRet;


}
 
int main(){
string S,T;
cin>>S>>T;
cout<<lcs3(S,T)<<endl;

return 0;

}
