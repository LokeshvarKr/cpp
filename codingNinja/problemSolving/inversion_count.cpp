/*


Inversion Count


Let A[0 ... n-1] be an array of n distinct positive integers. If i < j and A[i] > A[j] then the pair (i, j) is called an inversion of A (where i and j are indexes of A). Given an integer array A, your task is to find the number of inversions in A.
Input format :
Line 1 : n, array size
Line 2 : Array elements (separated by space).
Output format :
Count of inversions
Constraints :
1 <= n <= 10^5
1 <= A[i] <= 10^9
Sample Input 1 :
3
3 2 1
Sample Output 1 :
3
Sample Input 2 :
5
2 5 1 3 4
Sample Output 1 :
4


*/



long long merge(int A[],int p,int q,int r){
  int n1=q-p+1;
  int n2=r-q;
  int *a=new int[n1];
  int *b=new int[n2];
  
  int count=0;
  int i=0,j=0,k=p;
  
  while(i<n1)
    a[i++]=A[k++];
  
  while(j<n2)
    b[j++]=A[k++];
  
  i=0;
  j=0;
  k=p;
  
  while(i<n1 && j<n2){
    if(a[i]<=b[j]){
      A[k++]=a[i++];
    }
    else {
      A[k++]=b[j++];
      count=count+(n1-i);
    }
  }
  
  while(i<n1){
    A[k++]=a[i++];
  }
  
  while(j<n2){
    A[k++]=b[j++];
  }
  
  delete [] a;
  delete [] b;
  
  return count;
}

long long mergesort(int A[],int p,int r){
	if(p<r){
      int q=(p+r)/2;
      long long x=mergesort(A,p,q);
      long long y=mergesort(A,q+1,r);
      long long z=merge(A,p,q,r);
      
      return x+y+z;
    }
  return 0;
} 


long long solve(int A[], int n){
	
  return mergesort(A,0,n-1);
  
}
