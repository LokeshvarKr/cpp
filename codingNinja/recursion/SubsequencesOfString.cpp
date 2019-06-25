#include<iostream>
#include<math.h>
using namespace std;
int subsequences(string input,string output[])
{
	if(input.empty())
	{	
		output[0]="";
		return 1;
	}
	string SmallString=input.substr(1);
	int SmallOutput=subsequences(SmallString,output);
	for(int i=0;i<SmallOutput;i++)
	output[i+SmallOutput]=input[0]+output[i];
	return 2*SmallOutput;
}
int main()
{
	string input;
	cin>>input;
	int n=input.size();
	n=pow(2,n);
	string *output=new string[n];
	int count=subsequences(input,output);
	for(int i=0;i<count;i++)
	cout<<output[i]<<endl;
	return 0;
}
