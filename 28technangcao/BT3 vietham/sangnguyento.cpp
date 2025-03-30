#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// int max(int a, int b){
//     if(a>b){
//         return a;
//     }
//     return b;
// }
void sangnguyento(int l, int r){
    bool arr[r-l+1];
    for(int i=0;i<=r-l+1;i++){
        arr[i]=true;
    }
    for(int i=2;i<=sqrt(r);i++){
        for(int j=max(i*i,(l-i+1)/i*i);j<=r;j+=i){
            arr[j-l]=false;
        }
    }
    for(int i=max(l,2);i<=r;i++){
        if(arr[i-l]){
            cout<<i<<" ";
        }
    }

}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int l,r;
    cin>>l>>r;
    sangnguyento(l,r);
    return 0;
}
