/*


Delete node (recursive)

Given a linked list and a position i, delete the node of ith position from Linked List recursively.
If position i is greater than length of LL, then you should return the same LL without any change.
Indexing starts from 0. You don't need to print the elements, just delete the node and return the head of updated LL.
Input format :

Line 1 : Linked list elements (separated by space and terminated by -1)
Line 2 : Integer i (position)

Output format :

Updated LL elements (separated by space)

Sample Input 1 :

3 4 5 2 6 1 9 -1
3

Sample Output 1 :

3 4 5 6 1 9

Sample Input 2 :

3 4 5 2 6 1 9 -1
0

Sample Output 2 :

4 5 2 6 1 9


Insert node (recursive)


Given a linked list, an integer n and a position i, Insert that node n into Linked List at ith position recursively.
If position i is greater than length of LL, then you should return the same LL without any change. And if position i is equal to length of input LL, insert the node at last position.
Indexing starts from 0. You don't need to print the elements, just insert and return the head of updated LL.
Input format :

Line 1 : Linked list elements (separated by space and terminated by -1)
Line 2 : Integer i (position)
Line 3 : Integer n (Node to be inserted)

Output format :

Updated LL elements (separated by space)

Sample Input 1 :

3 4 5 2 6 1 9 -1
3
100

Sample Output 1 :

3 4 5 100 2 6 1 9

Sample Input 2 :

3 4 5 2 6 1 9 -1
0
20

Sample Output 2 :

20 3 4 5 2 6 1 9


*/
//head is head of linked list,i is the index, data is data of your node
// Following is the node structure
/**************
 class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
 };
***************/

Node* insertNodeRec(Node *head, int i, int data) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
  	if(head ==NULL && i>0)
      return head;
    if(head==NULL && i==0)
    {
      Node *newNode=new Node(data);
      return newNode;
    }
  if(head && i==0)
  {
    Node *newNode=new Node(data);
      newNode->next=head;;
    	return newNode;
  }
  
  head->next=insertNodeRec(head->next,i-1,data);
  return head;
}

Node* deleteNodeRec(Node *head, int i) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
    if(head==NULL)
      return head;
  if(head && i==0)
  {
    Node *temp=head;
    head=head->next;
    delete temp;
    return head;
  }
  head->next=deleteNodeRec(head->next,i-1);
  return head;
}








