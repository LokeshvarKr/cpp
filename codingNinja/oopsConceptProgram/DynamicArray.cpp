#include<iostream>
using namespace std;
class DynamicArray{
private:
 int nextIndex;
 int capacity;
 int *data;
public:
 DynamicArray(){
  capacity=1;
  nextIndex=0;
  data=new int [capacity];
 }
 DynamicArray(DynamicArray const &d){
  //this->data=d.data; // shallow copy
 
  data=new int[d.capacity];
  for(int i=0;i<d.nextIndex;i++){
	data[i]=d.data[i];
	}
  capacity=d.capacity;
  nextIndex=d.nextIndex;

 }
  void operator=(DynamicArray const &d){
  //this->data=d.data; // shallow copy
 
  data=new int[d.capacity];
  for(int i=0;i<d.nextIndex;i++){
	data[i]=d.data[i];
	}
  capacity=d.capacity;
  nextIndex=d.nextIndex;

 }
 void addElement(int element){
	if(nextIndex==capacity){
	int *newdata=new int[ 2*capacity];
   	 for(int i=0;i<capacity;i++){
	 newdata[i]=data[i];
   	 }
   	delete [] data;
   	data=newdata;
	capacity*=2;
  	}
	data[nextIndex]=element;
	nextIndex++;
 }

 int getCapacity(){
	return capacity;
 }

 int getElement(int index) const{
	if(index<nextIndex)return data[index];
	else return -1;
 }

 void addElement(int index,int element){
	if(index<nextIndex)
	data[index]=element;
	else if(index==nextIndex)
	addElement(element);
	else return;
 }
 void printAllElements() const {
	for(int i=0;i<nextIndex;i++)
	cout<<data[i]<<" ";
	cout<<endl;
 }

};
int main(){
int i,x,var=0,choice;
DynamicArray arr1;
arr1.addElement(10);
arr1.addElement(20);
arr1.addElement(30);
arr1.addElement(40);
arr1.addElement(50);

arr1.printAllElements();


DynamicArray arr2(arr1); //copy constructor

DynamicArray arr3;

arr3=arr1;   //copy assignment operator

arr1.addElement(0,100);

arr2.printAllElements();

arr3.printAllElements();
arr1.printAllElements();
/*
while(1){
cout<<"Enter 1 to add  Element to next index"<<endl;
cout<<"Enter 2 to addd(or replace) Element at spacific index"<<endl;
cout<<"Enter 3 to get capacity"<<endl;
cout<<"Enter 4 to get element"<<endl;
cout<<"Enter 5 to print all elements of array"<<endl;
cin>>choice;
switch(choice){
case 1:
  cout<<"Enter an element to insert"<<endl;
  cin>>x;
  array.addElement(x);
  break;
case 2:
  cout<<"Enter index and an element(index  where it should insert) respectively"<<endl;
  cin>>i>>x;
  array.addElement(i,x);
  break;
case 3:
  cout<<array.getCapacity()<<endl;
  break;
case 4:
  cout<<"Enter index (which element you want)"<<endl;
  cin>>i;
  cout<<array.getElement(i)<<endl;
  break;
}
}*/


return 0;
}
 
