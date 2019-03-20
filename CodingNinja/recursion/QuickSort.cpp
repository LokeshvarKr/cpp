

#include<cstdlib>

int partition(int input[],int p,int r){
  int index1=p+rand()%(r-p+1);
  int index2=p+rand()%(r-p+1);
  int index3=p+rand()%(r-p+1);
  
  int median=0;
  if(index1 <= index2 && index1 >= index3)
    median=index1;
  else if(index2 <= index1 && index2 >= index3)
    median=index3;
  else median=index3;
  
  int temp=input[median];
  input[median]=input[r];
  input[r]=temp;
  
  int i=p-1;
  int j=p;
  while(j<r){
    if(input[j]<input[r]){
      i++;
      int temp=input[i];
      input[i]=input[j];
      input[j]=temp;
    }
    j++;
  }
  
  temp=input[r];
  input[r]=input[i+1];
  input[i+1]=temp;
  
  return i+1;
  
}

void helpQuickSort(int input[],int p,int r){
  if(p<r){
    int q=partition(input,p,r);
    helpQuickSort(input,p,q-1);
    helpQuickSort(input,q+1,r);
  }
}
void quickSort(int input[], int size) {
  
  helpQuickSort(input,0,size-1);

}

