/*
Return subset of an array

Given an integer array (of length n), find and return all the subsets of input array.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important.

Input format :

Line 1 : Size of array

Line 2 : Array elements (separated by space)
Sample Input:

3
15 20 12

Sample Output:

[] (this just represents an empty array, don't worry about the square brackets)
12 
20 
20 12 
15 
15 12 
15 20 
15 20 12 




*/

int subset(int input[], int n, int output[][20])
{
    // Write your code here
  if(n==0)
  {
    output[0][0]=0;
    return 1;
  }
  int x=subset(input+1,n-1,output);
  for(int i=0;i<x;i++)
  {
    output[i+x][0]=output[i][0]+1;
    
    output[i+x][1]=input[0];
    
    for(int j=2;j<=output[i+x][0];j++)
      output[i+x][j]=output[i][j-1];
  }
  return 2*x;
  
}
// another way
/*

int subset(int input[], int n, int output[][20]) {
    // Write your code here
	if(n==0)
    {
      output[0][0]=0;
      return 1;
    }
  int ans=subset(input,n-1,output);
  for(int i=0;i<ans;i++)
  {
    for(int j=1;j<=output[i][0];j++)
      output[i+ans][j]=output[i][j];
    
    output[i+ans][output[i][0]+1]=input[n-1];
    output[i+ans][0]=output[i][0]+1;

  }
  return 2*ans;
  
}
*/
int main()
{



return 0;
}
