#include<iostream>
using namespace std;
class Fraction
{
	private:
	int numerator;
	int denomenator;
	public:
	Fraction(int numerator,int denomenator){
	this->numerator=numerator;
	this->denomenator=denomenator;
	}


	void setFraction(int numerator,int denomenator){
	this->numerator=numerator;
	this->denomenator=denomenator;
	}

	void print(){
	cout<<numerator<<"/"<<denomenator<<endl;
	}

	void simplify(){
	int hcf=1;
	int minm=numerator<denomenator?numerator:denomenator;
	  for(int i=1;i<=minm;i++){
	  if(numerator%i==0 && denomenator%i==0)
			hcf=i;
	  }
	numerator/=hcf;
	denomenator/=hcf;
	}

	Fraction add(Fraction &f){
	int deno=denomenator*f.denomenator;
	int num=((numerator*f.denomenator)+(f.numerator*denomenator));
	Fraction fnew(num,deno);
	fnew.simplify();
	return fnew;
	}
	
	Fraction multiply(Fraction &f){
	int num=numerator*f.numerator;
	int deno=denomenator*f.denomenator;
	Fraction fnew(num,deno);
	fnew.simplify();
	return fnew;
	}

	Fraction operator+(Fraction &f){
	int deno=denomenator*f.denomenator;
	int num=((numerator*f.denomenator)+(f.numerator*denomenator));
	Fraction fnew(num,deno);
	fnew.simplify();
	return fnew;
	}
	
	Fraction operator*(Fraction &f){
	int num=numerator*f.numerator;
	int deno=denomenator*f.denomenator;
	Fraction fnew(num,deno);
	fnew.simplify();
	return fnew;
	}
	//pre increament ++ operator
	Fraction& operator++(){
	numerator=numerator+denomenator;
	simplify();
	return *this;
	}
	
	//post increament ++ operator
	Fraction operator++(int){
	Fraction fNew(numerator,denomenator);
	numerator=numerator+denomenator;
	simplify();
	fNew.simplify();
	return fNew;
	}
	
	//operator+=()
	Fraction& operator+=(Fraction &f){
	int deno=denomenator*f.denomenator;
	int num=((numerator*f.denomenator)+(f.numerator*denomenator));
	numerator=num;
	denomenator=deno;
	simplify();
	return *this;
	}

};

int main(){
int x,y,choice;
int var=0;
Fraction f1(1,1),f2(1,1),f(1,1);
while(1)
{
cout<<"Enter 1 for add() "<<endl;
cout<<"Enter 2 for operator+()"<<endl;
cout<<"Enter 3 for multiply()"<<endl;
cout<<"Enter 4 for operator*()"<<endl;
cout<<"Enter 5 for operator++() (pre increament)"<<endl;
cout<<"Enter 6 for operator++(int) (post increament"<<endl;
cout<<"Enter 7 for operator+=() "<<endl;
cout<<"Enter 8 Quite"<<endl;
cin>>choice;
switch(choice)
{
case 1://add function
cout<<"Enter f1"<<endl;
cin>>x>>y;
f1.setFraction(x,y);
cout<<"Enter f2"<<endl;
cin>>x>>y;
f2.setFraction(x,y);
f.setFraction(1,1);
f=f1.add(f2);
cout<<"After addition"<<endl;
cout<<"f1 is"<<endl;
f1.print();
cout<<"f2 is"<<endl;
f2.print();
cout<<"f is"<<endl;
f.print();
break;

case 2://f=f1+f2 operator+()
cout<<"Enter f1"<<endl;
cin>>x>>y;
f1.setFraction(x,y);
cout<<"Enter f2"<<endl;
cin>>x>>y;
f2.setFraction(x,y);
f.setFraction(1,1);
f=f1+f2;
cout<<"After addition"<<endl;
cout<<"f1 is"<<endl;
f1.print();
cout<<"f2 is"<<endl;
f2.print();
cout<<"f is"<<endl;
f.print();
break;

case 3://multiply function
cout<<"Enter f1"<<endl;
cin>>x>>y;
f1.setFraction(x,y);
cout<<"Enter f2"<<endl;
cin>>x>>y;
f2.setFraction(x,y);
f.setFraction(1,1);
f=f1.multiply(f2);
cout<<"After multiplication"<<endl;
cout<<"f1 is"<<endl;
f1.print();
cout<<"f2 is"<<endl;
f2.print();
cout<<"f is"<<endl;
f.print();

case 4:// operator*() f=f1*f2;
cout<<"Enter f1"<<endl;
cin>>x>>y;
f1.setFraction(x,y);
cout<<"Enter f2"<<endl;
cin>>x>>y;
f2.setFraction(x,y);
f.setFraction(1,1);
f=f1*f2;
cout<<"After multiplication"<<endl;
cout<<"f1 is"<<endl;
f1.print();
cout<<"f2 is"<<endl;
f2.print();
cout<<"f is"<<endl;
f.print();
break;

case 5://pre increament operator++() 
cout<<"Enter f1"<<endl;
cin>>x>>y;
f1.setFraction(x,y);
f.setFraction(1,1);

++f1;
cout<<"After increamention in f1 as ++f1"<<endl;
cout<<"f1 is"<<endl;
f1.print();

++(++f1); 
cout<<"After increamenting f1 is as  ++(++f1)"<<endl;
cout<<"f1 is"<<endl;
f1.print();

f=++(++f1); 
cout<<"After increamenting f is as  f=++(++f1)"<<endl;
cout<<"f is"<<endl;
f.print();
break;

case 6://post increament opertor++(int)
cout<<"Enter f1"<<endl;
cin>>x>>y;
f1.setFraction(x,y);
f.setFraction(1,1);

f1++;
cout<<"after f1++,f1 is"<<endl;
f1.print();

f=f1++;
cout<<"after f=f1++ f and f1 is"<<endl;
f.print();
f1.print();
break;

case 7:
cout<<"Enter f1"<<endl;
cin>>x>>y;
f1.setFraction(x,y);
cout<<"Enter f2"<<endl;
cin>>x>>y;
f2.setFraction(x,y);

f1+=f2;
cout<<"after f1+=f2 f1 and f2 is"<<endl;
f1.print();
f2.print();

(f1+=f2)+=f2;
cout<<"after (f1+=f2)+=f2 f1 and f2 is"<<endl;
f1.print();
f2.print();
break;

case 8:
var=1;
break;
 
default:
var=1;
break;
}
if(var==1)
break;
}
return 0;
}
