
// min priority Queue

#include<vector>
using namespace std;
class priorityQueue{
	vector<int> pq;

	public:
	
	priorityQueue(){
	
	}
	
	~priorityQueue(){

	}

	bool isEmpty(){
	return pq.size()==0;
	}

	int getSize(){
	return pq.size();
	}

	int getMin(){
	if(isEmpty())
	return -1;
	else return pq[0];
	}

	void insert(int data){
	pq.push_back(data);
	int childIndex=pq.size() - 1;
	
		while(childIndex > 0){
		int parentIndex=(childIndex-1)/2;
			
			if(pq[childIndex] < pq[parentIndex]){
			int temp=pq[childIndex];
			pq[childIndex]=pq[parentIndex];
			pq[parentIndex]=temp;
			}
			else break;
			
		childIndex=parentIndex;
		}

	}

	private:
	void minHeapify(int i){
	int l=2*i+1;
	int r=2*i+2;
	int n=pq.size()-1;
	int minIndex=i;
		if(l<=n && pq[l] < pq[minIndex])
		minIndex=l;

		if(r<=n && pq[r] < pq[minIndex])
		minIndex=r;

		if(minIndex!=i){
		int temp=pq[i];
		pq[i]=pq[minIndex];
		pq[minIndex]=temp;
		
		minHeapify(minIndex);
		}

	}

	public:

	int removeMin(){
	if(isEmpty())
	return -1;

	int min=pq[0];	

	pq[0]=pq[pq.size()-1];
	pq.pop_back();
	
		if(isEmpty())
		return min;
		else { 
		minHeapify(0);
		return min;
		}
	}

	//iterative removeMin()
	 
    int removeMin_iterative() {
        if(isEmpty())
          return 0;
      int ans=pq[0];
      pq[0]=pq[pq.size()-1];
      pq.pop_back();
      
     if(isEmpty())
       return ans;
      
      int parentIndex=0;
      int leftChildIndex=2*parentIndex+1;
      int rightChildIndex=2*parentIndex+2;
      
      while(leftChildIndex < pq.size()){
       	int minIndex=parentIndex;

        if(pq[leftChildIndex] < pq[minIndex])
        minIndex=leftChildIndex;
      
        if(rightChildIndex < pq.size() && pq[rightChildIndex] < pq[minIndex])
        minIndex=rightChildIndex;
      
        if(minIndex!=parentIndex){
        int temp=pq[minIndex];
        pq[minIndex]=pq[parentIndex];
        pq[parentIndex]=temp;
        
        parentIndex=minIndex;
        leftChildIndex=2*parentIndex+1;
        rightChildIndex=2*parentIndex+2;
      	}
      	else 
        	break;
        
     }  
      return ans;
   }
    	

};


