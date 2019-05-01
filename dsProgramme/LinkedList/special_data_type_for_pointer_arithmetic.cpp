
/*
About " uintptr_t " data type :

	uintptr_t was not in C++. It's in C99, in <stdint.h>, as an optional type. Many C++03 compilers do 
	provide that file. It's also in C++11, in <cstdint>, where again it is optional, and which refers to
	C99 for the definition.

	In C99, it is defined as "an unsigned integer type with the property that any valid pointer to void 
	can be converted to this type, then converted back to pointer to void, and the result will compare 
	equal to the original pointer".

	Take this to mean what it says. It doesn't say anything about size.

	uintptr_t might be the same size as a void*. It might be larger.
	It could conceivably be smaller, although such a C++ implementation approaches perverse. 
	For example on some hypothetical platform where void* is 32 bits, but only 24 bits of virtual address space are used, 
	you could have a 24-bit uintptr_t which satisfies the requirement. I don't know why an implementation would do that, 
	but the standard permits it.

*/

#include<stdint.h>
#include<iostream>
using namespace std;
struct  Node {
	int data;
	struct Node * npx;
};
Node * XOR(struct Node *a,struct Node *b){
	return (struct Node *)( (uintptr_t)(a) - (uintptr_t)(b) );
}
int main(){

	Node * head=new Node();

	head->npx=NULL;
	head->data=5;

	cout<<XOR(head,NULL)<<endl;

	return 0;
}