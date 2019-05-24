/*

Given an array arr and a number K where K is smaller than size of array, the task is to find the K’th smallest element in the given array. It is given that all array elements are distinct.

Expected Time Complexity: O(n)

Input:
The first line of input contains an integer T, denoting the number of testcases. Then T test cases follow. Each test case consists of three lines. First line of each testcase contains an integer N denoting size of the array. Second line contains N space separated integer denoting elements of the array. Third line of the test case contains an integer K.

Output:
Corresponding to each test case, print the desired output in a new line.

Constraints:
1 <= T <= 100
1 <= N <= 105
1 <= arr[i] <= 105
1 <= K <= N

Example:
Input:
2
6
7 10 4 3 20 15
3
5
7 10 4 20 15
4

Output:
7
15

Explanation:
Testcase 1: 3rd smallest element in the given array is 7.

*/



#include<iostream>
#include<stdio.h>
using namespace std;

// Method 1: using c++ algorithm for MinHeap 
/*
#include<algorithm>
class greaters{
    public:
  bool operator()(const long& a,const long& b) const{ 
    return a>b; 
  } 
};

void kthSmallest(int *a,int n,int k){
     make_heap(a,a+n,greaters());
        int temp=0;
        for(int i=0;i<k;i++){
            temp=a[0];
            pop_heap(a,a+n,greaters());
            n=n-1;
        }
        cout<<temp<<endl;
}
*/

//Method 2 : using c++ min priority queue
/*
#include<queue>
void kthSmallest(int *a,int n,int k){
    priority_queue<int,vector<int> , greater<int> > pq;
    for(int i=0;i<n;i++){
        pq.push(a[i]);
    }
    int temp=0;
    for(int i=0;i<k;i++){
        temp=pq.top();
        pq.pop();
    }
    cout<<temp<<endl;
}
*/

//Method 3: using MinHeap

/*void min_heapify(int a[],int i,int n){
    int left=2*i+1;
    int right=2*i+2;
    int min_index=i;
    if(left < n && a[left] < a[min_index]){
        min_index=left;
    }
    if(right < n && a[right] < a[min_index]){
        min_index=right;
    }
    if(min_index!=i){
        int temp=a[i];
        a[i]=a[min_index];
        a[min_index]=temp;
        min_heapify(a,min_index,n);
    }
    
}

void build_min_heap(int a[],int n){
    for(int i=n/2;i>=0;i--){
        min_heapify(a,i,n);
    }
}
void kthSmallest(int a[],int n,int k){
   build_min_heap(a,n);
   int temp=0;
   for(int i=0;i<k;i++){
       temp=a[0];
       a[0]=a[n-1];
       n=n-1;
       min_heapify(a,0,n);
   }
    printf("%d\n",temp);
}
*/

// Method 4: using MaxHeap

void max_heapify(int a[],int i,int n){
    int left=2*i+1;
    int right=2*i+2;
    int max_index=i;
    if(left < n && a[left] > a[max_index]){
        max_index=left;
    }
    if(right < n && a[right] > a[max_index]){
        max_index=right;
    }
    if(max_index!=i){
        int temp=a[i];
        a[i]=a[max_index];
        a[max_index]=temp;
        max_heapify(a,max_index,n);
    }
    
}

void build_max_heap(int a[],int n){
    for(int i=n/2;i>=0;i--){
        max_heapify(a,i,n);
    }
}
void kthSmallest(int arr[],int n,int k){
    int *a=new int[k];
    for(int i=0;i<k;i++){
        a[i]=arr[i];
    }
    
    build_max_heap(a,k);
    
    for(int i=k;i<n;i++){
       if(arr[i]<a[0]){
           a[0]=arr[i];
           max_heapify(a,0,k);
       }
   }
    printf("%d\n",a[0]);
    delete [] a;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n;
        int *a=new int [n];
        for(int i=0;i<n;i++){
            scanf("%d",a+i);
        }
        scanf("%d",&k);
        kthSmallest(a,n,k);
        delete [] a;
    }
	return 0;
}
