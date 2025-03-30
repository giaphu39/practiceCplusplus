#include<iostream>
using namespace std;
#define MAX 100
void nhap1(int& m, int& n){
    cin>>m>>n;
}
void nhap2(float a[][MAX],int m, int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
}
void congmang(float a[][MAX],int m, int n,float b[][MAX],int l1, int l2,float c[][MAX]){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            c[i][j]+=a[i][j];
        }
    }
    for(int i=0;i<l1;i++){
        for(int j=0;j<l2;j++){
            c[i][j]+=b[i][j];
        }
    }
}
void xuat(float a[][MAX],int n, int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int m,n;
    int l1,l2;
    float a[MAX][MAX];
    float b[MAX][MAX];
    float c[MAX][MAX];
    nhap1(m,n);
    nhap2(a,m,n);
    nhap1(l1,l2);
    nhap2(b,l1,l2);
    congmang(a,m,n,b,l1,l2,c);
    xuat(c,m,n);
    return 0;
}