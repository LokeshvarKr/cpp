/*

Magnet Array Problem Submissions: 2365   Accuracy: 37.82%   Difficulty: Medium   Marks: 4
Associated Course(s):
          
Given n Magnets which are placed linearly, with each magnet to be considered as of point object. Each magnet suffers force from its left sided magnets such that they repel it to the right and vice versa. All forces are repulsive. The force being equal to the distance (1/d , d being the distance). Now given the positions of the magnets, the task to find all the points along the linear line where net force is ZERO. 

Note: Distance have to be calculated with precision of 0.0000000000001.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. The second line of each test case contains an integer N. Then in the next line are N space separated values of the array M[], denoting the positions of the magnet.

Output:
For each test case in a new line print the space separated points having net force zero till precised two decimal places.

Constraints:
1<=T<=100
1<=N<=100
1<=M[]<=1000

Example:
Input:
2
2
1 2
4
0 10 20 30
Output:
1.50
3.82 15.00 26.18




*/
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
double binary_search(double l,double h,double* a,int n){
    double d=0.0000000000001;
    double m=(l+h)/(2.0);
    double force=0.0;
    for(int i=0;i<n;i++){
        force+=((1.0)/(m-a[i]));
    }
    if(abs(force) <= d){
        return m;
    }
    else if(force < 0){
        return binary_search(l,m,a,n);
    }
    else if(force > 0){
        return binary_search(m,h,a,n);
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        double *a=new double[n];
        
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        for(int  i=0;i<n-1;i++){
            double ans=binary_search(a[i],a[i+1],a,n);
            cout<<fixed<<setprecision(2)<<ans<<" ";
        }
        cout<<endl;
        delete [] a;
    }
	return 0;
}
