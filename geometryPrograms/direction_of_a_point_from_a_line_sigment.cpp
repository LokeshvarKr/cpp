#include<iostream>
#define LEFT 1
#define RIGHT -1
#define ON_THE_LINE 0
using namespace std;
struct point
{
	float x;
	float y;
};
point subtract(point p1,point p2)
{
	point result;
	result.x=p1.x-p2.x;
	result.y=p1.y-p2.y;
	
	return result;
}
float cross_product(point p1,point p2)
{
	return (p1.x * p2.y - p1.y * p2.x);
}
int get_direction(point a,point b,point p)
{	
	//translate the vertex a at origin
	b=subtract(b,a);
	p=subtract(p,a);

	float crossProductValue=cross_product(b,p);
	if(crossProductValue>0)
		return LEFT;
	
	else if(crossProductValue<0)
		return RIGHT;
	
	else
		return ON_THE_LINE;

}
int main()
{
	point A,B,P;	
	
	cout<<"Entere two points of a line sigment"<<endl;
	cout<<"Enter co-ordinates of  point A"<<endl;
	cin>>A.x>>A.y;

	cout<<"Enter co-ordinates of point B"<<endl;
	cin>>B.x>>B.y;

	cout<<"Enter a point to which find the direction"<<endl;
	cout<<"Entere co-ordinates "<<endl;
	cin>>P.x>>P.y;
	int direction=get_direction(A,B,P);
	
	if(direction==1)
		cout<<"Point is 'Left' side of line sigment"<<endl;
	else if(direction==-1)
		cout<<"Point is 'Right' side of line sigment"<<endl;
	else
		cout<<"Point is 'On' the line sigment"<<endl;	

return 0;

}

