#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
#include<cmath>
using namespace std;

class Point{
	public:
		int x;
		int y;
};
bool compare_x(Point a,Point b){
	return a.x < b.x;
}
bool compare_y(Point a,Point b){
	return a.y < b.y;
}
double point_distance(Point a,Point b){
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
double bruteForce(Point *p,int n){
	double min_point_distance=INT_MAX;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			min_point_distance=min(min_point_distance,point_distance(p[i],p[j]));
		}
	}

	return min_point_distance;
}
double stripClosest(vector<Point> &strip,double d){
	int n=strip.size();
	double min_point_distance=d;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n && (strip[i].y-strip[j].y < d);j++){
			min_point_distance=min(min_point_distance,point_distance(strip[i],strip[j]));
		}
	}
	return min_point_distance;
}
double closestUtil(Point *px,Point *py,int n){
	if(n<=n){
		return bruteForce(px,n);
	}

	int mid=n/2;
	Point *pyL=new Point[mid];
	Point *pyR=new Point[n-mid];
	int l=0,r=0;
	for(int i=0;i<n;i++){
		if(py[i].x < px[mid].x){
			pyL[l++]=py[i];
		}
		else{
			pyR[r++]=py[i];
		}
	}


	double dl=closestUtil(px,pyL,mid);
	double dr=closestUtil(px+mid,pyR,n-mid);
	double d=max(dl,dr);
	vector <Point> strip;
	for(int i=0;i<n;i++){
		if(abs(py[i].x - px[mid].x) < d){
			strip.push_back(py[i]);
		}
	}

	double result=max(d,stripClosest(strip , d));

	delete [] pyL;
	delete [] pyR;
	strip.clear();
	return result;

}


double closest(Point *p,int n){
	Point *px=new Point[n];
	Point *py=new Point[n];

	for(int i=0;i<n;i++){
		px[i]=p[i];
		py[i]=p[i];
	}

	sort(px,px+n,compare_x);
	sort(py,py+n,compare_y);

	double result=closestUtil(px,py,n);
	delete [] px;
	delete [] py;
	return result;
}
int main(){
	int n;
	cin>>n;
	Point *p=new Point[n];
	for(int i=0;i<n;i++){
		cin>> p[i].x >> p[i].y;
	}
	cout<<"Closest point_distance is "<<closest(p,n)<<endl;
	delete [] p;
}