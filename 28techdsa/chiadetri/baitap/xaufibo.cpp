#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include<string>

#define int long long
// int n,k;
int fibo[100];
void _try(int n, int k){

    if(n==1){
        cout<<"A";return;
    }
    else if(n==2){
        cout<<'B';return;
    }

    if(k<=fibo[n-2]){
        _try(n-2,k); // đã là char thì đệ quy phải có return
    }
    else{
        _try(n-1,k-fibo[n-2]);
    }
}
int32_t main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,k;
    cin>>n>>k;
    fibo[0]=0; fibo[1]=1;
    for(int i=2;i<=n;i++){
        fibo[i]=fibo[i-1]+fibo[i-2];
    }

    _try(n,k);
    
    return 0;
}
