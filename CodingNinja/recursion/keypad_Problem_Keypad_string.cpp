#include<iostream>
#include<string>
using namespace std;
string getString(int x)
{
  string key[8];
  key[0]="abc";
  key[1]="def";
  key[2]="ghi";
  key[3]="jkl";
  key[4]="mno";
  key[5]="pqrs";
  key[6]="tuv";
  key[7]="wxyz";
  return key[x-2];
}
int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
  if(num==0 || num==1)
  {
    output[0]="";
    return 1;
  }
  
  int n=num%10;
  string s=getString(n);
  int SmallOutput=keypad(num/10,output);
  int k=SmallOutput;
  
  for(int i=1;i<s.size();i++)
  {
  for(int p=0,j=k;p<SmallOutput,j<k+SmallOutput;p++,j++)
		output[j]=output[p];
    k=k+SmallOutput;
  }
  
  k=SmallOutput;
  for(int i=1;i<=s.size();i++)
  {
  	for(int p=0;p<SmallOutput;p++)
		output[p+k]=s[i]+output[p];
    
    	k=k+SmallOutput;
	}
  
  for(int i=0;i<SmallOutput;i++)
    output[i]=s[0]+output[i];

return SmallOutput*s.size();
}
int main()
{
	int n;
	cin>>n;
	string output[1000];	
	int x=keypad(n,output);
for(int i=0;i<x;i++)
	cout<<output[i]<<endl;
}
