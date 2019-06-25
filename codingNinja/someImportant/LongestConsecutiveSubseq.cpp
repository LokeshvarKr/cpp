/*
Longest Consecutive Subsequence Submissions: 5276   Accuracy: 26.1%   Difficulty: Easy   Marks: 2
       
Given an array A of integers. The task is to complete the function which returns an integer denoting the length of the longest sub-sequence such that elements in the sub-sequence are consecutive integers, the consecutive numbers can be in any order.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains an integer N. Then in the next line are N space separated values of the array A.

Output:
For each test case in a new line output will be the length of the longest consecutive increasing sub-sequence present in the array A[ ].

Constraints:
1 <= T <= 100
1 <= N <= 106
1 <= Ai <= 108

Example(To be used only for expected output):
Input:
2
7
1 9 3 10 4 20 2
11
36 41 56 35 44 33 34 92 43 32 42
Output:
4
5

Explanation:
Testcase 1: Logest consecutive subsequence is 1, 2, 3, 4 of length 4.
*/

//solution 1
//solution 2
//solution 3

/*
//python solution
def findLongestConseqSubseq(arr, n):
    # code here
    map={}
    length=0
    for e in arr:
        map[e]=False
    for e in arr:
        if map[e]==True:
            continue
        else:
            x=e
            map[x]=True
            count=1
            while x-1 in map and map[x-1]==False:
                count+=1
                x-=1
            x=e
            while x+1 in map and map[x+1]==False:
                count+=1
                x+=1
            if length < count:
                length=count
    
    return length;

*/

//method 1 brute force
int findLongestConseqSubseq(int a[], int n)
{
    sort(a,a+n);
    int length=1;
    int count=1;
    for(int i=1;i<n;i++){
        if(a[i-1]+1==a[i]){
            count++;
        }
        else if(a[i-1]==a[i]){
            continue;
        }
        else{
            if(length < count){
                length=count;
            }
            count=1;
        }
    }
    if(length < count){
        length=count;
    }
    return length;
}
#include<unordered_map>
//Method 2 using map in c++
int findLongestConseqSubseq(int a[], int n){
    unordered_map<int,bool> map;
    for(int i=0;i<n;i++){
        if(map.count(a[i]) == 0)
            map[a[i]]=false;
    }
    int length=0;
    for(int i=0;i<n;i++){
        if(map[a[i]]==true){
            continue;
        }
        else{
            int count=1;
            int x=a[i];
            map[x]=true;
            while(map.count(x-1) > 0 && map[x-1]==false){
                count++;
                map[x-1]=true;
                x-=1;
            }
            x=a[i];
            while(map.count((x+1)) > 0 && map[x+1]==false){
            count++;
            map[x+1]=true;
            x+=1;
            }
            
            if(length < count){
                length=count;
                count=1;
            }
        }
    }
    return length;
}

#include<unordered_set>
//method 3 using unordered_set in c++
int findLongestConseqSubseq(int a[], int n)
{
    unordered_set<int> s;
    for(int i=0;i<n;i++){
        s.insert(a[i]);
    }
    int length=0;
    for(int i=0;i<n;i++){
        if(s.find(a[i]-1)==s.end()){
            int j=a[i];
            int count=0;
            while(s.find(j)!=s.end()){
                j++;
                count++;
            }
            if(length < count){
                length=count;
            }
        }
    }
    
    return length;
}

