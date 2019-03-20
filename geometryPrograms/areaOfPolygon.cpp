#include<iostream>
#include<cmath>
using namespace std;
struct point
{
	float x;
	float y;
};
float cross_product(point a,point b)
{
	return (a.x * b.y - a.y * b.x);
}
float area_of_polygon(point vertices[],int n)
{
	float sum=0;
	for(int i=0;i<n;i++)
	sum=sum+cross_product(vertices[i],vertices[(i+1)%n]);
	
	return abs(sum)/2;
}
int main()
{
	int n;
	cout<<"Enter no. of sides of Polygon"<<endl;
	cin>>n;
	point *vertices=new point[n];
	
	cout<<"Enter co-orinates of points"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter x and y co-ordinate"<<endl;
		cin>>vertices[i].x>>vertices[i].y;
	}

	float area=area_of_polygon(vertices,n);
	cout<<"Area of polygon is "<<area<<endl;

return 0;
}
