#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;




int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    int n;cin>>n;
    int* a=new int[n+1];
    int q;cin>>q;
    for(int i=0;i<n;i++) cin>>a[i];

    int* d=new int[n+1];
    d[0]=a[0];
    for(int i=1;i<n;i++){
        d[i]=a[i]-a[i-1];
    }

    while(q--){
        int l,r,k;cin>>l>>r>>k;
        d[l]+=k;
        d[r+1]-=k; // do cái này nên phải khai báo n+1
        
    }

    for(int i=0;i<n;i++){
        if(!i) a[i]=d[i];
        else a[i]=a[i-1]+d[i];
        cout<<a[i]<<" ";
    }
    
    delete[] a;
    delete[] d;
    return 0;
}
