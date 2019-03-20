
#include<iostream>
using namespace std;

class Polynomial {
  public:
  	int *degCoeff;      // Name of your array (Don't change this)
    	int capacity;
  	Polynomial(){
      	degCoeff=new int[5];
      	capacity=5;
    }
  	Polynomial(Polynomial const &p){
      degCoeff=new int[p.capacity];
      for(int i=0;i<p.capacity;i++)
        degCoeff[i]=p.degCoeff[i];
      	capacity=p.capacity;
    }
  	void operator=(Polynomial const &p){
      int *degCoeff=new int[p.capacity];
      for(int i=0;i<p.capacity;i++)
        degCoeff[i]=p.degCoeff[i];
      	capacity=p.capacity;
    }
    void setCoefficient(int deg,int coeff){
      if(deg>=capacity){
        int *degreeCoeff=new int [2*capacity];
        for(int i=0;i<capacity;i++){
          degreeCoeff[i]=degCoeff[i];
        }
        delete [] degCoeff;
        degCoeff=degreeCoeff;
        capacity*=2;
      }
      
      degCoeff[deg]=coeff;
      
    }
    void print() const {
      for(int i=0;i<capacity;i++){
        if(degCoeff[i])
        cout<<degCoeff[i]<<"x"<<i<<" ";
      }
      cout<<endl;
      
    }
  	Polynomial operator+(Polynomial const &p) const {
      int c=(capacity>p.capacity?capacity:p.capacity);
      int *dp=new int [c];
      int i=0;
      while(i<capacity && i<p.capacity){
        dp[i]=degCoeff[i]+p.degCoeff[i];
        i++;
      }
      while(i < capacity){
        dp[i]=degCoeff[i];
      	i++;
      }
      while(i<p.capacity){
        dp[i]=p.degCoeff[i];
        i++;
      }
      Polynomial poly;
      delete [] poly.degCoeff;
      poly.capacity=c;
      poly.degCoeff=dp;
	return poly;
    }
	Polynomial operator-(Polynomial const &p) const {
      int c=capacity>p.capacity?capacity:p.capacity;
      int *dp=new int [c];
      int i=0;
      while(i<capacity && i<p.capacity){
        dp[i]=degCoeff[i] - p.degCoeff[i];
        i++;
      }
      while(i < capacity){
        dp[i]=degCoeff[i];
      	i++;
      }
      while(i<p.capacity){
        dp[i]= (-1)*p.degCoeff[i];
        i++;
      }
      Polynomial poly;
      delete [] poly.degCoeff;
      poly.degCoeff=dp;       
      poly.capacity=c;
	return poly;
    }
  	Polynomial operator*(Polynomial const &p) const {
      int c = capacity+p.capacity - 1;
      int *dp=new int [c];
      int k=0;
      for(int i=0;i<capacity;i++){
        for(int j=0;j<p.capacity;j++){
          k=i+j;
          dp[k] +=degCoeff[i]*p.degCoeff[j];
        }
      }
      Polynomial poly;
      delete [] poly.degCoeff;
      poly.capacity=c;
      poly.degCoeff=dp;
	return poly;
    }
};
// Driver program to test below functions
 
int main()
{
    int count1,count2,choice;
    cin >> count1;
    
    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];
    
    for(int i=0;i < count1; i++) {
        cin >> degree1[i];
    }
    
    for(int i=0;i < count1; i++) {
        cin >> coeff1[i];
    }
    
    Polynomial first;
    for(int i = 0; i < count1; i++){
        first.setCoefficient(degree1[i],coeff1[i]);
    }
    
    cin >> count2;
    
    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];
    
    for(int i=0;i < count2; i++) {
        cin >> degree2[i];
    }
    
    for(int i=0;i < count2; i++) {
        cin >> coeff2[i];
    }
    
    Polynomial second;
    for(int i = 0; i < count2; i++){
        second.setCoefficient(degree2[i],coeff2[i]);
    }
    
    cin >> choice;
    
    Polynomial result;
    switch(choice){
            // Add
        case 1:
            result = first + second;
            result.print();
            break;
            // Subtract
        case 2 :
            result = first - second;
            result.print();
            break;
            // Multiply
        case 3 :
            result = first * second;
            result.print();
            break;
            
        case 4 : // Copy constructor
        {
            Polynomial third(first);
            if(third.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
        case 5 : // Copy assignment operator
        {
            Polynomial fourth(first);
            if(fourth.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
    }
    
    return 0;
}


