/*
Return Permutations - String

Given a string S, find and return all the possible permutations of the input string.
Note 1 : The order of permutations is not important.
Note 2 : If original string contains duplicate characters, permutations will also be duplicates.
Input Format :

String S

Output Format :

All permutations (in different lines)

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

// good way 

#include <string>
using namespace std;

int returnPermutations(string input, string output[]){
   	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
  if(input.length()==1)
  {
    output[0]=input[0];
    return 1;
  }
  string *temp=new string[1000];
  char s=input[0];
  int ans=returnPermutations(input.substr(1),temp);
  int k=0;
  for(int i=0;i<ans;i++)
  {
    string alpha=temp[i];
    int n=alpha.length();
    for(int j=0;j<=n;j++)
    {
      output[k]=alpha.substr(0,j)+s+alpha.substr(j);
      k++;
    }
  }
  return k;
}


//Another way

#include <string>
using namespace std;

int returnPermutations(string input, string output[]){
   	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
  
  if(input.empty())
  {
    output[0]="";
    return 1;
  }
  	string s1="";
  	string s2="";
  	string s="";
  	int ans=0;
  	for(int i=0;i<input.size();i++)
    {
      char c=input[i];
      s1=input.substr(0,i);
      s2=input.substr(i+1,input.size()-i);
      s=s1+s2;
      string out1[10000];
     ans=returnPermutations(s,out1);
      for(int j=0;j<ans;j++)
      {
        output[j+(i*ans)]=c+out1[j];
      }
    }
  	return ans*input.size();
}
int main()
{


}

