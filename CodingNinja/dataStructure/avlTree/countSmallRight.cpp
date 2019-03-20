/*
Count Smaller elements Submissions: 2461   Accuracy: 55.93%   Difficulty: Easy   Marks: 2
        
Given an array A of positive integers. Count number of smaller elements on right side of each array.

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case is N,N is the size of array. The second line of each test case contains N input arr[i].

Output:
Print the countSmaller array.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 106
1 <= Ai  <= 108

Example:
Input:
2
7
12 1 2 3 0 11 4
5
1 2 3 4 5

Output:
6 1 1 1 0 1 0
0 0 0 0 0

Explanation:
Testcase 1: 6 elements are greater than 1 on its right side in original array. Similarly 1 element is greater than 4 on its right side in original array.
*/
//usiing STL
// set and multiset is implemented as balanced binary search treee (eg. like AVL tree)

/*
#include<iostream>
#include<set>
using namespace std;
void countSmallerElements(int *a,int n){
    multiset<int>s;
    int countAns[n];
    for(int i=n-1;i>=0;i--){
        s.insert(a[i]);
        auto it=s.lower_bound(a[i]);
        countAns[i]=distance(s.begin(),it);
    }
    for(int i=0;i<n;i++){
        cout<<countAns[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int *a=new int[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        countSmallerElements(a,n);
        delete [] a;
    }
	return 0;
}

*/
#include<iostream>
using namespace std;
class AVLTree{
    private:
        class treeNode{
            public:
                int data;
                treeNode *left;
                treeNode *right;
                int height;
                int size;
                /*
                //this is totally worng constructor
                treeNode(int data){
                    data=data;
                    left=NULL;
                    right=NULL;
                    height=1;
                    size=1;
                }*/

                //the right constructor
                treeNode(int data){
                    this->data=data;
                    this->left=NULL;
                    this->right=NULL;
                    this->height=1;
                    this->size=1;
                }

                ~treeNode(){
                	delete left;
                	delete right;
                }
                
        };
        int max(int a,int b){
            return a>b?a:b;
        }
        int size(treeNode* node){
        	if(node==NULL){
        		return 0;
        	}
        	return node->size;
        }
        int height(treeNode* node){
            if(node==NULL){
                return 0;
            }
            return node->height;
        }
        int balanceFactor(treeNode* node){
            if(node==NULL){
                return 0;
            }
            return height(node->left) - height(node->right);
        }
        treeNode* leftRotate(treeNode *c){
            treeNode *b=c->right;
            treeNode *T2=b->left;
            
            b->left=c;
            c->right=T2;

            c->height=max(height(c->left),height(c->right))+1;
            b->height=max(height(b->left),height(b->right))+1;

            c->size=size(c->left)+size(c->right)+1;
            b->size=size(b->left)+size(b->right)+1;
            
            return b;
        }

        treeNode* rightRotate(treeNode *c){
            treeNode *b=c->left;
            treeNode *T2=b->right;
            
            b->right=c;
            c->left=T2;
            
            c->height=max(height(c->left),height(c->right))+1;
            b->height=max(height(b->left),height(b->right))+1;

            c->size=size(c->left)+size(c->right)+1;
            b->size=size(b->left)+size(b->right)+1;
            
            return b;
        }

        treeNode* insert(treeNode *node,int data,int *count){
            if(node==NULL){
              treeNode *newNode=new treeNode(data);
              return newNode;
            }
            if(data < node->data){
                node->left=insert(node->left,data,count);
            }
            else{
                node->right=insert(node->right,data,count);
                *count = *count + size(node->left)+ 1;
            }
            node->height=max(height(node->left),height(node->right))+1;
            node->size=size(node->left) + size(node->right)+1;
            
             int bf=balanceFactor(node);
            //LL
            if(bf > 1 && data < node->left->data){
                return rightRotate(node);
            }
            //RR
            if(bf < -1 && data > node->right->data){
                return leftRotate(node);
            }
            //LR
            if(bf > 1 && data > node->left->data){
                node->left=leftRotate(node->left);
                return rightRotate(node);
            }
            //RL
            if(bf < -1 && data < node->right->data){
                node->right=rightRotate(node->right);
                return leftRotate(node);
            }
            return node;
        }
          
        treeNode *root;
        
    public:
        AVLTree(){
            root=NULL;
        }
        void insert(int data,int *count){
            root=insert(root,data,count);
        }
        
        ~AVLTree(){
            delete root->left;
            delete root->right;
        }
        
};

void countSmaller(int *a,int n){
	AVLTree *tree=new AVLTree();
	int *countAns=new int [n];
    for(int i=0;i<n;i++){
        countAns[i]=0;
    }
	for(int i=n-1;i>=0;i--){
		tree->insert(a[i],&countAns[i]);
	}
	for(int i=0;i<n;i++){
		cout<<countAns[i]<<" ";
	}
	cout<<endl;
	delete [] countAns;
	delete tree;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int *a=new int[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        countSmaller(a,n);
        delete [] a;
    }
	return 0;
}