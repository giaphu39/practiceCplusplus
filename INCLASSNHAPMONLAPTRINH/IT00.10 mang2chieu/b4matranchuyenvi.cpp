#include<iostream>
using namespace std;
void nhap(int& n){
    cin>>n;
}
void nhap1(double a[100][100],int n, int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
}
void xuat(double a[100][100],int n, int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
void chuyenvi(double a[100][100],int n, int m){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<a[j][i]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int n,m;
    nhap(n);
    nhap(m);
    double a[100][100];
    nhap1(a,n,m);
    chuyenvi(a,n,m);
    // xuat(a,n,m);
    return 0;
}