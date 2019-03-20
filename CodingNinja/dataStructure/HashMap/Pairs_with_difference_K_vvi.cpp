
/*
Pairs with difference K

You are given with an array of integers and an integer K. Write a program to find and print all pairs which have difference K.
Best solution takes O(n) time. And take difference as absolute.
Input Format :
Line 1 : Integer n, Size of array
Line 2 : Array elements (separated by space)
Line 3 : K
Output format :
Print pairs in different lines (pair elements separated by space). In a pair, smaller element should be printed first.
(Order of different pairs is not important)
Constraints :
1 <= n <= 5000
Sample Input 1 :
4 
5 1 2 4
3
Sample Output 1 :
2 5
1 4
Sample Input 2 :
4
4 4 4 4 
0
Sample Output 2 :
4 4
4 4
4 4
4 4
4 4
4 4

*/


//this is very important question

#include<unordered_map>

void printPairs(int *a, int n, int k) {
	unordered_map<int,int> map;
 
  int i=0;
  while(i<n){
    map[a[i]]++;
    i++;
  }
  
  for(int i=0;i<n;i++){
    if (k==0)
    {
      int count=map[a[i]]*(map[a[i]]-1)/2;
      for(int j=0;j<count;j++)
        cout<<a[i]<<" "<<a[i]<<endl;
      map[a[i]]=0;
      continue;
    }
	else
    {
      //int element1=a[i]-k;
      //int element2=a[i]+k;
      int count1=map[a[i]]*map[a[i]-k];
      int count2=map[a[i]]*map[a[i]+k];
      
      while(count1>0){
        cout<<a[i]-k<<" "<<a[i]<<endl;
        count1--;
      }
      while(count2 > 0){
      cout<<a[i]<<" "<<a[i]+k<<endl;
        count2--;
      }
      
      map[a[i]]=0;
    }
    
  
	}
  
}
