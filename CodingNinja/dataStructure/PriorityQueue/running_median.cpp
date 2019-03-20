/*
Running median

You are given a stream of n integers. For every ith integer, add it to the running list of integers and print the resulting median (of the list till now).
Print the only integer part of median.
Input Format :
Line 1 : An integer N denoting the number of integers in the stream
Line 2 : N integers which are separated by spaces
Output Format :
After each new integer is added to the list print the updated median on a new line
Input Constraints
1 <= n <= 10^5
1 <= Ai <= 10^5
Sample Input 1 :
6
6 2 1 3 7 5
Sample Output 1 :
6
4
2
2
3
4
Sample Output explanation :
S = {6}, median = 6
S = {6, 2} -> {2, 6}, median = 4
S = {6, 2, 1} -> {1, 2, 6}, median = 2
S = {6, 2, 1, 3} -> {1, 2, 3, 6}, median = 2
S = {6, 2, 1, 3, 7} -> {1, 2, 3, 6, 7}, median = 3
S = {6, 2, 1, 3, 7, 5} -> {1, 2, 3, 5, 6, 7}, median = 4

*/


#include<iostream>
using namespace std;

//method 1 time comp o(n^2)

void findMedian(int arr[], int n){
   
  int a[n];
  for(int i=0;i<n;i++){
    a[i]=arr[i];
  }
  for(int i=0;i<n;i++){
    for(int j=i-1;j>=0;j--){
      if(a[j]>a[j+1]){
        int temp=a[j];
        a[j]=a[j+1];
        a[j+1]=temp;
      }
    }
    
    if(i%2==0)
      cout<<a[i/2]<<endl;
    else{
      int x=(a[i/2]+a[(i/2)+1])/2;
      cout<<x<<endl;
    }
    
  }
  
  return ;

}


//method 2 


/*

Create two heaps. One max heap to maintain elements of lower half and one min heap to maintain elements of higher half at any point of time..
Take initial value of median as 0.
For every newly read element, insert it into either max heap or min heap and calulate the median based on the following conditions:
If the size of max heap is greater than size of min heap and the element is less than previous median then pop the top element from max heap and insert into min heap and insert the new element to max heap else insert the new element to min heap. Calculate the new median as average of top of elements of both max and min heap.
If the size of max heap is less than size of min heap and the element is greater than previous median then pop the top element from min heap and insert into max heap and insert the new element to min heap else insert the new element to max heap. Calculate the new median as average of top of elements of both max and min heap.
If the size of both heaps are same. Then check if current is less than previous median or not. If the current element is less than previous median then insert it to max heap and new median will be equal to top element of max heap. If the current element is greater than previous median then insert it to min heap and new median will be equal to top element of min heap.


*/
#include<queue>

void findMedian(int arr[], int n){
priority_queue<int> max_pq;
priority_queue<int,vector<int>,greater<int> > min_pq;
  
  max_pq.push(arr[0]);
  int median=arr[0];
  cout<<median<<endl;
  
  for(int i=1;i<n;i++){
    
    if(max_pq.size() > min_pq.size() && arr[i] >= median){
      
      min_pq.push(arr[i]);
      median=(min_pq.top() + max_pq.top() )/2;
      cout<<median<<endl;
    }
    else if(max_pq.size() > min_pq.size() && arr[i] < median ){
      min_pq.push(max_pq.top());
      max_pq.pop();
      max_pq.push(arr[i]);
      median=(max_pq.top()+min_pq.top())/2;
      cout<<median<<endl;
    }
    
    else if(max_pq.size() < min_pq.size() && arr[i] >= median ){
      max_pq.push(min_pq.top());
      min_pq.pop();
      min_pq.push(arr[i]);
      median=(max_pq.top()+min_pq.top())/2;
      cout<<median<<endl;
    }
    else if(max_pq.size() < min_pq.size() && arr[i] < median ){
      max_pq.push(arr[i]);
      median=(min_pq.top() + max_pq.top())/2;
      cout<<median<<endl;
    }
    
    else if(max_pq.size() == min_pq.size() && arr[i] >= median ){
      min_pq.push(arr[i]);
      median=min_pq.top();
      cout<<median<<endl;
    }
    
    //max_pq.size() < min_pq.size() && median < arr[i]
    else  {
      max_pq.push(arr[i]);
      median=max_pq.top();
      cout<<median<<endl;
    }
    
  }
  
}



