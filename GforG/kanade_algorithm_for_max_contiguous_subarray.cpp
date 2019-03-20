#include<iostream>
#include<climits>
using namespace std;
//brute force 

/*
int main()
{
    int t;
    cin>>t;
    int n;
    while(t--){
    cin>>n;
    
    int *a=new int [n];
    
    for(int i=0;i<n;i++)cin>>a[i];
    
    int maxSum=INT_MIN;
    int sum;
    
    for(int i=0;i<n;i++){
        
        for(int j=i;j>=0;j--){
            sum=0;
            for(int k=i;k>=j;k--){
                sum+=a[k];
            }
            
            if(maxSum<sum)
            maxSum=sum;
        }
        
    }
    
    cout<<maxSum<<endl;
    
    delete [] a;
    
    }
    
	return 0;
}

*/


/*


Kadane’s Algorithm:

Initialize:
    max_so_far = 0
    max_ending_here = 0

Loop for each element of the array
  (a) max_ending_here = max_ending_here + a[i]
  (b) if(max_ending_here < 0)
            max_ending_here = 0
  (c) if(max_so_far < max_ending_here)
            max_so_far = max_ending_here
return max_so_far
Explanation:
Simple idea of the Kadane’s algorithm is to look for all positive contiguous segments of the array (max_ending_here is used for this). And keep track of maximum sum contiguous segment among all positive segments (max_so_far is used for this). Each time we get a positive sum compare it with max_so_far and update max_so_far if it is greater than max_so_far



*/

int main(){
    int t;
    cin>>t;
    int n;
    while(t--){
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        
        int max_so_far=INT_MIN;
        int max_end_here=0;
        
        for(int i=0;i<n;i++){
            max_end_here+=a[i];
            if(max_so_far<max_end_here)max_so_far=max_end_here;
            if(max_end_here<0)max_end_here=0;

        }
        cout<<max_so_far<<endl;
    }
    
    return 0;
}



