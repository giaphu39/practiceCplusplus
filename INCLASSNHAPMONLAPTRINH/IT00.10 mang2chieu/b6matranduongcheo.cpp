
#include <iostream>
using namespace std;
#define MAXR 100
#define MAXC 100
#include <string>
void NhapMaTran(double a[][MAXC], int &n, int& m){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
}
// sai trường hợp 0 0 vẫn là true
// trường hợp 0 -0 số âm
bool duongcheo(double a[][MAXC], int n,int m){
    if(n==0 or m==0 ) return true;
    else if(n!=m or n<0 or m<0) return false; 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==j){
                if(a[i][j]==0) return false;
            }
            else{
                if(a[i][j]!=0){ return false;}
            }
        }
    }
    return true;
}
string in(double a[][MAXC], int n,int m){
    string ans;
    if(duongcheo(a,n,m)) ans="Yes";
    else ans="No";
    return ans;
}
int main() {
    double a[MAXR][MAXC];
    int n,m;
    NhapMaTran(a, n,m);
    cout<<in(a,n,m);
    return 0;
}
