/*
Given an expression string exp, examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
For example, the program should print 'balanced' for exp = “[()]{}{[()()]()}” and 'not balanced' for exp = “[(])”

 

Input:

The first line of input contains an integer T denoting the number of test cases. 
Each test case consist of a string of expression, in a separate line.

Output:

Print 'balanced' without quotes if pair of parenthesis are balanced else print 'not balanced' in a separate line.


Constraints:

1 ≤ T ≤ 100
1 ≤ |s| ≤ 100


Example:

Input:
3
{([])}
()
()[]

Output:
balanced
balanced
balanced



*/
#include <iostream>
#include<stack>
using namespace std;
bool IsPair(char s,char c)
{
    if(s=='(' && c==')')
    return true;
    if(s=='{' && c=='}')
    return true;
    if(s=='[' && c==']')
    return true;
    
    return false;
}
bool checkParenthesis(char *str){
    stack<char>s;
    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]=='(' || str[i]=='{' || str[i]=='[')
        s.push(str[i]);
        if(str[i]==')' || str[i]=='}' || str[i]==']')
        {
            if(!s.empty() && IsPair(s.top(),str[i]))
                s.pop();
            else
                return false;
        }
    }
    if(!s.empty())
    return false;
    
    return true;
}
int main() {
	int t,n;
	bool x;
	char *s=new char[100];
	cin>>t;
	for(int i=0;i<t;i++){
	    cin>>s;
	   if(checkParenthesis(s))
	   cout<<"balanced"<<endl;
	   else
	   cout<<"not balanced"<<endl;
	}
	
	delete s;
	return 0;
	
}
