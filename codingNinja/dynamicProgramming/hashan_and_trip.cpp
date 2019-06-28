/*
Hasan and Trip

Hasan has finally finished his final exams and he decided to go in a trip among cities in Syria.
There are N cities in Syria and they are numbered from 1 to N, each city has coordinates on plane, 
i-th city is in (Xi, Yi).
Hasan is in first city and he wants to visit some cities by his car in the trip but the final destination 
should be N-th city and the sequence of cities he will visit should be increasing in index (i.e. if he is 
in city i he can move to city j if and only if i < j ).
Visiting i-th city will increase Hasan's happiness by Fi units (including first and last cities), also Hasan 
doesn't like traveling too much, so his happiness will decrease by total distance traveled by him.
Help Hasan by choosing a sequence of cities to visit which maximizes his happiness.

Input format:
First line contain integer N.
Next N lines contains three integers each, i-th line contains coordinates of i-th city Xi, Yi and Fi.

Output format:
Output one number rounded to 6 digits after floating point, the maximum possible happiness Hasan can get. Note: If answer is 2 print 2.000000

Constraints:
1 <= N <= 3,000
0 <= Xi, Yi, Fi <= 100,000

Sample Input 1
3
0 0 1
3 1 1
6 0 9
Sample Output 1
4.675445

Sample Input 2
37
14909 20840 26
2601 31760 14
35544 1338 24
64051 50195 8
18515 43348 6
25368 93435 21
86982 14016 30
36261 37288 29
88051 24899 43
36090 45220 1
89270 70285 4
33542 84226 48
24028 1935 21
14079 39350 21
55388 74277 18
69130 88144 45
23765 9452 24
45783 91035 18
3705 99971 19
36247 27152 32
66483 89502 7
56525 45862 13
51567 40579 46
94597 1039 0
19250 93999 24
10004 17562 42
2496 89967 38
32293 64570 31
91085 33694 1
20494 51339 19
47590 30238 23
56128 99737 50
7017 93409 19
94612 45078 48
81346 57197 6
11959 24210 5
8461 67309 39

Sample Output 2
-46849.226680


*/

#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    int *x=new int[n];
    int *y=new int[n];
    int *f=new int[n];
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i]>>f[i];
    } 
    double *ans=new double[n];
    ans[0]=f[0];
    for(int i=1;i<n;i++){
        ans[i]=INT_MIN;
        for(int j=0;j<i;j++){
            double d=sqrt( pow((x[i]-x[j]),2) + pow((y[i]-y[j]),2) );
            ans[i]=max(ans[i],ans[j]+f[i]-d);
        }
    } 
    cout<<fixed<<setprecision(6)<<ans[n-1]<<endl;
    
    delete [] x;
    delete [] y;
    delete [] f;
    delete [] ans;
    return 0;
}

/*
int main()
{
    int n;
    cin>>n;
    int *x=new int[n];
    int *y=new int[n];
    int *f=new int[n];
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i]>>f[i];
    }
    double **d=new double*[n];
    for(int i=0;i<n;i++){
        d[i]=new double[n];
        for(int j=i+1;j<n;j++){
            d[i][j]=sqrt( pow((x[i]-x[j]),2) + pow((y[i]-y[j]),2) );
        }
    }
   
    double *ans=new double[n];
    for(int i=0;i<n;i++){
        ans[i]=f[0];
    }
    for(int i=1;i<n;i++){
        ans[i]+=(f[i]-d[0][i]);
        for(int j=1;j<i;j++){
            double temp=ans[j] + f[i]-d[j][i];
            if(ans[i] < temp){
                ans[i]=temp;
            }
        }
    } 
    cout<<fixed<<setprecision(6)<<ans[n-1]<<endl;
    
    delete [] x;
    delete [] y;
    delete [] f;
    delete [] ans;
    for(int i=0;i<n;i++){
        delete [] d[i];
    }
    delete [] d;
    return 0;
}
*/