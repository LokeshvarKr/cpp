#include<iostream>
using namespace std;

// simple using functions only 
/*void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
void max_heapify(int arr[],int n,int i){
	int left=2*i+1;
	int right=2*i+2;
	int maxIndex=i;
	if(left < n && arr[left] > arr[maxIndex]){
		maxIndex=left;
	}
	if(right < n && arr[right] > arr[maxIndex]){
		maxIndex=right;
	}
	if(maxIndex!=i){
		swap(arr+i,arr+maxIndex);
		max_heapify(arr,n,maxIndex);
	}
}
void build_max_heap(int arr[],int n){
	for(int i=n/2;i>=0;i--){
		max_heapify(arr,n,i);
	}
}
void heap_sort(int arr[] ,int n){
	build_max_heap(arr,n);
	int size=n;
	for(int i=0;i<size-1;i++){
		swap(arr+0,arr+(n-1));
		n=n-1;
		max_heapify(arr,n,0);
	}
}
*/

template <typename T>
class  HeapSort{
private:
	T *arr;
	int size;
public:
	HeapSort(T arr[],int size){
		this->arr=arr;
		this->size=size;
	}
private:
	void swap(T *a,T *b){
		T temp=*a;
		*a=*b;
		*b=temp;
	}
	void max_heapify(int n,int i){
		int left=2*i+1;
		int right=2*i+2;
		int maxIndex=i;
		if(left < n && arr[left] > arr[maxIndex]){
			maxIndex=left;
		}
		if(right < n && arr[right] > arr[maxIndex]){
			maxIndex=right;
		}
		if(maxIndex!=i){
			swap(arr+i,arr+maxIndex);
			max_heapify(n,maxIndex);
		}
	}
	void build_max_heap(){
		for(int i=size/2;i>=0;i--){
			max_heapify(size,i);
		}
	}
public:
	void heap_sort(){
		build_max_heap();
		int n=size;
		for(int i=0;i<size-1;i++){
			swap(arr+0,arr+(n-1));
			n=n-1;
			max_heapify(n,0);
		}
	}

};
int main(){
	int n;
	cin>>n;
	double *arr=new double [n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	HeapSort<double> heapsort(arr,n);
	heapsort.heap_sort();
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}