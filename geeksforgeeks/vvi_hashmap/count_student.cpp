/*
Given N students with marks obtained by them in an exam. The task is to count the students with same name and marks.

Input: First line of input contains number of testcases T. For each testcase, first line of input contains N, number of students. Next N lines contains students name and his marks.

Output: For each testcase, print students name, marks and count of same student with same name and marks, all seperated by space. The output is sorted in lexigraphically sorted order of names and if two names are same then those are sorted in decreasing order of marks.

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


*/

#include <iostream>
#include<algorithm>
#include<utility>
#include <boost/functional/hash.hpp>
#include<unordered_map>
#include<vector>
using namespace std;
bool compare(pair<pair<string,int>,int> a , pair<pair<string,int>,int> b){
    if(a.first.first < b.first.first){
        return true;
    }
    else if (a.first.first==b.first.first){
        return a.first.second > b.first.second;
    }
    else{
        return false;
    }
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    unordered_map<pair<string,int>,int, boost::hash<pair<string,int>> >map;
	    for(int i=0;i<n;i++){
	        string name;
	        int marks;
	        cin>>name>>marks;
	        pair<string,int> p(name,marks);
	        if(map.find(p)!=map.end()){
	            map[p]+=1;
	        }
            else{
                map[p]=1;
            }
	    }
	    vector< pair< pair<string,int> , int > > v;
	    for(auto p:map){
	        v.push_back(make_pair(p.first,p.second));
	    }
	    int a[]={2,3,4,5,0,0,0};
	   
	   sort(v.begin(),v.end(),compare);
	    for(auto p:v){
	        cout<<p.first.first<<" "<< p.first.second<<" "<< p.second <<endl;
	    }
	    v.clear();
	    map.clear();
	}
	return 0;
}