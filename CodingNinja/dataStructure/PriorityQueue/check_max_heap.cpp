/*

Check Max-Heap

Given an array of integers, check whether it represents max-heap or not.
Return true or false.
Input Format :
Line 1 : An integer N i.e. size of the array
Line 2 : N integers which are elements of the array, separated by spaces
Output Format :
true if it represents max-heap and false if it is not a max-heap
Constraints :
1 <= N <= 10^5
1 <= Ai <= 10^5

*/


bool checkMaxHeap(int a[], int n){
   
  int l,r;
  for(int i=0;i<n;i++){
    l=2*i+1;
    r=2*i+2;
    
    if((l<n && a[l]>a[i]) || (r<n && a[r] > a[i]))
      return false;
  }
  
  return true;
  
  
}

int main(){

return 0;

}
