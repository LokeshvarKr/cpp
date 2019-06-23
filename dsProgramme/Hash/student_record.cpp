
//An interesting  problem solved by using Hash map
/*


Given N students with marks obtained by them in an exam. The task is to 
count the students with same name and same marks.

Input: First line of input contains number of testcases T. 
For each testcase, first line of input contains N, number of students. 
Next N lines contains students name and his marks.

Output: For each testcase, print students name, marks and count of same 
student with same name and marks, all seperated by space. The output is sorted in 
lexigraphically sorted order of names and if two names are same then those are sorted in decreasing order of marks.

Constraints:
1 <= T <= 100
1 <= N <= 104
1 <= marks <= 106

Example:
Input:
1
5
john 50
ankit 100
ankit 100
john 60
ankit 30

Output:
ankit 100 2
ankit 30 1
john 60 1
john 50 1

Example:
Testcase 1: 
ankit with marks 100 occurs two times.
ankit with marks 30 occurs one time.
john with marks 60 occurs once.
john with marks 50 occurs once.
 


*/

#include<iostream>
#include<map>
using namespace std;
int main()
 {
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    string name;
    int marks;
    
    map < string , map<int , int , greater <int> > > m;
    for(int i=0;i<n;i++){
        cin>>name>>marks;
        m[name][marks]+=1;
    }
    
    for(auto x:m){
        for(auto y : x.second){
            cout<<x.first<<" "<<y.first<<" "<<y.second<<endl;
        }
    }
    
    }
	return 0;
}