
//max priorityQueue uses

#include<iostream>
#include"maxPriorityQueue.h"
using namespace std;
int main(){
priorityQueue pq;

	pq.insert(10);
	pq.insert(100);
	pq.insert(20);
	pq.insert(2);
	pq.insert(35);
	pq.insert(5);
	pq.insert(10);

cout<<"size : "<<pq.getSize()<<endl;

	for(int i=0;i<10;i++){
	cout<<pq.getMax()<<endl;
	cout<<"removed "<<pq.removeMax()<<endl;
	}

return 0;

}





/*
int main() {
    PriorityQueue pq;
    int choice;
    cin >> choice;
    while(choice != -1) {
        switch(choice) {
            case 1 : // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2 : // getMax
                cout << pq.getMax() << endl;
                break;
            case 3 : // removeMax
                cout << pq.removeMax() << endl;
                break;
            case 4 : // size
                cout << pq.getSize() << endl;
                break;
            case 5 : // isEmpty
                if(pq.isEmpty()) {
                    cout << "true" << endl;
                }
                else {
                    cout << "false" << endl;
                }
            default :
                return 0;
        }
        cin >> choice;
    }
return 0;
}

*/
