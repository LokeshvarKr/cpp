#include<iostream>
#include<string>
using namespace std;
class Foo{
    public:
    int n;
    int *arr;
    Foo(){
        n=100;
        arr=new int [n];
        for(int i=0;i<n;i++){
            arr[i]=i;
        }
        
        //but look at this
        int Arr[n];
        cout<<"in constructor "<<sizeof(arr)<<endl;
        cout<<"in constructor "<<sizeof(Arr)<<endl;
        cout<<"in constructor "<<sizeof(n)<<endl;
    }
};
int main(){
    string s="kdsf fasj sadjf flkl kds jfk jfl kas asf jlal kff lklk fdsl afas kkf dfs fkds ksfk kjfdsk fksd jdsakf lkl flas fjdsk";
    
    cout<<sizeof(s)<<endl;
    cout<<sizeof(s[40])<<endl;
    cout<<sizeof(string)<<endl;
    cout<<sizeof(Foo)<<endl;
    Foo f;
    cout<<sizeof(f)<<endl;

    return 0;
}