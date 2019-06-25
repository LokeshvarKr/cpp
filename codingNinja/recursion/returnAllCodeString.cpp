/*
Return all codes - String

Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to return the list of all possible codes that can be generated from the given string.
Note : The order of codes are not important. And input string does not contain 0s.
Input format :

A numeric string

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

int getCodes(string input, string output[10000]) {
    /*
    You are given the input text and output string array. Find all possible codes and store in the output string array. Don’t print the codes.
    Also, return the number of codes return to the output string. You do not need to print anything.
    */
  if(input.empty())
  {
    output[0]="";
    return 1;
  }
  string out1[10000];
  string out2[10000];
  
  int ans1=getCodes(input.substr(1),out1);
  
  int x=input[0]-'0';
  char p=char('a'+(x-1));
  
  for(int i=0;i<ans1;i++)
      output[i]=p+out1[i];
  
  	int y=input[1]-'0';
  	int z=10*x+y;
  	if(z>=10 && z<=26)
  	{
  		char q=char('a'+(z-1));
      
  		int ans2=getCodes(input.substr(2),out2);
      
      for(int i=ans1; i < ans2 + ans1;i++)
       output[i]=q+out2[i];
      
      return ans1+ ans2;
    }
   
 /* delete []out1;
  delete []out2;*/
  return ans1;
}


