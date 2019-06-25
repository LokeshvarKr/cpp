#include<iostream>
#include<string>
#include "ourmap.h"
using namespace std;

int main(){

	ourmap<int> map;

	for(int i=0;i<10;i++){
		char ch='0'+i;
		string key="abc";
		key=key+ch;
		map.insert(key,i);
		cout<<"size : "<<map.size()<<endl;
		cout<<"LoadFactor : "<<map.getLoadFactor()<<endl;
	}
	for(int i=0;i<10;i++){
		char ch='0'+i;
		string key="abc";
		key=key+ch;
		cout<<key<<":"<<map.getValue(key)<<endl;
	}
	
	map.remove("abc2");
	map.remove("abc7");
	map.insert("abc1",100);
	for(int i=0;i<10;i++){
		char ch='0'+i;
		string key="abc";
		key=key+ch;
		cout<<key<<":"<<map.getValue(key)<<endl;
	}

return 0;
}
