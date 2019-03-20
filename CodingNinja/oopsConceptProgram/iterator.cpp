#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
#include<set>
#include<unordered_set>
#include<map>

using namespace std;
int main(){


cout<<"unordered_map----------"<<endl;
unordered_map<string,int> ourmap;
ourmap["abc"]=1;
ourmap["abc1"]=2;
ourmap["abc2"]=3;
ourmap["abc3"]=4;
ourmap["abc4"]=5;

unordered_map<string,int> :: iterator it=ourmap.begin();
while(it!=ourmap.end()){
cout<<it->first<<" "<<it->second<<endl;
it++;
}

vector<int> *v=new vector<int>();
v->push_back(10);
v->push_back(20);
v->push_back(30);
v->push_back(40);
v->push_back(50);

vector<int> ::iterator itt=v->begin();

cout<<"vector----"<<endl;
while(itt!=v->end()){
cout<<*itt<<"  ";
itt++;
}
cout<<endl;

cout<<"ordered map"<<endl;

map<string,int> *mymap=new map<string,int>();
pair<string,int> p1("pqr",10),p2("pqr2",20),p3("pqr3",30),p4("pqr4",40),p5("pqr5",50);
mymap->insert(p1);
mymap->insert(p2);
mymap->insert(p2);
mymap->insert(p3);
mymap->insert(p4);
mymap->insert(p5);

map<string,int> :: iterator it1=mymap->begin();

while(it1!=mymap->end()){
cout<<it1->first<<" "<<it1->second<<endl;
it1++;
}

delete mymap;

cout<<"unordered set"<<endl;

unordered_set<int> *myset=new unordered_set<int>();

myset->insert(100);
myset->insert(200);
myset->insert(300);
myset->insert(400);
myset->insert(500);

unordered_set<int> :: iterator it2=myset->begin();
while(it2!=myset->end()){
cout<<*it2<<" "<<endl;
it2++;
}


return 0;

}

