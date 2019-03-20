#include<iostream>
#include<unordered_map>
#include<string>
#include<utility>
using namespace std;
int main(){
unordered_map<string,int> hashMap;

pair<string,int> p1("abc",1);
//insert
hashMap.insert(p1);
//insert another way
hashMap["def"]=2;

//access or find
cout<<hashMap.at("abc")<<endl;

//another way to access but not good to use as see
cout<<hashMap["def"]<<endl;
cout<<"size : "<<hashMap.size()<<endl;
cout<<hashMap["ghi"]<<endl;

cout<<"size : "<<hashMap.size()<<endl;


//very good way to access
if(hashMap.count("ghi") > 0){
cout<<"ghi is present"<<endl;
}
 
//erase
hashMap.erase("ghi");

if(hashMap.count("ghi") > 0){
cout<<"ghi is present"<<endl;
}

cout<<"size : "<<hashMap.size()<<endl;

return 0;

}





