#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//dùng kĩ thuật mảng cộng dồn

void sol(int pre[], int l, int r){
    if(l==0) cout<<pre[r];
    else cout<< pre[r]-pre[l-1];
    cout<<endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,q;cin>>n>>q;
    int* a=new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int* pre=new int[n];
    pre[0]=a[0];
    for(int i=1;i<n;i++){
        pre[i]=pre[i-1]+a[i];
    }

    for(int i=0;i<q;i++){
        int l,r;cin>>l>>r;
        sol(pre,l,r);
    }
    return 0;
}
