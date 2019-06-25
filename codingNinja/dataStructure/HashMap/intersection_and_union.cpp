// input1 - first array
// input2 - second array
// size1 - size of first array
// size2 - size of second array


/*

Code : Print Intersection (and for union see below)

Given two random integer arrays, print their intersection. That is, print all the elements that are present in both the given arrays.
Input arrays can contain duplicate elements.
Note : Order of elements are not important
Input format :
Line 1 : Integer N, Array 1 Size
Line 2 : Array 1 elements (separated by space)
Line 3 : Integer M, Array 2 Size
Line 4 : Array 2 elements (separated by space)
Output format :
Print intersection elements in different lines
Constraints :
1 <= M, N <= 10^6
Sample Input 1 :
6
2 6 8 5 4 3
4
2 3 4 7 
Sample Output 1 :
2 
4 
3
Sample Input 2 :
4
2 6 1 2
5
1 2 3 4 2
Sample Output 2 :
2 
2
1

*/


#include<unordered_map>
void intersection(int input1[], int input2[], int size1, int size2) {
 
   unordered_map<int ,int > intersection;
	 for(int i=0;i<size1;i++){
      intersection[input1[i]]+=1;
     }
  
   for(int i=0;i<size2;i++){
    if(intersection[input2[i]] == 0)
      continue;
      	cout<<input2[i]<<endl;
     	intersection[input2[i]]-=1;
    
     
   }

//UNION  
void UNION(int input1[], int input2[], int size1, int size2) {

   unordered_map<int ,bool> intersection;
  for(int i=0;i<size1;i++){
    if(intersection[input1[i]] == 0)
      cout<<input1[i]<<" ";
  }
  for(int i=0;i<size2;i++){
    if(intersection[input2[i]] ==0)
      cout<<input2[i]<<" ";
  }
  cout<<endl;  
  
}

