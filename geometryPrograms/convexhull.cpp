#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Point{
    public:
        int x;
        int y;
        Point(){
            x=0;
            y=0;
        }
};
Point p0;
Point subtract(Point a,Point b){
    Point p;
    p.x=a.x-b.x;
    p.y=a.y-b.y;
    return p;
}
double cross_product(Point a,Point b){
    return a.x * b.y - a.y * b.x;
} 
double orientation(Point a,Point b,Point p){
    Point B=subtract(b,a);
    Point P=subtract(p,a);
    return cross_product(B,P);
}
double dist(Point a,Point b){
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}
bool comp(Point a,Point b){
    return a.x < b.x;
}

// 227 13, 404 585, 677 61, 755 652, 789 179, 933 400
// 379 435, 540 95, 571 796, 757 653, 903 98
bool compare(Point a,Point b){
    double x=orientation(p0,a,b);
    if(x>0){
        return true;
    }
    else if(x==0){
        return (dist(p0,a) <= dist(p0,b)) ? true:false;
    }
    else {
        return false;
    }
}
vector<Point> convexHull(Point *points,int n){
    p0=points[0];
    int min=0;
    for(int i=1;i<n;i++){
        if((points[i].y < p0.y) || (points[i].y==p0.y && points[i].x < p0.x)){
            p0=points[i];
            min=i;
        }
    }
    
    Point temp=points[0];
    points[0]=points[min];
    points[min]=temp;
    
    sort(points+1,points+n,compare);
    
    Point p1=points[1];
    Point p2=points[2];
    vector<Point> result;
    result.push_back(p0);
    result.push_back(p1);
    result.push_back(p2);
    int index=2;
    for(int i=3;i<n;i++){
        p1=result[index-1];
        p2=result[index];
        int x=orientation(p1,p2,points[i]);
        if(x==-1){
            result.pop_back();
            index--;
        }
        result.push_back(points[i]);
        index++;
    }
    
    return result;
}

int main()
 {
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    Point *points=new Point[n];
    for (int i=0;i<n;i++){
        cin>>points[i].x>>points[i].y;
    }

    vector<Point> v=convexHull(points,n);
    sort(v.begin(),v.end(),comp);
    for (Point p:v){
        cout<<p.x<<" "<<p.y<<",";
    }
    cout<<endl;
    }
    return 0;
}