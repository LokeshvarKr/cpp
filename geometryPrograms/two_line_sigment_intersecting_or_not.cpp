#include<iostream>
#define COUNTER_CLOCK_WISE 1
#define CLOCK_WISE -1
#define LINEAR 0;
using namespace std;
struct point 
{
	float x,y;
};
float max(float x,float y)
{
	return x>y?x:y;
}
float min(float x,float y)
{
	return x<y?x:y;
}
bool on_sigment(point a,point b,point p)
{
	if((p.x <= max(a.x,b.x) && p.x >= min(a.x,b.x) ) && (p.y <= max(a.y,b.y) && p.y >= min(a.y,b.y) ) )
	return true;
	
	return false;
}
float get_cross_product(point a,point b)
{
	return a.x*b.y-a.y*b.x;

}
int get_orientation(point a,point b,point p)
{
	point A,B;
	A.x=b.x-a.x; A.y=b.y-a.y;
	B.x=p.x-b.x; B.y=p.y-b.y;

	float productValue=get_cross_product(A,B);
	
	if(productValue>0)
		return COUNTER_CLOCK_WISE;

	else if(productValue<0)
		return CLOCK_WISE;

	else
		return LINEAR;
	
}
bool is_intersecting(point p1,point q1,point p2,point q2)
{
	int o1=get_orientation(p1,q1,p2);
	int o2=get_orientation(p1,q1,q2);
	int o3=get_orientation(p2,q2,p1);
	int o4=get_orientation(p2,q2,q1);

	if(o1!=o2 && o3!=o4)
	return true;
	
	if(o1==0 && on_sigment(p1,q1,p2) )
	return true;
	if(o2==0 && on_sigment(p1,q1,q2) )
	return true;
	if(o3==0 && on_sigment(p2,q2,p1) )
	return true;
	if(o1==0 && on_sigment(p2,q2,q1) )
	return true;

	return false;
}	
int main()
{
	point p1,q1,p2,q2;
	cout<<"Enter two points for first line sigment"<<endl<<endl;
	cout<<"Co-ordinate of first point of 1st line sigment "<<endl;
	cin>>p1.x>>p1.y;
	cout<<"co-ordinate of second point of 1st line sigment"<<endl;
	cin>>q1.x>>q1.y;
	cout<<"Co-ordinate of first point of 2nd line sigment "<<endl;
	cin>>p2.x>>p2.y;
	cout<<"co-ordinate of second point of 2nd line sigment"<<endl;
	cin>>q2.x>>q2.y;

	bool b=is_intersecting(p1,q1,p2,q2);
	
	if(b)
	cout<<"yes, intersecting"<<endl;
	else
	cout<<"No, not intersecting"<<endl;

	return 0;

}
