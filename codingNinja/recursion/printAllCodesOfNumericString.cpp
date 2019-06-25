/*
Print all Codes - String

Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to print the list of all possible codes that can be generated from the given string.
Note : The order of codes are not important. Just print them in different lines.
Input format :

A numeric string S

Output Format :

All possible codes in different lines

Constraints :
1 <= Length of String S <= 10
Sample Input:

1123

Sample Output:

aabc
kbc
alc
aaw
kw



*/
#include <string.h>
using namespace std;
void print(string input,string output,string option[])
{
  if(input.length()==0)
  {
    cout<<output<<endl;
    return;
  }
  	string temp=output;
    int num=int(input[0]-48);
    string alpha=option[num];
    output=output+alpha;
  
   	print(input.substr(1),output,option);
  
  if(input[1]!='\0')
  {
  	int num1=int(input[1]-48);
  	int num2=10*num+num1;
  	if(num2>9 && num2<27)
    {
  		string beta=option[num2];
  		output=temp+beta;
  		print(input.substr(2),output,option);
    }
  }
}
void printAllPossibleCodes(string input) {
    /*
    Given the input as a string, print all its possible combinations. You do not need to return anything.
    */
  string output="";
  string option[27]={""};
  for(int i=1;i<=26;i++)
  option[i]=option[i]+char(i+96);
  print(input,output,option);
}

int main()
{



}
