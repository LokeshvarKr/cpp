/*

Given an array A of size N having distinct elements, the task is to find the next greater element for each element of the array in order of their appearance in the array. If no such element exists, output -1 

Input:
The first line of input contains a single integer T denoting the number of test cases.Then T test cases follow. Each test case consists of two lines. The first line contains an integer N denoting the size of the array. The Second line of each test case contains N space separated positive integers denoting the values/elements in the array A.

Output:
For each test case, print in a new line, the next greater element for each array element separated by space in order.

Constraints:
1 <= T <= 100
1 <= N <= 107
1 <= Ai <= 1018
Example:
Input
1
4
1 3 2 4 
Output
3 4 4 -1

*/


#include<iostream>
#include<stack>
using namespace std;
int main()
 {
    int n;
    cin>>n;
    long long *a=new long long[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    long long *output=new long long[n]();
    stack<int> s;
    s.push(0);
    for(int i=1;i<n;i++){
        while(!s.empty() && a[s.top()] < a[i]){
            output[s.top()]=a[i];
            s.pop();
        }
        
        s.push(i);
        
    }
    
    while(!s.empty()){
        output[s.top()]=-1;
        s.pop();
    }
    for(int i=0;i<n;i++){
        cout<<output[i]<<" ";
    }
    cout<<endl;
    
    delete [] a;
    delete [] output;
    
	return 0;
}