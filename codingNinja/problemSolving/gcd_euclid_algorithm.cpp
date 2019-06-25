#include<iostream>
using namespace std;

class Triplate{
public:
	int x;
	int y;
	int gcd;
};


int gcd(int a,int b){
	
	//this will execute first time only if b>a so that for next time onwards we will have a>b 
	//if(b>a)
	//	gcd(b,a);
	
	//base case;
	if(b==0)return a;

	return gcd(b,a%b);
}

Triplate extended_euclidian_gcd(int a,int b){
	if(b==0){
		Triplate ans;
		ans.x=1;
		ans.y=0;
		ans.gcd=a;
		return ans;
	}

	Triplate smallAns=extended_euclidian_gcd(b,a%b);

	Triplate ans;
	ans.x=smallAns.y;
	ans.y=smallAns.x - (a/b)*smallAns.y;
	ans.gcd=smallAns.gcd;

	return ans;
}

int multiplicative_modulo_inverse(int a,int m){
	//gcd(a,m) must be 1; 
	Triplate ans=extended_euclidian_gcd(a,m);
	if(ans.x<0)
		return ans.x+m;
	return ans.x;
}

int main(){
	int a,b,m;
	cout<<"Enter a and b to find gcd(a,b) "<<endl;
	cin>>a>>b;

	cout<<"gcd"<<"("<<a<<","<<b<<")="<<gcd(a,b)<<endl;

	Triplate ans=extended_euclidian_gcd(a,b);
	cout<<"ax+by=gcd(a,b) where gcd(a,b)="<<ans.gcd<<", x="<<ans.x<<" and y="<<ans.y<<endl;

	cout<<"Enter a and m such that gcd(a,m)=1 to find inverse of a "<<endl;
	cin>>a>>m;
	cout<<"multiplicative_modulo_inverse of  "<<a<<"(mod m) is "<<multiplicative_modulo_inverse(a,m)<<endl;
}