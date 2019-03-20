/*
Print Permutations - String

Given a string, find and print all the possible permutations of the input string.
Note : The order of permutations are not important. Just print them in different lines.
Sample Input :

abc

Sample Output :

abc
acb
bac
bca
cab
cba


*/

//better approach

#include <iostream>
#include <string>
using namespace std;
void print(string input,char output[],int m){
  if(input.length()==0){
    cout<<output<<endl;
    return;
  }
  string s="";
  string s1="";
  string s2="";
  int n=input.length();
 for(int i=0;i<n;i++)
 {
   s1=input.substr(0,i);
     output[m]=input[i];
   s2=input.substr(i+1);
   s=s1+s2;
   print(s,output,m+1);
 }
  
}
void printPermutations(string input){

    	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
  char output[15];
  print(input,output,0); //int m=0
}

//another approach

#include <iostream>
#include <string>
using namespace std;
void print(string input,string output){
  if(input.length()==0){
    cout<<output<<endl;
    return;
  }
 for(int i=0;i<=output.length();i++)
   print(input.substr(1),output.substr(0,i)+input[0]+output.substr(i));
}
void printPermutations(string input){

    	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
  print(input,""); //int m=0
}


