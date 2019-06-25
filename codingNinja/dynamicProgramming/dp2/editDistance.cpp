#include <iostream>
#include <vector>
using namespace std;

int editDistance(string s1, string s2){

 if(s1.size()==0)return s2.length();
  if(s2.size()==0)return s1.length();
  
  else if(s1[0]==s2[0])return editDistance(s1.substr(1),s2.substr(1));
  else{
    //insert
    int x=1+editDistance(s1.substr(1),s2);
    //delete
    int y=1+editDistance(s1,s2.substr(1));
    //update
    int z=1+editDistance(s1.substr(1),s2.substr(1));
    
    return min(min(x,y),z);
  }
}