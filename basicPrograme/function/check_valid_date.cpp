//Assume that date is falls between 1850 and 2050
#include<iostream>
using namespace std;
int main()
{
	int d,m,y;
	cout<<"Enter date "<<endl;
	cin>>d>>m>>y;
	
	int is_leap=0;
	int flag=0;

	if( ( y%4==0 && y%100!=0 ) || y%400==0 )
		is_leap=1;

	if(y<1850 || y>2050 || m<1 || m>12 || d>31 || d<1)
		flag=1;

	if(m==2)
	{
		//if(d==30 || d==31 || (d==29 & !is_leap))
		//	flag=1; 
		if((d>29  && is_leap) || (d>=29 && !is_leap))
			flag=1;

		if((m==4||m==6||m==9||m==11) && d==31)
			flag=1;
			
	}

	if(flag==1)
	cout<<"Invalid date"<<endl;

return 0;
}
