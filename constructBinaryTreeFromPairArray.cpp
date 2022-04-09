// Tree Constructor
// Have the function TreeConstructor(strArr) take the array of strings stored in strArr, 
// which will contain pairs of integers in the following format: (i1,i2), 
// where i1 represents a child node in a tree and the second integer i2 signifies that it is the parent of i1. 
// For example: if strArr is ["(1,2)", "(2,4)", "(7,2)"], then this forms the following tree:
//       4
//      /
//     2
//    /  \
//   1     7
  
// which you can see forms a proper binary tree. Your program should,
// in this case, return the string true because a valid binary tree can be formed.
// If a proper binary tree cannot be formed with the integer pairs, then return the string false.
// All of the integers within the tree will be unique, which means there can only be one node in the tree with the given integer value.
// Examples
// Input: {"(1,2)", "(2,4)", "(5,7)", "(7,2)", "(9,5)"}
// Output: true
// Input: {"(1,2)", "(3,2)", "(2,12)", "(5,2)"}
// Output: false
// Tags: Google Facebook





#include <iostream>
#include <string>
#include<unordered_map>
#include<utility>
#include<vector>
using namespace std;

int convertInt(string s){
  int result=0;
  for(int i=0;i<s.length();i++){
    int x=(int)s[i]-48;
    result=result*10 + x;
  }
  return result;
}

pair<int,int> getPair(string s){
    s=s.substr(1,s.length()-2);
    int x=s.find(',');
    int child=convertInt(s.substr(0,x));
    int parent=convertInt(s.substr(x+1,s.length()-(x+1)));
    pair<int,int> p;
    p.first=child;
    p.second=parent;
    return p;
}
string TreeConstructor(string strArr[], int arrLength) {
  unordered_map<int,vector<int>> parentChildren;
  unordered_map<int,int> childParent;
  for(int i=0;i<arrLength;i++){
    pair<int,int> p=getPair(strArr[i]);
    parentChildren[p.second].push_back(p.first);
    if(parentChildren[p.second].size()>2){
      return "false";
    }
    childParent[p.first]=p.second;
  }

//   cout<<"========print parentChildren map==========="<<endl;
//   unordered_map<int,vector<int>>::iterator it=parentChildren.begin();
//   while(it!=parentChildren.end()){
//     cout<<(*it).first<<": ";
//     for(int i=0;i<(*it).second.size();i++){
//       cout<<(*it).second[i]<<" ";
//     }
//     cout<<endl;
//     it++;
//   }

// cout<<"========print childParent map==========="<<endl;
//    unordered_map<int,int>::iterator itt=childParent.begin();
//   while(itt!=childParent.end()){
//     cout<<(*itt).first<<": "<<(*itt).second<<endl;
//     itt++;
//   }

  //check if only one root is present
  
  int root=0;
  unordered_map<int,vector<int>>::iterator it;
  for(it=parentChildren.begin(); it!=parentChildren.end(); it++){
    int p=(*it).first;
    if(childParent.find(p)==childParent.end()){
      root++;
      if(root>1){
        return"false";
      }
    }
  }
  return "true";
}

int main(void) {    
  // keep this function call here
  string A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  cout << TreeConstructor(A, arrLength);
  return 0;
}
