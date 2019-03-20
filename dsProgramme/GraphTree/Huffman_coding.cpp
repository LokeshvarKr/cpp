#include<iostream>
#include<string.h>
#define MAX_TREE_HEIGHT 50
using namespace std;

struct FreqNode
{
	char c;
	int f;
};
struct TNode
{
	TNode *left;
	char ch;
	int freq;
	TNode *right;
};
struct MinHeap
{
	int size;
	int capacity;
	TNode **H;
};
void MinHeapify(MinHeap *Queue,int i)
{
	int smallest;
	int l=2*i+1;
	int r=2*i+2;

	if(l < Queue->size && Queue->H[l]->freq < Queue->H[i]->freq)
		smallest=l;
	else
		smallest=i;

	if(r < Queue->size && Queue->H[r]->freq < Queue->H[smallest]->freq)
		smallest=r;

	if(smallest!=i)
	{
		TNode *temp=Queue->H[i];
		Queue->H[i]=Queue->H[smallest];
		Queue->H[smallest]=temp;

		MinHeapify(Queue,smallest);

	}

}
void BuildMinHeap(MinHeap *Queue)
{
	int n=Queue->size;

	for(int i=(n-1)/2;i>=0;i--)
	{
		MinHeapify(Queue,i);

	}
}
TNode* ExtractMinHeap(MinHeap *Queue)
{
	TNode *temp=Queue->H[0];
	
	int n=Queue->size;

	Queue->H[0]=Queue->H[n-1];

	Queue->size=n-1;
	
	MinHeapify(Queue,0);	

	return temp;
}
void InsertMinHeap(MinHeap *Queue,TNode *Ttop)
{
	/*int n=Queue->size;
	n+=1;

	Queue->size=n;

	Queue->H[n-1]=Ttop;

	int i=n-1;
	while(i>0 && Queue->H[i]->freq < Queue->H[(i-1)/2]->freq)
	{
		TNode *temp=Queue->H[i];
		Queue->H[i]=Queue->H[(i-1)/2];
		Queue->H[(i-1)/2]=temp;

		i=(i-1)/2;
	}
	*/


//Another way


	++Queue->size;
	int i=Queue->size-1;

	while(i>0 && Ttop->freq < Queue->H[(i-1)/2]->freq)
	{
		Queue->H[i]=Queue->H[(i-1)/2];
		i=(i-1)/2;
	}
	Queue->H[i]=Ttop; 

}
int   IsPriorityQueueHahOneOnly(MinHeap *Queue)
{
	if(Queue->size==1)
	return 1;
	else return 0;
}
TNode* BuildHuffmanTree(MinHeap *Queue)
{

	
	while(!IsPriorityQueueHahOneOnly(Queue))
	{
		TNode *X=ExtractMinHeap(Queue);
		TNode *Y=ExtractMinHeap(Queue);

		TNode *Ttop=new TNode;

		Ttop->left=X;
		Ttop->right=Y;
		Ttop->ch='$';
		Ttop->freq=X->freq+Y->freq;

		InsertMinHeap(Queue,Ttop);

	}

	return ExtractMinHeap(Queue);
}
void PrintHuffmanCode(TNode *T,int a[],int top)
{
	if(T->left)
	{
		a[top]=0;
		PrintHuffmanCode(T->left,a,top+1);
	}
	if(T->right)
	{	
		a[top]=1;
		PrintHuffmanCode(T->right,a,top+1);
	}
	if(T->left==NULL && T->right==NULL)
	{
		cout<<T->ch<<" ";
		for(int i=0;i<top;i++)
			cout<<a[i];

		cout<<endl;
	}

}
void HuffmanCoding(FreqNode *FN,int n)
{	
	
	MinHeap *Queue= new MinHeap;
	
	Queue->size=n;
	Queue->capacity=n;
	Queue->H=new TNode *[n];

	for(int i=0; i<n;i++)
		Queue->H[i]=new TNode;

	for(int i=0;i<n;i++)
	{
		Queue->H[i]->left=NULL;
		Queue->H[i]->right=NULL;
		Queue->H[i]->ch=FN[i].c;
		Queue->H[i]->freq=FN[i].f;
	}

	BuildMinHeap(Queue);
	
	TNode *T=BuildHuffmanTree(Queue);
	
	int code_array[MAX_TREE_HEIGHT];

	int top=0;	

	PrintHuffmanCode(T,code_array,top);

}
void string_operation()
{
	char s[100];
	cout<<"Enter a string(All character should be small)"<<endl;
	cin>>s;
	int hash1[26];

	for(int i=0;i<26;i++)
		hash1[i]=0;

	for(int i=0;s[i]!='\0';i++)
	{
		int key=s[i]-97;
		hash1[key]+=1;
	}
	 
	int j=0;         
	for(int i=0;i<26;i++)
	{
		if(hash1[i]!=0)
			j++;
	}	
	
	FreqNode *FN=new FreqNode[j];
	
	int k=0;	
	for(int i=0;i<26;i++)
	{
		if(hash1[i]!=0)
		{
		FN[k].c=char(i+97);
		FN[k].f=hash1[i];
		k+=1;
		}	
	}                                     
	
	cout<<"Calculated char-freq pair "<<endl;
	for(int i=0;i<j;i++)
	cout<<FN[i].c<<" "<<FN[i].f<<endl;

	cout<<endl;
	
	cout<<"Huffman Code is"<<endl;
	HuffmanCoding(FN,j);

	delete [] FN;

}
void char_freq_operation()
{
	int n;
	cout<<"Enter how many charector"<<endl;
	cin>>n;

	FreqNode *FN=new FreqNode[n];

	cout<<"Enter character and frequency (character should be small)"<<endl;
	for(int i=0;i<n;i++)
	cin>>FN[i].c>>FN[i].f;

	cout<<"Entered freq-pair is "<<endl;
	for(int i=0;i<n;i++)
	cout<<FN[i].c<<" "<<FN[i].f<<endl;

	cout<<"HuffMan Code is"<<endl;
	HuffmanCoding(FN,n);

	delete [] FN;

}
int main()
{
	int x;
	
	cout<<"Enter 1 'for Entering string and then find the charactor code' "<<endl;
	cout<<"Enter 2 to Enter charector-Frequency pair"<<endl;
		
	cin>>x;
	switch(x)
	{
	case 1:
		string_operation();
		break;
	case 2:
		char_freq_operation();
		break;
	} 

return 0;	 

}
