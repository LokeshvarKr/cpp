#include<iostream>
using namespace std;
void roman(int n)
{
	
	if(n>=1000){
	cout<<"m";
	roman(n-1000);
	}

	else if(n>=500){
	cout<<"d";
	roman(n-500);
	}

	else if(n>=100){
	cout<<"c";
	roman(n-100);
	}

	else if(n>=50){
	cout<<"l";
	roman(n-50);
	}

	else if(n>=10){
	cout<<"x";
	roman(n-10);
	}

	else if(n==9){
	cout<<"ix";
	}

	else if(n>=5){
	cout<<"v";
	roman(n-5);
	}

	else if(n==4)
	cout<<"iv";
	else if(n==3)
	cout<<"iii";
	else if(n==2)
	cout<<"ii";
	else if(n==1)
	cout<<"i";
	else
		return;
}
int main()
{
	int n;
	cout<<"Enter a number"<<endl;
	cin>>n;
	roman(n);

return 0;

}
