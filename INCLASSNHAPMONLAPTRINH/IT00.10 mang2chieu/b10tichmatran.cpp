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

void tichmang(float a[][MAX],int m, int n,float b[][MAX],int l1, int l2,float c[][MAX]){
    //từng hàng nhân từng cột tổng lại
    // for(int i=0;i<m;i++){
    //     for(int j=0;j<n;j++){
    //         c[i][j]=0;
    //     }
    // }
    for(int i=0;i<m;i++){
        for(int j=0;j<l2;j++){
            for(int z=0;z<n;z++){
                //trên cùng 1 hàng thì cột đổi (a)
                c[i][j]+=a[i][z]*b[z][j];
                // cout<<c[i][j]<<" ";
            }
            // cout<<endl;
            
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
    tichmang(a,m,n,b,l1,l2,c);
    xuat(c,m,l2);// m*n x l1*l2= m*l2
    return 0;
}