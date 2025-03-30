
#include <iostream>
using namespace std;

#define MAX 100

void Nhapmang(int a[][MAX], int &n);
void Xuatmang(int a[][MAX], int n);


int b[MAX];


void fibo(int a[],int n){
    a[0]=0;
    a[1]=1;

    for(int i=2;i<=n*2-1;i++){
        a[i]=a[i-1]+a[i-2];    
    }
}

void sol(int a[][MAX],int b[], int n){
    int z=0;
    for(int i=0;i<n;i++){
        z++;
        int u=z;
        for(int j=0;j<n;j++){
            a[i][j]=b[u];
            u++;
        }
    }
}
void Nhapmang(int a[][MAX], int &n){
    cin>>n;
    fibo(b,n);
    sol(a,b,n);
}

void Xuatmang(int a[][MAX], int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
void xuat1(int a[],int n){
    for(int i=0;i<=n*2-1;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
// int main() {
//     int b[MAXR];
//     double a[MAXR][MAXC];
//     int n;
//     nhap(n);
//     fibo(b,n);
//     sol(a,b,n);
//     // xuat1(b,n);
//     xuat(a,n);
//     return 0;
// }

int main()
{
    int n, a[MAX][MAX];
	Nhapmang(a,n);
	Xuatmang(a,n);
	
    return 0;
}