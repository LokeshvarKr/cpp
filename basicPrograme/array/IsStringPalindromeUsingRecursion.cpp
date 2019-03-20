#include<iostream>
#include<string.h>
using namespace std;

bool check(char input[],int p,int q)
{
  if(p==q && input[p]==input[q])
    return true;
  if(p+1==q && input[p]==input[q])
    return true;
  if(input[p]!=input[q])
    return false;
    bool ans=check(input,p+1,q-1);
  return ans;
}
 bool checkPalindrome(char input[]) {
    // Write your code here
  int n=strlen(input);
    if(n==0)
      return true;
  return check(input,0,n-1);
}


using namespace std;
int main()
{
char input[50];
cin>>input;
cout<<checkPalindrome(input);
return 0;
}
