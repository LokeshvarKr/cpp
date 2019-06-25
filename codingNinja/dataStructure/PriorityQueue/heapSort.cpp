
#include<iostream>
using namespace std;
void inplaceHeapSort(int input[], int n){
  
  for(int i=0;i<n;i++){
    int childIndex=i;
    while(childIndex > 0){
    	int parentIndex=(childIndex-1)/2;
      	if(input[childIndex] < input[parentIndex]){
          int temp=input[childIndex];
          input[childIndex]=input[parentIndex];
          input[parentIndex]=temp;
        }
      	else break;
      	
      	childIndex=parentIndex;
      	
    }
    
  }
  

  //here can be use while(n>0) instead of this for loop
  for(int i=n;i>0;i--){		
    
    int min=input[0];
    input[0]=input[n-1];
    input[n-1]=min;
    n=n-1;
    int parentIndex=0;
    int leftIndex=2*parentIndex+1;
    int rightIndex=2*parentIndex+2;
   
    while(leftIndex < n){
      int minIndex=parentIndex;
		if(input[leftIndex] < input[minIndex])
          minIndex=leftIndex;
      	if(rightIndex < n && input[rightIndex] < input[minIndex])
          minIndex=rightIndex;
      	
      	if(minIndex!=parentIndex){
          int temp=input[parentIndex];
          input[parentIndex]=input[minIndex];
          input[minIndex]=temp;
          
          parentIndex=minIndex;
          leftIndex=2*parentIndex+1;
          rightIndex=2*parentIndex+2;
          
        }
      	else break;
    }
    
  }

}
int main()
int n;
cin>>n;
int *a=new int [n];
for(int i=0;i<n;i++)cin>>a[i];
inplaceHeapSort(a,n);
for(int i=0;i<n;i++)cout<<a[i]<<" ";
delete [] a;

return 0;
}
