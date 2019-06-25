#include<iostream>
using namespace std;

int divisors(int n){
    if(n==0 || n==1)return 1;
    bool sieve[n+1];
    sieve[0]=sieve[1]=false;
    for(int i=2;i<=n;i++){
        sieve[i]=true;
    }
    for(int i=2;i*i<=n;i++){
        if(sieve[i]==true){
            for(int j=i;i*j<=n;j++){
                sieve[i*j]=false;
            }
        }
    }
    int m=1000000007;
    int d=1;
    for(int i=2;i<=n;i++){
        if(sieve[i]==false){
            continue;
        }
        long long x=i;
        long long count=0;
        while(n/x > 0){
            count=(count+(n/x))%m;
            x=x*i;
        }
        count=count+1;
        d=(int)((d*count)%m);
    }
    return d;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int d=divisors(n);
        cout<<d<<endl;
    }
    return 0;
}