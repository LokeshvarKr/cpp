#include<string>
#include<iostream>
using namespace std;
void subsequences(string input,string output)
{
	if(input.length()==0)
	{
	cout<<output<<endl;
	return;
	}
	subsequences(input.substr(1),output);
	output=output+input[0];
	subsequences(input.substr(1),output);
	

}
int main()
{
	string input;
	cin>>input;
	string output="";
	subsequences(input,output);

	return 0;
}
