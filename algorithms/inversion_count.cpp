

/*

Inversion Count

Let A[0 ... n-1] be an array of n distinct positive integers. 
If i < j and A[i] > A[j] then the pair (i, j) is called an 
inversion of A (where i and j are indexes of A). Given an 
integer array A, your task is to find the number of inversions in A.

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


long long merge(int A[],int s,int mid,int e){
    int n1=mid-s+1;
    int n2=e-mid;
    int a[n1];
    int b[n2];
    for(int i=0;i<n1;i++){
        a[i]=A[s+i];
    }
    for(int j=0;j<n2;j++){
        b[j]=A[mid+j+1];
    }
    long long count=0;
    int i=0,j=0,k=s;
    while(i<n1 && j<n2){
        if(a[i] > b[j]){
            count+=(n1-i);
            A[k++]=b[j++];
        }
        else{
            A[k++]=a[i++];
        }
    }
    while(i<n1){
        A[k++]=a[i++];
    }
    while(j<n2){
        A[k++]=b[j++];
    }
    return count;
}


long long  merge_sort(int A[],int s,int e){
    long  long count=0;
    if(s<e){
        int mid=s+(e-s)/2;
        count = merge_sort(A,s,mid);
        count += merge_sort(A,mid+1,e);
        count += merge(A,s,mid,e);
    }
    return count;
}
long long inversion_count(int A[], int n)
{
    //using merge_sort algorithm
	long long count=merge_sort(A,0,n-1);
    return count;
}