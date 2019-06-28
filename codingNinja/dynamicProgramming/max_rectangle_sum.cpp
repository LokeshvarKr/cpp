
/*
Maximum Sum Rectangle

Given a 2D array, find the maximum sum rectangle in it. In other words find maximum sum over all rectangles in the matrix.
Input
First line contains 2 numbers n and m denoting number of rows and number of columns. Next n lines contain m space separated integers denoting elements of matrix nxm.
Output
Output a single integer, maximum sum rectangle.
Constraints
1<=n,m<=100
Sample Input
4 5
1 2 -1 -4 -20
-8 -3 4 2 1
3 8 10 1 3
-4 -1 1 7 -6
Sample Output
29

*/


#include <bits/stdc++.h>
using namespace std;
#define SIZE 110


// simple solution o(n^4)
/*
int find_max_sum_rectangle(int A[SIZE][SIZE],int n,int m){
    int R[n][m];
    int max_sum=INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            //sum
            int sum=0;
            for(int l=i;l<n;l++){
                for(int r=j;r<m;r++){
                    sum+=A[l][r];
                }
            }
            R[i][j]=sum;
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int l=i;l<n;l++){
                for(int r=j;r<m;r++){
                    
                    int down=0,right=0,diagonal=0;
                    if(l+1 < n)down=R[l+1][j];
                    if(r+1 < m)right=R[i][r+1];
                    if(l+1 < n && r+1 < m)diagonal=R[l+1][r+1];
                    int curr_sum=R[i][j]-(down+right-diagonal);
                    if(curr_sum > max_sum){
                        max_sum=curr_sum;
                    }
                }
            }
        }
    }
    
    return max_sum;
}
*/



// dp solution o(n^3)
int kadane_algo(int s[],int n){
    int max_sum=INT_MIN,curr_sum=0;
    for(int i=0;i<n;i++){
        curr_sum+=s[i];
        if(max_sum < curr_sum){
            max_sum=curr_sum;
        }
        if(curr_sum < 0){
            curr_sum=0;
        }
    }
    return max_sum;
}
int find_max_sum_rectangle(int A[SIZE][SIZE],int n,int m){
    int s[n];
    for(int k=0;k<n;k++){
        s[k]=0;
    }
    int max_sum=INT_MIN;
    for(int i=0;i<m-1;i++){
        for(int j=i;j<m;j++){
            for(int k=0;k<n;k++){
                s[k]+=A[k][j];
            }
            int curr_sum=kadane_algo(s,n);
            if(max_sum < curr_sum){
                max_sum=curr_sum;
            }
        }
        for(int k=0;k<n;k++){
            s[k]=0;
        }
    }
    return max_sum;
}

int main()
{
    int A[SIZE][SIZE];
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>A[i][j];
        }
    }
    int max_sum=find_max_sum_rectangle(A,n,m);
    cout<<max_sum<<endl;
    return 0;
}
