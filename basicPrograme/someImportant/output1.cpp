#include<iostream>
#include<iomanip>
using namespace std;
      
int main()
{
    if(sizeof(int) > -1){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
    cout<<endl;
    
    //see this output for explanation
    cout<<sizeof(int)<<endl;
    unsigned x=unsigned(-1);
    cout<<x<<endl;
    return 0;
} 
//Reason
//In C++, when an integer value is compared with an unsigned it, the int is promoted 
//to unsigned. Negative numbers are stored in 2’s complement form and unsigned value
//of the 2’s complement form is much higher than the sizeof int.