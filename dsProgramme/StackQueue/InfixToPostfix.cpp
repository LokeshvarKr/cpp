/*

Given an infix expression. Conver the infix expression to postfix expression.

Infix expression:The expression of the form a op b. When an operator is in-between every pair of operands.

Postfix expression:The expression of the form a b op. When an operator is followed for every pair of operands.

Input:

The first line of input contains an integer T denoting the number of test cases.
The next T lines contains an infix expression.The expression contains all characters and ^,*,/,+,-.

Output:
Output the infix expression to postfix expression.

Constraints:
1<=T<=100
1<=length of expression<=30

Example:
Input:
2
a+b*(c^d-e)^(f+g*h)-i
A*(B+C)/D

Output:
abcd^e-fgh*+^*+i-
ABC+*D/

*/


#include <iostream>
using namespace std;

class stack
{
    private:
        int TOP;
        char *ch;
    public:
    stack()
    {
        ch=new char[30];
        TOP=-1;
    }
    void push(char c)
    {
        TOP++;
        ch[TOP]=c;
    }
    void pop()
    {
        TOP--;
    }
    char top()
    {
        return ch[TOP];
    }
    bool empty()
    {
        if(TOP==-1)
        return true;
        else 
        return false;
    }
};
int OperandWeight(char c)
{
    switch(c)
    {
        case '-':
        case '+':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
}
bool IsPrecedenceHigh(char c,char s)
{
    if(OperandWeight(c)<=OperandWeight(s))
        return true;
        else 
        return false;
}
bool IsOperand(char c)
{
    if((c>=65 && c<=90) ||(c>=97 && c<=122))
        return true;
    else return false;
}
void InfToPost(char *exp)
{
    int j=0;
    char p[30];
    stack s;
    for(int i=0; exp[i]!='\0';i++)
    {
        if(IsOperand(exp[i]))
        p[j++]=exp[i];
        else if(exp[i]=='(')
        s.push(exp[i]);
        else if(exp[i]==')')
        {
            while(!s.empty() && s.top()!='(')
            {
                p[j++]=s.top();
                s.pop();
            }
            if(s.empty() || s.top()!='(')
            {
                cout<<"Invalid expression"<<endl;
                return;
            }
            s.pop();
        }
        else
        {
            while(!s.empty() && s.top()!='(' && IsPrecedenceHigh(exp[i],s.top()) )
            {
                p[j++]=s.top();
                s.pop();
            }
            s.push(exp[i]);
        }
    }
    while(!s.empty())
    {
        p[j++]=s.top();
        s.pop();
    }
    p[j]='\0';
    cout<<p<<endl;
    
}
int main()
{
	char exp[30];
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
	    cin>>exp;
	    InfToPost(exp);
	}
	return 0;
}
