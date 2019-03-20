/*
Minimum bracket Reversal

Given a string expression which consists only ‘}’ and ‘{‘. The expression may not be balanced. You need to find the minimum number of bracket reversals which are required to make the expression balanced.
Return -1 if the given expression can't be balanced.
Input Format :

String S

Output Format :

Required count

Sample Input 1 :

{{{

Sample Output 1 :

-1

Sample Input 2 :

{{{{}}

Sample Output 2 :

1

//sample input }}{{, }}}{{{{{, }}}}}}{{{ 

*/
#include<stack>
int countBracketReversals(char input[]){
	// Write your code here
 stack<char>s;
  int i=0;
  while(input[i]!='\0')
  {
    if(input[i]=='{')
    {
      s.push(input[i]);
      i++;
    }
    else 		//(input[i]=='}')
    {
     if(s.empty() || s.top()=='}')
       s.push(input[i]);
      else 				//(input[i]=='{')
        s.pop();
      
        i++;
    }
    
  }
  
  int count=0;
  while(!s.empty() && s.size()>=2)
  {
    char c1=s.top();
    s.pop();
    char c2=s.top();
    s.pop();
    
    if(c1==c2)
      count+=1;
    if(c1=='{' && c2=='}')
      count+=2;
  }
  
  if(s.size()==1)
    return -1;
  else return count;
  
}

