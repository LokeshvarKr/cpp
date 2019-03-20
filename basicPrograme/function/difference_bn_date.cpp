#include<iostream>
using namespace std;
int main()
{
	int d1,m1,y1,d2,m2,y2,d,m,y;
	cout<<"Enter first and second date (first falls before second)"<<endl;
	cout<<"Enter first date"<<endl;
	cin>>d1>>m1>>y1;
	cout<<"Enter second date"<<endl;
	cin>>d2>>m2>>y2;

	int is_leap=0;

	if((y2%100!=0 && y2%4==0) || y2%400==0)
		is_leap=1;
	if(d2<d1)
	{
		if(m2==3)
		{
			if(is_leap)
				d2=d2+29;
			else
				d2=d2+28;
		
		}

		else if(m2==5 || m2==7 || m2==10 || m2==12)
			d2=d2+30;

		else
			d2=d2+31; 

	m2=m2-1;

	}

	if(m2<m1)
	{
		m2=m2+12;
		y2=y2-1;
	}

	d=d2-d1;
	m=m2-m1;
	y=y2-y1;
	
	cout<<"Difference is --- "<<"day---"<<d<<" | month---"<<m<<" | year---"<<y;
	
	return 0;

}
