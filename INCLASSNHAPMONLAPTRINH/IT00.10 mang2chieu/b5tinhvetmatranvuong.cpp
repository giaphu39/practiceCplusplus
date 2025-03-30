
#include <iostream>
using namespace std;
#define MAXR 100
#define MAXC 100

void NhapMaTran(double a[][MAXC], int &n, int& m){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
}

double vet(double a[][MAXC], int n){
    double ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) ans+=a[i][j];
        }
    }
    return ans;
}

int main() {
    double a[MAXR][MAXC];
    int n,m;
    NhapMaTran(a, n,m);
    cout<<vet(a,n);
    return 0;
}
