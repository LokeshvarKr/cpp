#include<iostream>
#include<climits>
using namespace std;

//dynamic programming time o(n^2) space o(n^2)
/*int main()
 {
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n=s.length();
        bool **p=new bool*[n];
        for(int i=0;i<n;i++){
            p[i]=new bool[n];
            p[i][i]=true;
        }
        int max_len=1;
        int start=0;
        for(int l=2;l<=n;l++){
            for(int i=0;i<=n-l;i++){
                int j=i+l-1;
                if(l==2){
                    p[i][j]=(s[i]==s[j]);
                }
                else{
                    p[i][j]=(s[i]==s[j] && p[i+1][j-1]);
                }
                if(p[i][j] && l > max_len){
                    max_len=l;
                    start=i;
                }
            }
        }
        cout<<"palindrome is "<<s.substr(start,max_len)<<endl;
        cout<<"length is "<<max_len<<endl;

        for(int i=0;i<n;i++){
            delete [] p[i];
        }
        delete  [] p;
    }

	return 0;
	
}
*/



// time o(n^2) space o(1)
#include<iostream>
#include<climits>
using namespace std;
int main()
 {
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n=s.length();
        int max_len=1;
        int start=0;
        for(int k=1;k<n;k++){
            int i=k-1;
            int j=k;
            int len=0;
            int st;
            while(i>=0 && j<n && s[i]==s[j]){
                len+=2;
                st=i;
                i--;
                j++;
            }
            if(len > max_len){
                start=st;
                max_len=len;
            }
            
            i=k-1;
            j=k+1;
            len=1;
            st=k;
            while(i>=0 && j<n && s[i]==s[j]){
                st=i;
                len+=2;
                i--;
                j++;
            }
            if(len > max_len){
                start=st;
                max_len=len;
            }
            
        }
        
        cout<<s.substr(start,max_len)<<endl;
    }
	return 0;
	
}