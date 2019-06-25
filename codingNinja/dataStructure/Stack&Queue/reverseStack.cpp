/*

Reverse Stack

Reverse a given Stack with the help of another empty stack. Two stacks will be given. Out of which first contains some integers and second one is empty. You need to reverse the first one using second stack. Change in the given first stack itself.
Note : You don't need to print or return the stack, just reverse the given stack and it will be printed internally.
Input format :

Line 1 : Size of Stack
Line 2 : Stack elements (separated by space)

Sample Input 1 :

4 
1 2 3 4     (4 is at top)

Sample Output 1 :

1 2 3 4    (1 is at top)



*/

#include <stack>

/*
// according to question wrong method:-

void reverseStack(stack<int> &input, stack<int> &extra) {
	// Write your code here
  while(!input.empty()){ 
  extra.push(input.top());
    input.pop();
  }
  stack <int > s=input;
  input=extra;
  extra=s;
}
*/

// right method:-

void reverseStack(stack<int> &input, stack<int> &extra) {
  
 	if(input.empty())
      return;
  int a= input.top();
  input.pop();
  reverseStack(input,extra);
  while(!input.empty())
  {
    extra.push(input.top());
    input.pop();
  }
  input.push(a);
  while(!extra.empty())
  {
    input.push(extra.top());
    extra.pop();
  }
 }
