// ma trận đối xứng có các điểm qua đường chéo chính đối xứng, và có tính chất a = at
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
// a[i][j]=a[j][i] còn gặp đường chéo chính thì bỏ qua
bool doixung(double a[][MAXC], int n,int m){
    if(n==0 or m==0 or n!=m or n<0 or m<0) return false; // nhớ kiểm tra các trường hợp đặc biệt
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==j) continue;
            else{
                if(a[i][j]!=a[j][i]) return false;
            }
        }
    }
    return true;
}
string in(double a[][MAXC], int n,int m){
    string ans;
    if(doixung(a,n,m)) ans="Yes";
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
