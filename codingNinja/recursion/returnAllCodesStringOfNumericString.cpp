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

// very good approach
#include <string.h>
using namespace std;

int getCodes(string input, string output[10000]) {
    /*
    You are given the input text and output string array. Find all possible codes and store in the output string array. Don’t print the codes.
    Also, return the number of codes return to the output string. You do not need to print anything.
    */
  if(input.length()==0)
  {
    output[0]="";
    return 1;
  }
 	string *temp1=new string[10000];
	string *temp2=new string[10000];
  
    int ans1=getCodes(input.substr(1),temp1);
  
  int x1=int(input[0]-48);
  char c1=char('a'+x1-1);
  
  for(int i=0;i<ans1;i++)
    output[i]=c1+temp1[i];
  
  if(input[1]!='\0')
  {
    int ans2=0;
    int x2=int(input[1]-48);
    int x3=x1*10+x2;
    if(x3>9 && x3<27)
    {
  		char c2=char('a'+x3-1);
      
       	ans2=getCodes(input.substr(2),temp2);
      
      for(int i=0;i<ans2;i++)
   		output[i+ans1]=c2+temp2[i];
    }
    return ans1+ans2;
  }
  else
  return ans1;
  
}

// verry good logic
#include <string>
using namespace std;

int getCodes(string input, string output[10000]) {
    /*
    You are given the input text and output string array. Find all possible codes and store in the output string array. Don’t print the codes.
    Also, return the number of codes return to the output string. You do not need to print anything.
    */
  if(input.length()==1)
  {
    int x1=int(input[0]-48);
  	char c1=char('a'+x1-1);
    output[0]=c1;
    return 1;
  }
  
  
  int ans=getCodes(input.substr(1),output);
  int x1=int(input[0]-48);
  char c1=char('a'+x1-1);
  string temp[10000];
  for(int i=0;i<ans;i++)
    temp[i]=output[i];
  
  for(int i=0;i<ans;i++)
    output[i]=c1+output[i];
  
  int x2=int(input[1]-48);
  int x3=x1*10+x2;
      int i=0;
  if(x3>9 && x3<27)
  {
  char c2=char('a'+x3-1);
    string alpha=temp[0];
    string beta=alpha;
    while(alpha[0]==beta[0])
    {
  	output[ans+i]=c2+temp[i].substr(1);
      i++;
    beta=temp[i];
    }
  }
  return ans+i;
}

/*
#include <string>
using namespace std;

int Codes(string input, string output[10000],string options[])
{
  if(input.size()==1)
  {
    int num=input[0]-48;
    string alpha=options[num];
    output[0]=alpha;
    return 1;
  }
  
  int count=Codes(input.substr(1),output,options);
  
  string temp[100];
  for(int i=0;i<count;i++)
  {
    temp[i]=output[i];
  }
  int num=input[0]-48;
  string alpha=options[num];
  int x=0;
  for(int i=0;i<count;i++)
  {
    output[i]=alpha+temp[i];
    x++;
  }
  
  int num1=input[1]-48;
  int num2=(num*10)+num1;
  string adder=options[num2];
  int i=0;
  string beta=temp[0];
  string beta1=beta;
  if(num2>9&&num2<27)
  {
    while(beta[0]==beta1[0])
    {
      string left=temp[i];
      output[x+i]=adder+left.substr(1);
      i++;
      beta1=temp[i];
    }
  }
  
  return x+i;
}

int getCodes(string input, string output[10000]) 
{


  string options[30]={""};
  for(int i=1;i<=26;i++)
  {
    options[i]=char(i+96);
  }
  return Codes(input,output,options); 

}

*/
