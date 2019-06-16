#include<iostream>
using namespace std;
/*int main()
 {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long prev=0,curr=1,next=1;
        int i=0;
        while(i<n){
            curr=next;
            cout<<curr<<" ";
            next=prev+curr;
            prev=curr;
            i++;
        }
        cout<<endl;
    
    }
	return 0;
}*/


long long fib(int n,long long ans[]){
    if(ans[n]!=-1 || n<=2){
        return ans[n];
    }
    ans[n]=fib(n-1,ans)+fib(n-2,ans);
    return ans[n];
}
#include<cstring>
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        long long *ans=new long long [n+1];
        memset(ans,-1,sizeof(ans[0]) * (n+1));
        ans[0]=0;
        ans[1]=1;
        ans[2]=1;
        ans[n]= fib(n,ans);
        for(int i=1;i<=n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        delete [] ans;
    }
	return 0;
}


//divide and conquer only for nth fibonacii;
/*void mul(long long f1[2][2],long long f2[2][2]){
    long long x=f1[0][0]*f2[0][0] + f1[0][1]*f2[1][0];
    long long y=f1[0][0]*f2[0][1] + f1[0][1]*f2[1][1];
    long long z=f1[1][0]*f2[0][0] + f1[1][1]*f2[1][0];
    long long w=f1[1][0]*f2[0][1] + f1[1][1]*f2[1][1];
    
    f1[0][0]=x;
    f1[0][1]=y;
    f1[1][0]=z;
    f1[1][1]=w;
    
}
void fibUtil(long long F[2][2],int n){
    if(n==1){
        return;
    }
    long long f[2][2]={{1,1},{1,0}};
    fibUtil(F,n/2);
    mul(F,F);
    if(n&1){
        mul(F,f);
    }
}

long long fib(int n){
    long long F[2][2]={{1,1},{1,0}};
    fibUtil(F,n);
    return F[0][1];
}
#include<cstring>
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long ans=fib(n);
        cout<<ans<<endl;
    }
	return 0;
}*/